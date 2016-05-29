
#ifndef IMAGEPROVIDER_HPP
#define IMAGEPROVIDER_HPP

#include <iostream>
#include <vector>


class ImageProvider {
public:
    ImageProvider();
    virtual ~ImageProvider();
    
    virtual int GatherImages(std::vector<std::string>& imagePaths) = 0;
};

#endif /* IMAGEPROVIDER_HPP */
