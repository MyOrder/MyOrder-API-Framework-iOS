//
//  MOFCoreDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 13/12/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "MOFNetworkConnection.h"
#import "MOFMerchantType.h"
#import "MOFBaseDAO.h"


/**
 *  Block definition for the version check.
 *
 *  @param message Message to display
 *  @param options Options have a message and either a url or action, where action can be "close" to force abort
 */
typedef void(^MOFMOFCoreVersionCheckBlock)(NSString *message, NSArray *options);



/**
 *  DAO with generic functionality used in all other modules
 */
@interface MOFCoreDAO : MOFBaseDAO

/**
 *  Returns all existing merchant types in the app (previously downloaded and persisted)
 *
 *  @return List of loaded MOFMerchantType objects
 */
- (NSArray *)allMerchantTypes;


/**
 *  Load all merchant types. If location is provided, the merchant type will contain an
 *  updated `count` value with the amount of merchants around you for that type
 *
 *  @param location    Location to check merchants around. Pass kCLLocationCoordinate2DInvalid if none required
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFMerchantType if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantTypesForLocation:(CLLocationCoordinate2D)location
                                             animation:(MOFNetworkAnimation)animation
                                              onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                               onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all cities with given terms and for list of types
 *
 *  @param merchantTypes Optional list of MOFMerchantType objects that you want to query
 *  @param term          Optional term to match on city name
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of NSString if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadCitiesWithTypes:(NSArray *)merchantTypes
                                         term:(NSString *)term
                                    animation:(MOFNetworkAnimation)animation
                                     onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                      onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Checks that the client is updated properly by querying the server. Result block will be invoked with the message
 *  to display and all options that the user have to dismiss the message (close, update, view...)
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the result of the check
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)versionCheckWithAnimation:(MOFNetworkAnimation)animation
                                           onResult:(MOFMOFCoreVersionCheckBlock)resultBlock;


@end
