//
//  MOFCouponsDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 17/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"

@class MOFMerchant;
@class MOFCoupon;

@interface MOFCouponsDAO : MOFBaseDAO

/**
 *  Load all coupons from copons ids
 *
 *  @param couponIds        List of coupons to fetch
 *  @param includeMerchants BOOL indicating whether to fetch the merchant detail associated to the coupon
 *  @param animation        Animation type to pass to the animation handler of the request
 *  @param resultBlock      Block executed with the resulting array of MOFCoupon if any
 *  @param errorBlock       Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadCouponsWithIds:(NSArray *)couponIds
                            includeMerchants:(BOOL)includeMerchants
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all coupons from a particular merchant
 *
 *  @param merchant    Merchant to load coupons from
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFCoupon if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadCouponsWithMerchant:(MOFMerchant *)merchant
                                        animation:(MOFNetworkAnimation)animation
                                         onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                          onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all copons that the user saved
 *
 *  @param animation        Animation type to pass to the animation handler of the request
 *  @param resultBlock      Block executed with the resulting array of MOFCoupon if any
 *  @param errorBlock       Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadSavedCouponsWithAnimation:(MOFNetworkAnimation)animation
                                               onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                                onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Activate a coupon for its use
 *
 *  @param coupon      Coupon to activate
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed when activation succeds
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)activateCoupon:(MOFCoupon *)coupon
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Deactivate the use of a coupon
 *
 *  @param coupon      Coupon to deactivate
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed when activation succeds
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)deactivateCoupon:(MOFCoupon *)coupon
                                 animation:(MOFNetworkAnimation)animation
                                  onResult:(MOFBaseDAOResultBlock)resultBlock
                                   onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Save a coupon in the user's list of coupons
 *
 *  @param coupon      Coupon to save
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed when activation succeds
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)saveCoupon:(MOFCoupon *)coupon
                           animation:(MOFNetworkAnimation)animation
                            onResult:(MOFBaseDAOResultBlock)resultBlock
                             onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Removes a coupon from the user's list of coupons
 *
 *  @param coupon      Coupon to remove
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed when activation succeds
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)removeCoupon:(MOFCoupon *)coupon
                             animation:(MOFNetworkAnimation)animation
                              onResult:(MOFBaseDAOResultBlock)resultBlock
                               onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
