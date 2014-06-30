//
//  MOFOrderItem.h
//  MyOrderApp
//
//  Created by Angel Garcia on 30/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFOrder;

@interface MOFOrderItem : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSCountedSet *options;
@property (nonatomic, strong) NSString * productId;
@property (nonatomic, strong) NSNumber * quantity;
@property (nonatomic, strong) NSNumber * retailPrice;
@property (nonatomic, strong) NSNumber * salePrice;
@property (nonatomic, weak) MOFOrder *order;

@end


@class MOFProduct;

@interface MOFOrderItem (Relations)

@property (nonatomic, strong) MOFProduct *product;

@end

@interface MOFOrderItem (Utils)

- (NSString *)optionsDescription;

@end