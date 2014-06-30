//
//  MOFThuisBezorgdDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 19/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "MOFShopDAO.h"

/**
 *  DAO for supporting ThuisBezorg catalog. Instantiating this DAO will replace the existing MOFShopDAO to provide a
 *  transparent TB handling
 */
@interface MOFTBShopDAO : MOFShopDAO


/**
*  Load all restaurants based on some search criteria like location, postcode,...
*
*  @param location    Indicates the location to fetch the info from. Optional
*  @param postCode    Area to look. Optional
*  @param animation   Animation type to pass to the animation handler of the request
*  @param resultBlock Block executed with the resulting array of MOFMerchant if any
*  @param errorBlock  Block executed with the resulting error if any.
*
*  @return Connection fired. Cancellable.
*/
- (MOFNetworkConnection *)loadMerchantsWithLocation:(CLLocationCoordinate2D)location
                                           postCode:(NSString *)postCode
                                          animation:(MOFNetworkAnimation)animation
                                           onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                            onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load a restaurant detail and optionally includes the categories and products in its menu
 *
 *  @param restaurant       Restaurant to load details.
 *  @param deliveryLocation Location to deliver the order. Optional
 *  @param deliveryPostCode Postcode to deliver the order. Optional
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFMerchant
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantDetail:(MOFMerchant *)restaurant
                            deliveryLocation:(CLLocationCoordinate2D)deliveryLocation
                            deliveryPostCode:(NSString *)deliveryPostCode
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;


@end
