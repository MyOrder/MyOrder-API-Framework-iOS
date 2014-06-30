//
//  XTSessionRestLayerConnection.h
//  XTRestLayerDemo
//
//  Created by Angel Garcia on 17/06/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "XTRestLayerConnection.h"

@interface XTSessionRestLayerConnection : XTRestLayerConnection

+ (NSURLSession *)sharedSession;
+ (void)setSharedSession:(NSURLSession *)session;

@property (nonatomic, strong) NSURLSessionTask *sessionTask;

@end
