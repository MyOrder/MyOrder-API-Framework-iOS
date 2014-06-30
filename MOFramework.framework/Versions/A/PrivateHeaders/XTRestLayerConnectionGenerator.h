//
//  XTRestLayerConnectionGenerator.h
//  XTRestLayerDemo
//
//  Created by Berik Visschers on 2013-02-25.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XTRestLayerProtocols.h"
#import "XTRestLayerTypes.h"

@interface XTRestLayerConnectionGenerator : NSObject
+ (id<XTRestLayerConnectionProtocol>)connectionForModelObject:(id<XTRestLayerModelProtocol>)modelObject
                                                 withSelector:(SEL)selector;
@end
