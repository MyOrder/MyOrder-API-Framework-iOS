//
//  MOFGenericNetworkingMapper.h
//  Core
//
//  Created by Angel Garcia on 14/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import "XTRestLayerMapperBase.h"

@protocol MOFNetworkingMappingProtocol;

@interface MOFGenericNetworkingMapper : XTRestLayerMapperBase

@property (nonatomic, strong) Class<MOFNetworkingMappingProtocol> modelClass;
@property (nonatomic, strong) NSString *rootPath;
@property (nonatomic, strong) NSArray *objectsToDelete;

@property (nonatomic, readonly, assign) NSInteger totalResults;

@end
