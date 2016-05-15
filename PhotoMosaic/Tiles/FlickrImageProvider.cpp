//
//  Flickr.cpp
//  KDTree
//
//  Created by Abhijit Apte on 14/05/16.
//  Copyright © 2016 Abhijit Apte. All rights reserved.
//

#include "FlickrImageProvider.hpp"


namespace Tiles {
    
    FlickrImageProvider::FlickrImageProvider(
                                             const std::string& apiKey,
                                             const std::string& apiSecret,
                                             const std::string& searchString)
    
    : mFlickCurl(nullptr)
    , mAPIKey(apiKey)
    , mAPISecret(apiSecret)
    , mSearchString(searchString)
    {
        flickcurl_init();
        mFlickCurl = flickcurl_new();
        if (mFlickCurl)
        {
            flickcurl_set_api_key(mFlickCurl, mAPIKey.c_str());
            flickcurl_set_shared_secret(mFlickCurl, mAPISecret.c_str());
        }
    }
    
    FlickrImageProvider::~FlickrImageProvider()
    {
        flickcurl_free(mFlickCurl);
        flickcurl_finish();
    }
    
    /*virtual*/
    int FlickrImageProvider::GatherImages(std::vector<std::string>& imagePaths)
    {
        flickcurl_search_params params;
        flickcurl_search_params_init(&params);
        char* searchString = (char*)malloc(mSearchString.length() + 1);
        strcpy(searchString, mSearchString.c_str());
        params.text = searchString;
        
        int numPicsToQuery = 10;
        int MAX_RESULTS_PER_PAGE = 2;
        
        // This is needed on each iteration
        flickcurl_photo **ret_photos = NULL;
        
        // Calculate the number of queries we'll need.  Be careful of incomplete
        // queries
        int currPicsToQuery = numPicsToQuery;
        int numQueries = numPicsToQuery / MAX_RESULTS_PER_PAGE
        + ((numPicsToQuery % MAX_RESULTS_PER_PAGE == 0) ? 0 : 1);
        
        for (int queryNum = 0; queryNum < numQueries; queryNum++) {
            // Iteration variables
            int currPerPage = currPicsToQuery < MAX_RESULTS_PER_PAGE ?
            currPicsToQuery : MAX_RESULTS_PER_PAGE;
            params.per_page = currPerPage;
            params.page = queryNum +1;
            currPicsToQuery -= currPerPage;
            
            // Make the query
            ret_photos = flickcurl_photos_search(mFlickCurl, &params);
            if (ret_photos == NULL)
                // The query failed
                return -1;
            
            int picNum = 0;
            char* curUrl = NULL;
            while(ret_photos[picNum] != NULL) {
                curUrl = flickcurl_photo_as_source_uri(ret_photos[picNum], 's');
                if (curUrl == NULL) { // Error!
                    flickcurl_free_photos(ret_photos);
                    return -1;
                }
                
                imagePaths.push_back(std::string(curUrl));
                free(curUrl);
                
                picNum++;
            }
            
            flickcurl_free_photos(ret_photos);
            
            if (picNum < currPerPage) {
                // We received less photos than we wanted.  Not necessarily
                // an error, but break out of the loop
                break;
            }
        }
        
        free(searchString);
        
        return true;
    }
    
}
