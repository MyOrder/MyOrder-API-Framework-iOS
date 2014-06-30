//
//  MOFMultiModelNetworkingMapper.h
//  MyOrderApp
//
//  Created by Angel Garcia on 02/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFGenericNetworkingMapper.h"

@interface MOFMultiModelNetworkingMapper : MOFGenericNetworkingMapper

@property (nonatomic, strong) NSDictionary *modelClasses;

- (id)initWithModelClasses:(NSDictionary *)modelClasses;

@end
