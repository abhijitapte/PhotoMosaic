//
//  main.cpp
//  KDTree
//
//  Created by Abhijit Apte on 14/05/16.
//  Copyright © 2016 Abhijit Apte. All rights reserved.
//

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
    
    Tiles::FlickrImageProvider flickrImageProvider(
                                    apiKey,
                                    apiSecret,
                                    searchString);
    
    std::vector<std::string> imagePaths;
    flickrImageProvider.GatherImages(imagePaths);
    
    return 0;
}
