//
//  XTRestLayerConnectionProtocol.h
//  XTRestLayer
//
//  Created by Berik Visschers on 2013-02-22.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XTRestLayerTypes.h"

@protocol XTRestLayerMapperProtocol;
@protocol XTRestLayerConnectionProtocol <NSObject>

+ (instancetype)sendAsynchronousRequest:(NSURLRequest *)request
                                 mapper:(id<XTRestLayerMapperProtocol>)mapper
                      connectionHandler:(XTLayerConnectionHandler)connectionHandler
                      completionHandler:(XTLayerConnectionCompletionHandler)completionHandler;

//Network related properties
@property (nonatomic, strong) NSURLRequest *request;
@property (nonatomic, strong) NSHTTPURLResponse *response;

//Error properties
@property (nonatomic, strong) NSError *responseError;
@property (nonatomic, strong) NSError *mapperError;

//Data properties
@property (nonatomic, strong) NSData *responseData;
@property (nonatomic, strong) id parsedResponse;
@property (nonatomic, assign) BOOL isCached;

//Other properties
@property (nonatomic, copy) XTLayerConnectionCachingHandler cachingHandler;
@property (nonatomic, copy) XTLayerConnectionCompletionHandler completionHandler;
@property (nonatomic, strong) id<XTRestLayerMapperProtocol>mapper;
@property (nonatomic, assign) NSInteger numberOfAttempts;

- (void)start;
- (void)cancel;

@end
