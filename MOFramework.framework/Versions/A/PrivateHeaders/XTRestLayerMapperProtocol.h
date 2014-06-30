//
//  XTRestLayerMapperProtocol.h
//  XTRestLayerDemo
//
//  Created by Berik Visschers on 2013-02-25.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XTRestLayerTypes.h"

@protocol XTRestLayerMapperProtocol <NSObject>

- (void)mapDataFromConnection:(id<XTRestLayerConnectionProtocol>)connection completionHandler:(XTLayerMapperCompletionHandler)completionHandler;

@end
