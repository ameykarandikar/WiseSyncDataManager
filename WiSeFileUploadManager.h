//
//  FileUploadManager.h
//  WiseSyncDataManager
//
//  Created by Elbin on 16/02/18.
//  Copyright © 2018 Elbin John. All rights reserved.
//

/*!
 @header WiSeFileUploadManager.h
 
 @brief This class can be used for uploading image file to server.
 
 @author WiSilica
 @copyright  2018 WiSilica
 */

#import <Foundation/Foundation.h>
#import <WiSeCloudAPISDK/WiSeCloudSDKInitializer.h>
#import <WiSeCloudAPISDK/WiSeCloudAPIURLInfo.h>
#import <WiSeDataModelsManager/WiSeDataModelsManager.h>


@interface WiSeFileUploadManager : NSObject

+ (instancetype)sharedInstance;

/**
 Start Uploading image file to server using below method
 
 @param imageDetails  Type : WiSeImageItem - contains details about image
 @param user - Current logged user details
 
 */

- (void)startUploadRequest :(WiSeImageItem *)imageDetails
                      user :(WiSeCurrentLoggedINUser *) user
              SuccessBlock :(void (^)( id responseObject))success
             ProgressBlock :(void (^)( NSUInteger bytesWritten,long long totalBytesWritten, long long totalBytesExpectedToWrite))progress
              FailureBlock :(void (^)( NSString *errorDescription))failure;

@end
