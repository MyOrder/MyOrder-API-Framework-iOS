//
//  MOFNetworkConnection.h
//  Core
//
//  Created by Angel Garcia on 14/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import "XTSessionRestLayerConnection.h"

@protocol MOFNetworkingMappingProtocol;
@class MOFNetworkConnection;

/**
 *  Enum with animation types to show when a network operation
 */
typedef enum {
    /**
     *  Do not show any animation. No animation handler called
     */
    MOFNetworkAnimationNone,
    
    /**
     *  Show the animation only when error happens. Animation handler only called on error
     */
    MOFNetworkAnimationOnlyError,
    
    /**
     *  Show a toast-like animation. Animation handler always called
     */
    MOFNetworkAnimationToast,
    
    /**
     *  Show a HUD like indicator. Animation handler always called
     */
    MOFNetworkAnimationHUD,
    
    /**
     *  Show a HUD like indicator and a confirmation message. Animation handler always called
     */
    MOFNetworkAnimationHUDWithConfirmation,

    /**
     *  Reserved for third party app developers to include other custom messages. Animation handler always called
     */
    MOFNetworkAnimationOther

} MOFNetworkAnimation;


/**
 *  Enum with animation status associated to a request. To be used with the animation type
 */
typedef enum {
    /**
     *  Request just started to load
     */
    MOFNetworkAnimationStatusStart,
    
    /**
     *  Request finished successfully
     */
    MOFNetworkAnimationStatusSuccess,
    
    /**
     *  Request finished with error
     */
    MOFNetworkAnimationStatusError
    
} MOFNetworkAnimationStatus;

typedef void (^MOFNetworkAnimationHandler) (MOFNetworkConnection *connection, MOFNetworkAnimationStatus status);


@interface MOFNetworkConnection : XTSessionRestLayerConnection

//Set credentials
+ (void)setAccessKey:(NSString *)accessKey;
+ (void)setSecretKey:(NSString *)secretKey;

//Sets the session token for all connections that use session
+ (void)setSessionToken:(NSString *)authHeader;
+ (NSString *)sessionToken;

//Sets a global animation handler for all requests
+ (void)setAnimationHandler:(MOFNetworkAnimationHandler)animationHandler;

//Sets the global base URL for the API calls
+ (void)setBaseUrl:(NSString *)baseUrl;
+ (NSString *)baseUrl;

//Creates an asyncrhonous request
+ (instancetype)sendAsynchronousAPIRequestWithQuery:(NSString *)query
                                         modelClass:(Class<MOFNetworkingMappingProtocol>)modelClass
                                  connectionHandler:(XTLayerConnectionHandler)connectionHandler
                                  completionHandler:(XTLayerConnectionCompletionHandler)completionHandler;

//Indicates if the request should include session information. If YES an no session yet, the it is on put on hold. Defaults to YES.
@property (nonatomic, assign) BOOL requireSession;

//Indicates if the request must present loading sanimations
@property (nonatomic, assign) MOFNetworkAnimation animation;

//Allows to configure the animation handler. Set `animation` property for standard animations
@property (nonatomic, copy) MOFNetworkAnimationHandler animationHandler;
@property (nonatomic, strong) NSString *successMessage;

//Other HTTP properties
@property (nonatomic, strong) NSString *HTTPMethod;
@property (nonatomic, strong) NSString *HTTPBody;
@property (nonatomic, strong) NSString *HTTPContentType;


@end
