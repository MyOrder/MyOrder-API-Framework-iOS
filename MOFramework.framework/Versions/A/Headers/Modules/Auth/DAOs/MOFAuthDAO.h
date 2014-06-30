//
//  MOFAuthDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 24/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"
#import "MOFNetworkConnection.h"

@class MOFSession;
@class MOFUser;
@class MOFAddress;

/**
 *  DAO to manage login and user data. Required for other DAOs to work
 */
@interface MOFAuthDAO : MOFBaseDAO

/**
 *  Current session data. A session can be anonymous if user is not logged in
 */
@property (nonatomic, readonly, strong) MOFSession *session;


/**
 *  User data if session is not annonymous
 */
@property (nonatomic, readonly, strong) MOFUser *user;


/**
 *  Property indicating if a login operation is in progress. Observable
 */
@property (nonatomic, readonly, assign) BOOL isLogging;


/**
 *  Performs an anonymous login in the system. If user is not logged in this method
 *  should be called to get an anonymous session
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFSession object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loginAnonymouslyWithAnimation:(MOFNetworkAnimation)animation
                                               onResult:(MOFBaseDAOResultBlock)resultBlock
                                                onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Performs a logout in the system. This method also do a logout in the MyOrder Payment SDK
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param force       If force make logout even for anonymous user
 *  @param resultBlock Block executed with the resulting MOFSession object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)logoutWithAnimation:(MOFNetworkAnimation)animation
                                        force:(BOOL)force
                                     onResult:(MOFBaseDAOResultBlock)resultBlock
                                      onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load user details for current session. This method is automatically called after a successful login
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFUser object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadUserWithAnimation:(MOFNetworkAnimation)animation
                                       onResult:(MOFBaseDAOResultBlock)resultBlock
                                        onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Update user information with provided info
 *
 *  @param email       New email. Pass nil to keep previous
 *  @param mobilePhone New phone number. Pass nil to keep previous
 *  @param firstName   New first name. Pass nil to keep previous
 *  @param lastName    New last name. Pass nil to keep previous
 *  @param birthDate   New birthday. Not implemented yet
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFUser object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)updateUserWithEmail:(NSString *)email
                                  mobilePhone:(NSString *)mobilePhone
                                    firstName:(NSString *)firstName
                                     lastName:(NSString *)lastName
                                    birthDate:(NSDate *)birthDate
                                    animation:(MOFNetworkAnimation)animation
                                     onResult:(MOFBaseDAOResultBlock)resultBlock
                                      onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Update user profile image
 *
 *  @param image       UIImage to upload
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFUser object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)updateUserImage:(UIImage *)image
                                animation:(MOFNetworkAnimation)animation
                                 onResult:(MOFBaseDAOResultBlock)resultBlock
                                  onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Create a new address for the user. Currently this method is equivalent to `updateUserAddress`
 *  because only 1 address is supported per user.
 *
 *  @param name        Not implemented
 *  @param street      New street. Pass nil to keep previous
 *  @param number      New house number. Pass nil to keep previous
 *  @param postCode    New postal code. Pass nil to keep previous
 *  @param city        New city. Pass nil to keep previous
 *  @param country     Not implemented
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFUser object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)createUserAddressWithName:(NSString *)name
                                             street:(NSString *)street
                                        houseNumber:(NSString *)number
                                           postCode:(NSString *)postCode
                                               city:(NSString *)city
                                            country:(NSString *)country
                                          animation:(MOFNetworkAnimation)animation
                                           onResult:(MOFBaseDAOResultBlock)resultBlock
                                            onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Updates an existing address for a user with new values
 *
 *  @param address     Existing address to modify
 *  @param name        Not implemented
 *  @param street      New street. Pass nil to keep previous
 *  @param number      New house number. Pass nil to keep previous
 *  @param postCode    New postal code. Pass nil to keep previous
 *  @param city        New city. Pass nil to keep previous
 *  @param country     Not implemented
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting MOFUser object
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)updateUserAddress:(MOFAddress *)address
                                   withName:(NSString *)name
                                     street:(NSString *)street
                                houseNumber:(NSString *)number
                                   postCode:(NSString *)postCode
                                       city:(NSString *)city
                                    country:(NSString *)country
                                  animation:(MOFNetworkAnimation)animation
                                   onResult:(MOFBaseDAOResultBlock)resultBlock
                                    onError:(MOFBaseDAOErrorBlock)errorBlock;




@end
