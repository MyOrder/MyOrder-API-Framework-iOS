//
//  XTRestLayerConnection.h
//  XTRestLayerDemo
//
//  Created by Berik Visschers on 2013-02-25.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XTRestLayerProtocols.h"
#import "XTRestLayerTypes.h"

@interface XTRestLayerConnection : NSObject <XTRestLayerConnectionProtocol>

@property (nonatomic, strong) NSOperationQueue *queue;

- (void)processResponse;

@end
