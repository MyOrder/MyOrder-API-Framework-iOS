//
//  MOFNetworkingMappingProtocol.h
//  Core
//
//  Created by Angel Garcia on 14/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MOFNetworkingMappingProtocol <NSObject>

+ (NSArray *)mapObjectsFromArray:(NSArray *)array;

- (void)updateWithDictionary:(NSDictionary *)dictionary;


@end
