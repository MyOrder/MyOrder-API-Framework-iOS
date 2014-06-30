//
//  MOFParkingDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 15/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

@import CoreLocation;

#import "MOFBaseDAO.h"
#import "MOFParkingPoint.h"
#import "MOFParkingSession.h"

/**
 *  DAO for managing Parking sessions
 */
@interface MOFParkingDAO : MOFBaseDAO


/**
 *  Load all parking points for a particular location
 *
 *  @param location    Location of points to load
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFParkingPoint if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadPointsWithLocation:(CLLocationCoordinate2D)location
                                       animation:(MOFNetworkAnimation)animation
                                        onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                         onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Tries to load an existing parking session if any. Returns nil if none existing
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the existing MOFParkingSession if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadParkingSessionWithAnimation:(MOFNetworkAnimation)animation
                                                 onResult:(MOFBaseDAOResultBlock)resultBlock
                                                  onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Creates a new parking session for a location or point id, ending on a particular time.
 *
 *  @param location    Location for the new parking session. If kCLLocationCoordinate2DInvalid, then it uses pointId
 *  @param pointId     Point id corresponding to the parking spot numbers.
 *  @param date        End date of parking session. Note that it has to end within 24 hours.
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the created MOFParkingSession
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)createParkingSessionWithLocation:(CLLocationCoordinate2D)location
                                                 orPointId:(NSString *)pointId
                                                   endTime:(NSDate *)date
                                                 animation:(MOFNetworkAnimation)animation
                                                  onResult:(MOFBaseDAOResultBlock)resultBlock
                                                   onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Create a new parking session as a result of extending an existing one
 *
 *  @param session     Existing parking session to extend
 *  @param date        End date of parking session. Note that it has to end within 24 hours.
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the created MOFParkingSession
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)extendParkingSession:(MOFParkingSession *)session
                                       endTime:(NSDate *)date
                                     animation:(MOFNetworkAnimation)animation
                                      onResult:(MOFBaseDAOResultBlock)resultBlock
                                       onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Starts the checkout (payment) of a created session. This method will return an MOOrder ready
 *  to be sent to the MyOrder payment SDK for payment.
 *
 *  @param session      Session to checkout
 *  @param licensePlate License plate of the car
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the created MOOrder to pay
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)checkoutParkingSession:(MOFParkingSession *)session
                                    licensePlate:(NSString *)licensePlate
                                       animation:(MOFNetworkAnimation)animation
                                        onResult:(MOFBaseDAOResultBlock)resultBlock
                                         onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Stops an existing parking session and returns remaining time as money to the MiniTix wallet
 *
 *  @param session     Existing session to stop
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the updated MOFParkingSession object (including real price)
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)stopParkingSession:(MOFParkingSession *)session
                                   animation:(MOFNetworkAnimation)animation
                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                     onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
