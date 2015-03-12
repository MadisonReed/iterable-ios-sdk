//
//  Iterable_API.h
//  Iterable-iOS-SDK
//
//  Created by Ilya Brin on 11/19/14.
//  Copyright (c) 2014 Iterable. All rights reserved.
//

@import Foundation;

@interface IterableAPI : NSObject

- (instancetype) initWithApiKey:(NSString *)apiKey andEmail:(NSString *) email;

/*!
 @method
 
 @abstract
 Initializes Iterable with launchOptions.
 
 @discussion
 */
- (instancetype) initWithApiKey:(NSString *)apiKey andEmail:(NSString *) email launchOptions:(NSDictionary *)launchOptions;

/*!
 @method
 
 @abstract
 Initializes a shared instance of Iterable with launchOptions.
 This method will set up a singleton instance of the <code>IterableAPI</code> class for
 you using the given project API key. When you want to make calls to Iterable
 elsewhere in your code, you can use <code>sharedInstance</code>. If launchOptions is there and
 the app was launched from a remote push notification, we will track a pushOpen.
 
 @discussion
 */
+ (IterableAPI *) sharedInstanceWithApiKey:(NSString *)apiKey andEmail:(NSString *) email launchOptions:(NSDictionary *)launchOptions;

/*!
 @method
 
 @abstract
 Returns the previously instantiated singleton instance of the API.
 
 @discussion
 The API must be initialized with <code>sharedInstanceWithApiKey:</code> before
 calling this class method.
 
 */
+ (IterableAPI *)sharedInstance;

- (void)getUser;
- (void)registerToken:(NSData *)token appName:(NSString *)appName;

/*!
 @method
 
 @abstract
 Tracks a purchase. (not implemented yet)
 
 @discussion
 Pass in the total purchase amount and an <code>NSArray</code> of CommerceItems
 
 @param total   total purchase amount
 @param items   list of purchased items
 */
//- (void)trackPurchase:(NSNumber *)total items:(NSArray *)items;

/*!
 @method
 
 @abstract
 Tracks a pushOpen event.
 
 @discussion
 Pass in the <code>userInfo</code> from the push notification payload
 
 @param userInfo    the push notification payload
 */
- (void)trackPushOpen:(NSDictionary *)userInfo;

/*!
 @method
 
 @abstract
 Tracks a pushOpen event.
 
 @discussion
 Pass in the the relevant campaign data.
 
 @param userInfo    the push notification payload
 */
- (void)trackPushOpen:(NSNumber *)campaignId templateId:(NSNumber *)templateId appAlreadyRunning:(BOOL)appAlreadyRunning;

/*!
 Here for testing. Will go away.
 */
- (void)sendPush;
@end
