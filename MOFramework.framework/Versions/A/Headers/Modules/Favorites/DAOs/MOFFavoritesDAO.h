//
//  MOFFavoritesDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 14/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"
#import "MOFModelObject.h"

/**
 *  Constant with the Notification fired when a new favorite is added. User info contains added object
 */
static const NSString *kMOFFavoritesAddNotification = @"kMOFFavoritesAddNotification";

/**
 *  Constant with the Notification fired when a favorite is removed from list. User info contains removed object
 */
static const NSString *kMOFFavoritesRemoveNotification = @"kMOFFavoritesRemoveNotification";


/**
 *  DAO for managing favorites. Current implementation of favorites is stored locally on device, but API is 
 *  ready for future server side stored favorites. Any MOFModelObject implementing NSCopy protocol can be favorited
 */
@interface MOFFavoritesDAO : MOFBaseDAO


/**
 *  @return list of all previously loaded favorites
 */
- (NSArray *)allFavorites;


/**
 *  @return list of all previously loaded favorites for a particular model class
 */
- (NSArray *)allFavoritesForType:(Class)cls;


/**
 *  Check if an object is in favorite list
 *
 *  @param object Object to check
 *
 *  @return YES if object exist in favorites
 */
- (BOOL)isFavorite:(MOFModelObject *)object;


/**
 *  Add or remove an object in favorites
 *
 *  @param favorite BOOL indicating whether to store it or remove it
 *  @param object   Object to store
 */
- (void)setFavorite:(BOOL)favorite forObject:(MOFModelObject *)object;


/**
 *  Load all favorites from server. Currently not implemented, but mocks expected response
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFModelObject if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadFavoritesWithAnimation:(MOFNetworkAnimation)animation
                                            onResult:(MOFBaseDAOResultBlock)resultBlock
                                             onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Save all favorites on server side. Currently not implemented, but mocks expected response
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFMovie if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)saveFavoritesWithAnimation:(MOFNetworkAnimation)animation
                                            onResult:(MOFBaseDAOResultBlock)resultBlock
                                             onError:(MOFBaseDAOErrorBlock)errorBlock;


@end
