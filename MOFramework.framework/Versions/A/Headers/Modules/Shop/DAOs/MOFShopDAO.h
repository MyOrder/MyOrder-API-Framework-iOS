//
//  MOFShopDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 25/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MOFBaseDAO;
@class MOFMerchant;
@class MOFCategory;
@class MOFProduct;

/**
 *  DAO to fetch all the catalog information, from merchants to products
 */
@interface MOFShopDAO : MOFBaseDAO


/**
*  Load all merchants based on some basic criteria: type, location and term
*
*  @param merchantTypes Array with all MOFMerchantType types to load. Optional.
*  @param location      indicates the location to fetch the info from. Optional
*  @param term          search term to use. Optional
*  @param animation     Animation type to pass to the animation handler of the request
*  @param resultBlock   Block executed with the resulting array of MOFMerchant if any
*  @param errorBlock    Block executed with the resulting error if any.
*
*  @return Connection fired. Cancellable.
*/
- (MOFNetworkConnection *)loadMerchantsWithTypes:(NSArray *)merchantTypes
                                        location:(CLLocationCoordinate2D)location
                                            term:(NSString *)term
                                       animation:(MOFNetworkAnimation)animation
                                        onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                         onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all merchants based on advance search criteria like type, location, term,... If limit
 *  and offset included, then paginated results are expected. Note that a page could contain less than
 *  limit locations in case the user can not see some private ones
 *
 *  @param merchantTypes Array with all MOFMerchantType types to load. Optional.
 *  @param location      indicates the location to fetch the info from. Optional
 *  @param term          search term to use. Optional
 *  @param externalIds   Array of ids read from a QR code or any other external source. Optional
 *  @param postCode      Area to look. Optional
 *  @param city          City to look. Optional
 *  @param offset        Position of first merchant to be returned in paginated results
 *  @param limit         Amount of merchants to retrieve
 *  @param animation     Animation type to pass to the animation handler of the request
 *  @param resultBlock   Block executed with the resulting array of MOFMerchant if any
 *  @param errorBlock    Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantsWithTypes:(NSArray *)merchantTypes
                                        location:(CLLocationCoordinate2D)location
                                            term:(NSString *)term
                                     externalIds:(NSArray *)externalIds
                                        postCode:(NSString *)postCode
                                            city:(NSString *)city
                                          offset:(NSInteger)offset
                                           limit:(NSInteger)limit
                                       animation:(MOFNetworkAnimation)animation
                                        onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                         onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all merchants in clusters based on location
 *
 *  @param merchantTypes       Array with all MOFMerchantType types to load. Optional.
 *  @param topLeftlocation     indicates the location of the top left corner to fetch the info from.
 *  @param bottomRightlocation indicates the location of the bottom right corner to fetch the info from.
 *  @param limit               maximum amount of merchants that can be shown in the map (rest will be clustered)
 *  @param animation           Animation type to pass to the animation handler of the request
 *  @param resultBlock         Block executed with the resulting data as a dictionary of MOFMerchant and MOFCluster arrays
 *  @param errorBlock          Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantClustersWithTypes:(NSArray *)merchantTypes
                                                   from:(CLLocationCoordinate2D)topLeftlocation
                                                     to:(CLLocationCoordinate2D)bottomRightlocation
                                                  limit:(NSInteger)limit
                                              animation:(MOFNetworkAnimation)animation
                                               onResult:(MOFBaseDAOResultBlock)resultBlock
                                                onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load a merchant detail and optionally includes the categories and products in its menu
 *
 *  @param merchant          Merchant to load.
 *  @param includeCategories Indicates if the categories in the menu should be included
 *  @param includeProducts   Indicates if the products in the menu should be included
 *  @param animation         Animation type to pass to the animation handler of the request
 *  @param resultBlock       Block executed with the resulting updated MOFMerchant
 *  @param errorBlock        Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantDetail:(MOFMerchant *)merchant
                           includeCategories:(BOOL)includeCategories
                             includeProducts:(BOOL)includeProducts
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Update the status of a particular merchant. Useful for refreshing the open status and other "live" parameters
 *
 *  @param merchant    Merchant to load
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting NSDictionary with the retrieved status.
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMerchantStatus:(MOFMerchant *)merchant
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all categories for a specific group of merchants or types
 *
 *  @param merchantTypes Array of MOFMerchantType types of the categories to load. Optional
 *  @param merchants     Array of MOFMerchant to load the categories from. Optional
 *  @param animation     Animation type to pass to the animation handler of the request
 *  @param resultBlock   Block executed with the resulting array of MOFCategory if any
 *  @param errorBlock    Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadCategoriesWithMerchantTypes:(NSArray *)merchantTypes
                                                merchants:(NSArray *)merchants
                                                animation:(MOFNetworkAnimation)animation
                                                 onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                                  onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all categories for a specific group of merchants or types
 *
 *  @param merchantTypes Array of MOFMerchantType types of the categories to load. Optional
 *  @param merchants     Array of MOFMerchant to load the categories from. Optional
 *  @param offset        Position of first result to be returned in paginated results
 *  @param limit         Amount of results to retrieve
 *  @param animation     Animation type to pass to the animation handler of the request
 *  @param resultBlock   Block executed with the resulting array of MOFCategory if any
 *  @param errorBlock    Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadCategoriesWithMerchantTypes:(NSArray *)merchantTypes
                                                merchants:(NSArray *)merchants
                                                   offset:(NSInteger)offset
                                                    limit:(NSInteger)limit
                                                animation:(MOFNetworkAnimation)animation
                                                 onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                                  onError:(MOFBaseDAOErrorBlock)errorBlock;



