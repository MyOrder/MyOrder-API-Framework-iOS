//
//  MOConnection.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/22/13.
//
//

#import <Foundation/Foundation.h>

@class MOApiConnection;
typedef void(^MOApiConnectionSuccessBlock)(MOApiConnection *connection, NSDictionary *response);
typedef void(^MOApiConnectionErrorBlock)(MOApiConnection *connection, NSError *error);

@interface MOApiConnection : NSObject

//Global configuration properties
+ (void)setBaseURL:(NSURL *)baseURL;
+ (NSURL *)baseURL;

+ (void)setSessionId:(NSString *)sessionId;
+ (void)setUserId:(NSString *)userId;
+ (void)setPassword:(NSString *)password;
+ (void)setMobilePhone:(NSString *)phone;

//Connection instance methods
@property(nonatomic, strong) NSDictionary *parameters;
@property(nonatomic, copy) MOApiConnectionSuccessBlock onSuccessBlock;
@property(nonatomic, copy) MOApiConnectionErrorBlock onErrorBlock;

- (id)initWithEndPoint:(NSString *)endpoint;
- (void)start;

@end
