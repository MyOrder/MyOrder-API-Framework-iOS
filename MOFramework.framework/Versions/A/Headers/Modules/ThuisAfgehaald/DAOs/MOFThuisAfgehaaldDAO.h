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

- (MOFNetworkConnection *)loginUserWithUsername:(NSString *)username
                                       password:(NSString *)password
                                      animation:(MOFNetworkAnimation)animation
                                       onResult:(MOFBaseDAOResultBlock)resultBlock
                                        onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadMealsWithFilter:(NSString *)filter
                                     location:(CLLocationCoordinate2D)location
                                     postCode:(NSString *)postalCode
                                   pageNumber:(NSString*)pageNumber
                                    animation:(MOFNetworkAnimation)animation
                                     onResult:(MOFBaseDAOResultBlock)resultBlock
                                      onError:(MOFBaseDAOErrorBlock)errorBlock ;


- (MOFNetworkConnection *)loadMealDetail:(MOFTAMeal *)meal
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadCookDetail:(MOFTAMeal *)meal
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadFollowUnfollowCook:(MOFTAMeal*)meal
                                       animation:(MOFNetworkAnimation)animation
                                        onResult:(MOFBaseDAOResultBlock)resultBlock
                                         onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)requestThuisAfgehaaldMeal:(MOFTAMeal*)meal
                                           quantity:(NSString*)quantity
                                           comments:(NSString*)comment
                                         pickUpDate:(NSString*)pickUpDate
                                          startTime:(NSString*)startTime
                                            endTime:(NSString*)endTime
                                          animation:(MOFNetworkAnimation)animation
                                           onResult:(MOFBaseDAOResultBlock)resultBlock
                                            onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)pickUpThuisAfgehaaldMeal:(MOFTAMeal*)meal
                                          quantity:(NSString*)quantity
                                           comment:(NSString*)comment
                                         animation:(MOFNetworkAnimation)animation
                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                           onError:(MOFBaseDAOErrorBlock)errorBlock;



@end