/**
 *  Load a category detail
 *
 *  @param category    Category to laod
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned. Result contains an updated MOFCategory
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */

- (MOFNetworkConnection *)loadCategoryDetail:(MOFCategory *)category
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all products based on some simple criteria: types, merchants and term
 *
 *  @param merchantTypes Array with all MOFMerchantType types to load. Optional.
 *  @param merchants     Array of all MOFMerchant to retrieve products from. Optional.
 *  @param term          search term to use. Optional
 *  @param animation     loading indicator style
 *  @param resultBlock   Block executed when the result is returned. Results contain an NSArray of MOFProduct
 *  @param errorBlock    Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadProductsWithMerchantTypes:(NSArray *)merchantTypes
                                              merchants:(NSArray *)merchants
                                                   term:(NSString *)term
                                              animation:(MOFNetworkAnimation)animation
                                               onResult:(MOFBaseDAOResultBlock)resultBlock
                                                onError:(MOFBaseDAOErrorBlock)errorBlock;



/**
 *  Load all products based on some advance criteria like type, merchants, categories, term,...
 *
 *  @param merchantTypes Array with all MOFMerchantType types to load. Optional.
 *  @param merchants     Array of all MOFMerchant to retrieve products from. Optional.
 *  @param term          search term to use. Optional
 *  @param categories    Array of all MOFCategory instances to retrieve products from. Optional.
 *  @param externalIds   Array of ids read from a QR code or any other external source. Optional
 *  @param offset        Position of first result to be returned in paginated results
 *  @param limit         Amount of results to retrieve
 *  @param animation     loading indicator style
 *  @param resultBlock   Block executed when the result is returned. Results contain an NSArray of MOFProduct
 *  @param errorBlock    Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */

- (MOFNetworkConnection *)loadProductsWithMerchantTypes:(NSArray *)merchantTypes
                                              merchants:(NSArray *)merchants
                                                   term:(NSString *)term
                                             categories:(NSArray *)categories
                                            externalIds:(NSArray *)externalIds
                                                 offset:(NSInteger)offset
                                                  limit:(NSInteger)limit
                                              animation:(MOFNetworkAnimation)animation
                                               onResult:(MOFBaseDAOResultBlock)resultBlock
                                                onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load a product detail
 *
 *  @param product     Product to laod
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFProduct
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadProductDetail:(MOFProduct *)product
                                  animation:(MOFNetworkAnimation)animation
                                   onResult:(MOFBaseDAOResultBlock)resultBlock
                                    onError:(MOFBaseDAOErrorBlock)errorBlock;



/**
 *  Make a checkout from a merchant
 *
 *  @param merchant    Merchant to checkout
 *  @param location    Location from where the user is making the checkin
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFCheckIn
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)checkInMerchant:(MOFMerchant *)merchant
                                 location:(CLLocationCoordinate2D)location
                                animation:(MOFNetworkAnimation)animation
                                 onResult:(MOFBaseDAOResultBlock)resultBlock
                                  onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Make a checkout from a merchant
 *
 *  @param merchant    Merchant to checkout
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFCheckIn
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)checkOutMerchant:(MOFMerchant *)merchant
                                 animation:(MOFNetworkAnimation)animation
                                  onResult:(MOFBaseDAOResultBlock)resultBlock
                                   onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load the checking information for a specific merchant and user
 *
 *  @param merchant    Merchant to load the checkin status
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFCheckInStatus
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection*)loadCheckInStatusAndCount:(MOFMerchant *)merchant
                                         animation:(MOFNetworkAnimation)animation
                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                           onError:(MOFBaseDAOErrorBlock)errorBlock;



@end
