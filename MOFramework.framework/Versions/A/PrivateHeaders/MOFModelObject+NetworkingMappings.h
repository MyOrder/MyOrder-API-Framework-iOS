//
//  MOFModelObject+NetworkingMappings.h
//  MyOrderApp
//
//  Created by Angel Garcia on 11/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"
#import "MOFNetworkingMappingProtocol.h"

@interface MOFModelObject (NetworkingMappings) <MOFNetworkingMappingProtocol>

+ (NSString *)identifierKey;

@end
