//
//  MOFProductOptionValue.h
//  MyOrderApp
//
//  Created by Angel Garcia on 23/12/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"

@class MOFProductOption;

@interface MOFProductOptionValue : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSNumber * priceAdjustment;
@property (nonatomic, strong) NSOrderedSet *medias;
@property (nonatomic, strong) NSString *optionId;

@end

@interface MOFProductOptionValue (Relations)

@property (nonatomic, weak) MOFProductOption *option;

@end