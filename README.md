# truth-and-crop-opencv

An application for quickly ground-truthing semantic segmentation datasets in Python/OpenCV.

### Dependencies

+ `python 3.4.5`
+ `opencv 3.0.0`
+ `numpy 1.11.2`
+ `argparse 1.1`
+ `colorama 0.3.7`
+ `matplotlib 1.5.3`
+ `scikit-image 0.12.3`

### Usage

```bash
usage: truth_and_crop.py [-h] [--wnd WND] [--ds DS] [--nseg NSEG]
                         [--sigma SIGMA]
                         img_path img_name out_path

positional arguments:
  img_path       path to image to be ground-truthed
  img_name       name of image to be ground-truthed
  out_path       root path to save resulting cropped image/mask pairs

optional arguments:
  -h, --help     show this help message and exit
  --wnd WND      square crop size / 2 in pixels
  --ds DS        image down-sampling factor
  --nseg NSEG    number of superpixel segments for SLIC
  --sigma SIGMA  gaussian smoothing parameter for SLIC
```

Example:

```bash
python truth_and_crop.py ~/input_folder/ IMG_6108.JPG ~/output_folder/ --wnd 150 --ds 4 --nseg 200
```

### Commands

+ `m - Toggle mode between ground-truthing and cropping.`
+ `w - Write cropped image-mask pairs to IMAGES_OUT_DIR and MASKS_OUT_DIR respectively.`
+ `q - Quit, note does not automatically save.`
+ `0 - Select class 0.`
+ `1 - Select class 1.. so fourth`
