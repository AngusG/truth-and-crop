import argparse
import numpy as np
import matplotlib.pyplot as plt

from scipy import ndimage

X_LOW = 80
X_UPP = 120

Y_LOW = X_LOW
Y_UPP = X_UPP

MAX_VALID_CLASS = 5


if __name__ == '__main__':

    parser = argparse.ArgumentParser()
    parser.add_argument('mask', help='path to integer mask to clean')
    parser.add_argument(
        '--zoom', help="zoom into area bounded by X_LOW, X_UPP, Y_LOW, Y_UPP", action="store_true")
    args = parser.parse_args()

    orig_mask = plt.imread(args.mask)
    max_px = orig_mask.max()
    min_px = orig_mask.min()

    # valid classes are 0 through 5
    valid_classes = []
    hist, bin_edges = np.histogram(
        orig_mask, bins=MAX_VALID_CLASS + 1, range=(0, MAX_VALID_CLASS + 1))
    class_area_pct = np.zeros(len(hist))

    for i in range(len(hist)):
        class_area_pct[i] = 100 * float(hist[i] / np.sum(hist))
        # 1.0% is an arbitrary choice here that seemed to work well
        if class_area_pct[i] > 1.0:
            print('class %d is %.2f%% by volume' % (i, class_area_pct[i]))
            valid_classes.append(i)

    clean_mask = orig_mask.copy()
    valid_class_arr = np.asarray(valid_classes)
    print(valid_class_arr)
    for i in range(len(hist)):
        if i not in valid_classes:
            # assign the closest valid class label
            new_class_label = valid_class_arr[
                np.argmin(np.abs(valid_class_arr - i))]
            print('Replacing instances of class %d (area %.2f%%) with valid class %d (area %.2f%%)' % (
                i, class_area_pct[i], new_class_label, class_area_pct[new_class_label]))
            clean_mask[orig_mask == i] = new_class_label

        out_of_range_pct = 100 * \
            float(
                np.sum(clean_mask[orig_mask > MAX_VALID_CLASS]) / np.sum(hist))
    print('Replacing out of range classes (area %.2f%%) with top valid class %d (area %.2f%%)' % (
        out_of_range_pct, MAX_VALID_CLASS, class_area_pct[MAX_VALID_CLASS]))
    clean_mask[orig_mask > MAX_VALID_CLASS] = MAX_VALID_CLASS

    plt.close('all')

    plt.figure()
    if args.zoom:
        plt.imshow(orig_mask[X_LOW:X_UPP, Y_LOW:Y_UPP],
                   vmin=min_px, vmax=max_px)
    else:
        plt.imshow(orig_mask, vmin=min_px, vmax=max_px)
    plt.title('original mask')

    plt.figure()
    if args.zoom:
        plt.imshow(clean_mask[X_LOW:X_UPP, Y_LOW:Y_UPP],
                   vmin=min_px, vmax=max_px)
    else:
        plt.imshow(clean_mask, vmin=min_px, vmax=max_px)
    plt.title('histogram cleaned mask')

    ### Now median filter the histogram cleaned image ###
    median_filter_size = 5 # Hyperparameter
    clean_mask = ndimage.median_filter(clean_mask, size=median_filter_size)

    plt.figure()
    if args.zoom:
        plt.imshow(clean_mask[X_LOW:X_UPP,
                              Y_LOW:Y_UPP], vmin=min_px, vmax=max_px)
    else:
        plt.imshow(clean_mask, vmin=min_px, vmax=max_px)
    plt.title('median filter mask (%dx%d)' %
              (median_filter_size, median_filter_size))

    morphology_size = 3 # Hyperparameter
    clean_mask = ndimage.grey_dilation(
        clean_mask, size=(morphology_size, morphology_size))

    plt.figure()
    if args.zoom:
        plt.imshow(clean_mask[X_LOW:X_UPP,
                              Y_LOW:Y_UPP], vmin=min_px, vmax=max_px)
    else:
        plt.imshow(clean_mask, vmin=min_px, vmax=max_px)
    plt.title('morphology (%dx%d)' % (morphology_size, morphology_size))
    plt.show()
