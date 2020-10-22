//
//  SyncBaseManager.h
//  CloudDataManager
//
//  Created by Elbin John on 01/02/17.
//  Copyright © 2017 Elbin John. All rights reserved.
//

/*!
 @header WiSeSyncBaseManager.h
 
 @brief This class is used for syncing all entities with server.
 
 @author WiSilica
 @copyright  2018 WiSilica
 */

#import <Foundation/Foundation.h>
#import <WiSeDataModelsManager/WiSeDataModelsManager.h>
#import <WiSeDataBaseManager/WiSeDataBaseManager.h>
#import <WiSeDataModelsManager/WiSeDataModelsManager.h>
#import <CloudDataManager/CloudDataManager.h>
#import <WiSeDataBaseManager/WiSeDataBaseManager.h>
#import <WiSeDataModelsManager/WiSeDataModelsManager.h>
#import <WiSeConnectSDK/WiSeBLEConnectSDK.h>

extern NSString * const  WiSeServerSyncDatabaseUpdated;
extern NSString * const  WiSeMapDownloadCompleted;
extern NSString * const  WiSeServerSyncCompleted;

typedef enum {

    WiSeSyncItemProcessStatusExecuting,
    WiSeSyncItemProcessStatusCompleted,
    WiSeSyncItemProcessStatusRegistered

}WiSeSyncItemProcessStatus;


typedef enum
{
    APPScheduleCategoryAll  = -1,

}APPScheduleCategory;

typedef enum : NSUInteger {
    PlatformSync,
    TrackingSync,
    TargusSync,
    SyncAll
} SyncModule;
 


@interface WiSeSyncItemsList : NSObject

@property(nonatomic,assign)int parrentProcessID;
@property(nonatomic,assign)int processID;
@property(nonatomic,assign)int processOrderID;
@property(nonatomic,assign)int priorityOrder;
@property(nonatomic,assign)int processType;
@property(nonatomic,assign)WiSeSyncItemProcessStatus processStatus;
@property(nonatomic,strong)NSString * processName;
@property(nonatomic,strong)NSString * apiId;

@property(nonatomic,assign)int totalCount;
@property(nonatomic,assign)int currentItem;

@end

@interface WiSeSyncBaseManager : NSObject

@property(nonatomic,assign)SyncModule syncModule;

@property (atomic,strong) NSArray * syncTemplates;
/**
 To ends a syncing process task

 @param prcessName - Name of the process you want to stop syncing.
 
 */
- (void)prcessEnd:(NSString*)prcessName  syncCount :(int)syncCount;

/**
 To update maximum timestamp.
 
 @param syncTypeId - type Id for task.
 
 @param maxTimestamp - maximum Tiestamp value read from server.
 
 */
- (void)updateSyncForTypeId:(int)syncTypeId maxTimestamp:(NSTimeInterval )maxTimestamp;

/**
 To get timestamp.
 
@param syncTypeId - type Id for task.
 
 */
- (double)getSyncTimeForTypeId:(int)syncTypeId;

/**
 To upadate the pending items to get sync with server.
 
 */
- (void)updatePendingList;

/**
 To start  syncing process to and from server
 
 */
- (void)prcessStart;


/**
 To start upload and download task from and to server.
 
 */
- (void)initProcessUploadAndDownload;

/**
 To start upload task to server.
 
 */
- (void)initProcessUploadOnly;


/**
 To mark one process sync completed.

 @param prcessName - Name of the process you want to stop syncing.
 @param syncCount -  number of sync.
 */
- (void)postNotificationProcessName:(NSString*)prcessName onCount:(int)syncCount;

/**
 To get the syc process status
 
 
 */
- (NSArray*)getSyncProcessStatus;

/**
 To ends up all sync process with server
 
 */
- (void)closeAllSyncOperations;

/**
 Update sync time for all archive apis with current user login time

 @param loginTime Current user login time
 */
- (void) updateSyncTimeForArchiveAPIsAfterLogin : (NSTimeInterval) loginTime;


@end
