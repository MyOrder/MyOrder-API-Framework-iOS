//
//  MOFNotificationsDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 14/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"

/**
 *  Environment to register. Use MOFNotificationsEnvironmentSandbox for development mode only.
 *  For InHouse or AppStore use MOFNotificationsEnvironmentLive
 */
typedef enum  {
    MOFNotificationsEnvironmentLive,
    MOFNotificationsEnvironmentSandbox
} MOFNotificationsEnvironment;

/**
 *  DAO to manage Apple Push Notifications registrations.
 */
@interface MOFNotificationsDAO : MOFBaseDAO

/**
 *  Registered apns token
 */
@property (nonatomic, readonly, copy) NSString *apnsToken;

/**
 *  Disable push notifications. If this property is set after registering then it automatically does 
 *  an unregister when set to NO, and a register when set back to YES
 */
@property (nonatomic, assign) BOOL disablePushNotifications;

/**
 *  Sets the environment for the notifications. Should be set before calling to register/unregister methods
 */
@property (nonatomic, assign) MOFNotificationsEnvironment environment;


/**
 *  Registers the device for receiving APNS. Note that if the `disablePushNotifications` is set then the
 *  method will only store the apnsToken, but will not register the device on APNS.
 *
 *  @param token       APNS token register on application:didRegisterForRemoteNotificationsWithDeviceToken: appDelegate method
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting response from server
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)registerPushNotificationsWithToken:(NSString *)token
                                                   animation:(MOFNetworkAnimation)animation
                                                    onResult:(MOFBaseDAOResultBlock)resultBlock
                                                     onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Unregisters the device from receiving APNS after a previous register call
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting response from server
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)unregisterPushNotificationsWithAnimation:(MOFNetworkAnimation)animation
                                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                                           onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
