//
//  XTRestLayerTypes.h
//  XTRestLayerDemo
//
//  Created by Berik Visschers on 2013-02-26.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

@protocol XTRestLayerConnectionProtocol;
typedef void (^XTLayerConnectionHandler) (id<XTRestLayerConnectionProtocol> connection);
typedef NSCachedURLResponse * (^XTLayerConnectionCachingHandler) (NSURLConnection *connection, NSCachedURLResponse *cachedResponse);
typedef void (^XTLayerConnectionCompletionHandler) (id result, id<XTRestLayerConnectionProtocol> connection);
typedef void (^NSURLConnectionCompletionHandler)(NSURLResponse*, NSData*, NSError*);
typedef void (^XTLayerMapperCompletionHandler) (id results, NSError *error);
