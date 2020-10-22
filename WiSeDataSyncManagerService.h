//
//  WiSeSyncManager.h
//  CloudDataManager
//
//  Created by Elbin John on 01/02/17.
//  Copyright © 2017 Elbin John. All rights reserved.
//

/*!
 @header WiSeDataSyncManagerService.h
 
 @brief This class can be used for initialising all api services.
 
 @author WiSilica
 @copyright  2018 WiSilica
 */

#import "WiSeSyncBaseManager.h"
@interface WiSeDataSyncManagerService : WiSeSyncBaseManager

@property (nonatomic,strong) WiSe_FileDownloadManager          * downloadManager;

+ (instancetype)sharedInstance;

/**
 To initialise api manager services.
 */
- (void)initilizeServices;

@end

