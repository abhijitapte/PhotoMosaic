//
//  Flickr.hpp
//  KDTree
//
//  Created by Abhijit Apte on 14/05/16.
//  Copyright © 2016 Abhijit Apte. All rights reserved.
//

#ifndef FLICKR_IMAGEPROVIDER_HPP
#define FLICKR_IMAGEPROVIDER_HPP

#include "ImageProvider.hpp"
#include "flickcurl/include/flickcurl.h"

namespace Tiles {
    
    /*
     * Flickr instance orchestrates the downloads images from flickr which
     * are used as tiles that eventually are laid out as tiles in the photo
     * selected by the user
     *
     */
    class FlickrImageProvider : public ImageProvider {
        
    public:
        
        FlickrImageProvider(
                            const std::string& apiKey,
                            const std::string& apiSecret,
                            const std::string& searchString);
        
        ~FlickrImageProvider();
        
        virtual int GatherImages(std::vector<std::string>& imagePaths);
        
    private:
        
        flickcurl*  mFlickCurl;
        std::string mAPIKey;
        std::string mAPISecret;
        std::string mSearchString;
        
    };
}

#endif /* FLICKR_IMAGEPROVIDER_HPP */
