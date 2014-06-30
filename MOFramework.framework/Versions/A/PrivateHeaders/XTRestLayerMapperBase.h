//
//  XTRestLayerMapper.h
//  XTRestLayerDemo
//
//  Created by Berik Visschers on 2013-02-25.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XTRestLayerProtocols.h"
#import "XTRestLayerTypes.h"

@interface XTRestLayerMapperBase : NSObject <XTRestLayerMapperProtocol>
- (Class)modelClassForPath:(NSString *)path;
@end
