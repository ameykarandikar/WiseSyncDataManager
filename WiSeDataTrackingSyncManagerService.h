//
//  WiSeDataTrackingSyncManagerService.h
//  CloudDataManager
//
//  Created by Elbin John on 21/03/17.
//  Copyright © 2017 Elbin John. All rights reserved.
//

/*!
 @header WiSeDataTrackingSyncManagerService.h
 
 @author WiSilica
 @copyright  2018 WiSilica
 */
#import <Foundation/Foundation.h>
#import "WiSeDataSyncManagerService.h"

@interface WiSeDataTrackingSyncManagerService : WiSeDataSyncManagerService

+ (instancetype)sharedInstance;

//- (void)initProcessUploadAndDownload;


@end
