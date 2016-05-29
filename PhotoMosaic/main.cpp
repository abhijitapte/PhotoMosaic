
#include <iostream>
#include "Tiles/FlickrImageProvider.hpp"

int main(int argc, const char * argv[]) {
    
    if (argc != 4)
    {
        return -1;
    }
    
    std::string apiKey = argv[1];
    std::string apiSecret = argv[2];
    std::string searchString = argv[3];
    
    std::shared_ptr<ImageProvider> imageProvider = std::make_shared<FlickrImageProvider>(apiKey, apiSecret, searchString);
    
    std::vector<std::string> imagePaths;
    imageProvider->GatherImages(imagePaths);
    
    return 0;
}
