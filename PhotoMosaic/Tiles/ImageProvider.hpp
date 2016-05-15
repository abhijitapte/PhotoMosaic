//
//  ImageProvider.hpp
//  KDTree
//
//  Created by Abhijit Apte on 15/05/16.
//  Copyright © 2016 Abhijit Apte. All rights reserved.
//

#ifndef IMAGEPROVIDER_HPP
#define IMAGEPROVIDER_HPP

#include <iostream>
#include <vector>

namespace Tiles {
    
    class ImageProvider {
    public:
        ImageProvider();
        virtual ~ImageProvider();
        
        virtual int GatherImages(std::vector<std::string>& imagePaths) = 0;
    };
    
}

#endif /* IMAGEPROVIDER_HPP */
