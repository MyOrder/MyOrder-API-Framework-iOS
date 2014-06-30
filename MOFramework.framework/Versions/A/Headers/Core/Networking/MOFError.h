//
//  MOFError.h
//  MyOrderApp
//
//  Created by Angel Garcia on 21/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Error code when response from Network is not correct (error in data or no response at all)
 */
static NSInteger const kMOFErrorCodeNetworkError = 1000;

/**
 *  Error code used when fetching server API
 */
static NSInteger const kMOFErrorCodeAPIError = 1001;

/**
 *  Error code used when error instantiated from code by the use of `errorWithMessage` method
 */
static NSInteger const kMOFErrorCodeGenericMessage = 1002;

/**
 *  Error code used when the JSON response can not be parsed
 */
static NSInteger const kMOFErrorCodeInvalidJSON = 1003;

/**
 *  Error code used when the user can not access a particular endpoint
 */
static NSInteger const kMOFErrorCodeUnauthorized = 1004;

/**
 *  Error code used when the endpoint requires a ThuisAfgehaald login first
 */
static NSInteger const kMOFErrorTALoginRequired = 1005;



/**
 *  Subclass of NSError with extra information
 */
@interface MOFError : NSError

/**
 *  Returns new error with a specific client side message
 *
 *  @param message Message for the error
 *
 *  @return MOFError with code kMOFErrorCodeGenericMessage
 */
+ (instancetype)errorWithMessage:(NSString *)message;

/**
 *  Returns new error from an invalid Server API response
 *
 *  @param dict Response from server
 *
 *  @return MOFError with code kMOFErrorCodeAPIError
 */
+ (instancetype)errorWithAPIResponse:(NSDictionary *)dict;

/**
 *  Returns new error from an invalid JSON
 *
 *  @param dict String to convert to JSON
 *
 *  @return MOFError with code kMOFErrorCodeInvalidJSON
 */
+ (instancetype)errorWithJSONResponse:(NSString *)message;


/**
 *  Array of specific suberrors (if any). For example, in a form each invalid field would be listed here
 */
@property (nonatomic, strong) NSArray *subErrors;


@end
