//
//  MOFProductOption.h
//  MyOrderApp
//
//  Created by Angel Garcia on 23/12/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"

@interface MOFProductOption : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSNumber * minimum;
@property (nonatomic, strong) NSNumber * maximum;
@property (nonatomic, strong) NSOrderedSet *values;

@end
