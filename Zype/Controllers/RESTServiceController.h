//
//  RESTServiceController.h
//  Zype
//
//  Created by ZypeTech on 1/28/15.
//  Copyright (c) 2015 Zype. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Video.h"
#import "EpisodeController.h"

@class PlaybackSource;

@interface RESTServiceController : NSObject <NSURLSessionDelegate>

- (void)getTokenWithUsername:(NSString *)username WithPassword:(NSString *)password WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)registerWithUsername:(NSString *)username WithPassword:(NSString *)password WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)resetPasswordWithUsername:(NSString *)username WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)saveConsumerIdWithToken:(NSString *)accessToken WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getTokenInfo:(NSString *)accessToken WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getConsumerInformationWithID:(NSString *)consumerId withCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completion;
- (void)refreshAccessTokenWithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

- (void)syncZObject;

- (void)syncVideosInPage:(NSNumber *)page WithVideosInDB:(NSMutableArray *)videosInDB WithExistingVideos:(NSMutableArray *)existingVideos completionDelegate: (EpisodeController*) delegate;
- (void)syncVideosFromDate:(NSDate *)fromDate ToDate:(NSDate *)toDate InPage:(NSNumber *)page WithVideosInDB:(NSArray *)videosInDBFiltered WithExistingVideos:(NSArray *)existingVideos;
- (void)syncHighlightsInPage:(NSNumber *)page WithVideosInDB:(NSMutableArray *)highlightsInDB WithExistingVideos:(NSMutableArray *)existingVideos;
- (void)syncVideosFromPlaylist:(NSString *)playlistId InPage:(NSNumber *)page WithVideosInDB:(NSArray *)videosInDBFiltered WithExistingVideos:(NSArray *)existingVideos completionDelegate: (EpisodeController*) delegate;
- (void)syncVideosFromPlaylist:(NSString *)playlistId InPage:(NSNumber *)page WithVideosInDB:(NSArray *)videosInDBFiltered WithExistingVideos:(NSArray *)existingVideos completionDelegate: (EpisodeController*)delegate withCompletionHandler:(void (^)(void))complete;
- (void)loadVideoWithId:(NSString *)videoId withCompletionHandler:(void(^)(NSData *data, NSError *error))success;

- (void)getDownloadVideoUrlWithVideoId:(NSString *)vId WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getDownloadAudioUrlWithVideoId:(NSString *)vId WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

- (void)getVideoPlayerWithVideo:(Video *)video downloadInfo:(BOOL)isDownloaded withCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getAudioPlayerWithVideo:(Video *)video WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getAudioSourceWithVideo:(Video *)video withCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

- (void)syncPlaylistWithId:(NSString *)playlistId withCompletionHandler:(void (^)(NSString *))errorString;
- (void)syncPlaylistsWithParentId:(NSString *)parentId completionDelegate:(EpisodeController*)delegate withCompletionHandler:(void (^)(void))complete;

- (PlaybackSource *)videoStreamPlaybackSourceFromRootDictionary:(NSDictionary *)dictionary;
- (PlaybackSource *)audioStreamPlaybackSourceFromRootDictionary:(NSDictionary *)dictionary;
- (NSArray *)streamPlaybackSourcesFromRootDictionary:(NSDictionary *)dictionary;
- (NSArray *)allPlaybackSourcesFromRootDictionary:(NSDictionary *)dictionary;

- (NSString *)videoPlayerUrlFromJSON:(NSDictionary *)parsedObject;
- (NSString *)videoPlayerNameFromJSON:(NSDictionary *)parsedObject;
- (NSString *)videoDownloadUrlFromJSON:(NSDictionary *)parsedObject;
- (NSString *)audioStreamUrlFromJSON:(NSDictionary *)parsedObject;
- (NSString *)audioDownloadUrlFromJSON:(NSDictionary *)parsedObject;
- (NSString *)audioStreamCaptureUrlFromJSON:(NSDictionary *)parsedObject;
- (NSString *)youTubeIdFromVideo:(id)data;

- (void)loadGuests:(NSString *)videoId InPage:(NSNumber *)page;

- (void)syncFavoritesAfterRefreshed:(BOOL)isRefreshed InPage:(NSNumber *)page WithFavoritesInDB:(NSMutableArray *)favoritesInDB WithExistingFavorites:(NSMutableArray *)existingFavorites;
- (void)syncLibraryAfterRefreshed:(BOOL)isRefreshed InPage:(NSNumber *)page WithLibraryInDB:(NSMutableArray *)libraryInDB WithExistingLibrary:(NSMutableArray *)existingLibrary;
- (void)loadVideoInFavoritesWithId:(NSString *)videoId;
- (void)loadVideoInLibraryWithId:(NSString *)videoId;
- (void)favoriteVideo:(Video *)video;
- (void)unfavoriteVideo:(Video *)video;

- (void)searchVideos:(NSString *)searchString InPage:(NSNumber *)page;

- (void)syncAppSetting;
- (void)syncAppContent;

- (void)checkLiveStreamWithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getLiveStreamWithId:(NSString *)vId WithCompletionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getLiveStreamAudioWithId:(NSString *)vId WithCompletionHandler:(void (^)(NSData *, NSURLResponse *, NSError *, NSString *))completionHandler;


- (void)syncNotificationsInPage:(NSNumber *)page WithNotificationsInDB:(NSMutableArray *)notificationsInDB WithExistingNotifications:(NSMutableArray *)existingNotifications;

- (void)syncSubscriptionPlan;
- (void)getSubscriptionPlan:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completion;
- (void)createMarketplace:(NSData*)receipt planId:(NSString*)planId completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completion;

// EPG
- (void)getGuides:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (void)getGuidePrograms:(NSString*)channelId sort:(NSString*)sort order:(NSString*)order greaterThan:(NSString*)gte lessThan:(NSString*)lte completion:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

//Singleton
+ (instancetype)sharedInstance;

@end

