//
//  MOFThuisAfgehaaldDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 11/02/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"
@import CoreLocation;

@class MOFTACook;
@class MOFTAMeal;

@interface MOFThuisAfgehaaldDAO : MOFBaseDAO

/**
 *  Login in ThuisAfgehaald
 *
 *  @param username    username
 *  @param password    password
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contain 200(OK)
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */

- (MOFNetworkConnection *)loginUserWithUsername:(NSString *)username
                                       password:(NSString *)password
                                      animation:(MOFNetworkAnimation)animation
                                       onResult:(MOFBaseDAOResultBlock)resultBlock
                                        onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load Meals for Location
 *
 *  @param location    Location from where you want to get Meals
 *  @param pageNumber  page number
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTAMeal
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadMealsWithLocation:(CLLocationCoordinate2D)location
                                     pageNumber:(NSString*)pageNumber
                                      animation:(MOFNetworkAnimation)animation
                                       onResult:(MOFBaseDAOResultBlock)resultBlock
                                        onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load Detail for Meal
 *
 *  @param meal        Meal object
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTAMeal
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadMealDetail:(MOFTAMeal *)meal
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load Cook Details
 *
 *  @param meal        Cook Object
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTACook
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadCookDetail:(MOFTACook *)cook
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;



/**
 *  Follow - UnFollow Cook
 *
 *  @param cook        Cook Object
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTACook
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)followUnfollowCook:(MOFTACook*)cook
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Request ThuisAfgehaald Meal (A meal can only be requested if meal has request property set to a value greater than zero)
 *
 *  @param meal        Meal Object
 *  @param quantity    number of quantity for meal
 *  @param comment     comment for meal
 *  @param pickUpDate  pickup date
 *  @param startTime   start time
 *  @param endTime     end time
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)requestThuisAfgehaaldMeal:(MOFTAMeal*)meal
                                           quantity:(NSString*)quantity
                                           comments:(NSString*)comment
                                         pickUpDate:(NSString*)pickUpDate
                                          startTime:(NSString*)startTime
                                            endTime:(NSString*)endTime
                                          animation:(MOFNetworkAnimation)animation
                                           onResult:(MOFBaseDAOResultBlock)resultBlock
                                            onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Pick Up ThuisAfgehaald Meal (A meal can only be picked up if meal has request property set to zero)
 *
 *  @param meal        Meal Object
 *  @param quantity    number of quantity of meal
 *  @param comment     comment
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)pickUpThuisAfgehaaldMeal:(MOFTAMeal*)meal
                                          quantity:(NSString*)quantity
                                           comment:(NSString*)comment
                                         animation:(MOFNetworkAnimation)animation
                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                           onError:(MOFBaseDAOErrorBlock)errorBlock;



@end
