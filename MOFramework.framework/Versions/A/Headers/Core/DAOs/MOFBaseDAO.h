//
//  MOFBaseDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 14/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Result block invoked on DAO operations when asynchronous results of type array is expected
 *  @param results Array with resulting objects
 */
typedef void(^MOFBaseDAOResultArrayBlock)(NSArray *results);

/**
 *  Result block invoked on DAO operations when asynchronous results of single object or multiple results is expected
 *  @param results Object with resulting object
 */
typedef void(^MOFBaseDAOResultBlock)(id results);

/**
 *  Error block invoked on DAO operations when an error happens
 *  @param error Resulting error. On rare occassions it could be nil
 */
typedef void(^MOFBaseDAOErrorBlock)(NSError *error);


@interface MOFBaseDAO : NSObject

/**
 *  Instantiates the sharedInstance if not created already. Call this method before start using a DAO. 
 *  If Unit test, use `setSharedInstance` to set a mock instead.
 */
+ (void)instantiate;


/**
 *  Returns the configured shared instance. Call `instantiate` or `setSharedInstance` before using this method
 *
 *  @return shared instance
 */
+ (instancetype)sharedInstance;


/**
 *  Sets the shared instance to the given object. You should not call this method unless you want to
 *  modify how a DAO works by providind a custom subclass or mock
 *
 *  @param instance new object instance to use as shared
 */
+ (void)setSharedInstance:(id)instance;

@end
