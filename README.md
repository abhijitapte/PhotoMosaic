# PhotoMosaic

## Purpose
Given a source image as input, create a photo made from a tile of images.

## Details
The problem has been neatly described in https://chara.cs.illinois.edu/cs225/mps/6/ module.
The solution employs Nearest Neighbor Search algorithm that inturn uses k-d tree (k-dimensional tree).

An image provider helper class has been added that takes care of the tiling needs i.e., fetching images from a source and then using them as tiles to stitch out the mosaic that nearly resembles the input/source image. The image provider class is an interface and as a design principle, it is better to code to the interface rather than to the implementation (recall from 'Head First Design Patterns').

Flickr provides a library called `FlickrCurl` [https://www.flickr.com/services/api/] that abstracts fetching, querying images. But inorder to use these services, one needs an API key and an API secret. This can be applied via https://www.flickr.com/services/apps/create/apply/? 

The application expects three command line arguments to be supplied:
1) API key (obtained from Flickr)
2) API secret (obtained from Flickr)
3) Search string

## Steps

Note: The ones that have been completed have been striked out.

1) Fetch the source image (capture new or supply existing image)
~~2) Query for images from image provider~~
3) Download the images from image provider
4) Find nearest neighbor for each unit in source image and replace it with the nearest neighbor found.
5) Stich the photo back and write the image back to disk.



