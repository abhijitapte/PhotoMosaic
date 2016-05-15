# PhotoMosaic

## Purpose
Given a source image as input, create a photo made from a tile of images.

## Details
The problem has been neatly described in https://chara.cs.illinois.edu/cs225/mps/6/ module.
The solution employs Nearest Neighbor Search algorithm that inturn uses k-d tree (k-dimensional tree).

An image provider helper class has been added that takes care of the tiling needs i.e., fetching images from a source and then using them as tiles to stitch out the mosaic that nearly resembles the input/source image.
