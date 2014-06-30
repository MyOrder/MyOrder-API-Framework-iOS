//
//  MOFOrder.h
//  MyOrderApp
//
//  Created by Angel Garcia on 03/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFOrderItem;
@class MOFProduct;
@class MOFMerchant;

@interface MOFOrder : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSNumber * deliveryAmount;
@property (nonatomic, strong) NSNumber * discountAmount;
@property (nonatomic, strong) NSOrderedSet *fulfillmentMethods;
@property (nonatomic, strong) NSString * merchantId;
@property (nonatomic, strong) NSString * orderNumber;
@property (nonatomic, strong) NSString * status;
@property (nonatomic, strong) NSNumber * totalAmount;
@property (nonatomic, strong) NSString * externalId;
@property (nonatomic, strong) NSString * externalStatusId;
@property (nonatomic, strong) NSOrderedSet *orderItems;

@end



@interface MOFOrder (Relations)


@property (nonatomic, strong) MOFMerchant *merchant;

- (NSInteger)amountOfProducts;
- (NSInteger)amountForProduct:(MOFProduct *)product;

- (NSArray *)itemsForProduct:(MOFProduct *)product;
- (MOFOrderItem *)itemForProduct:(MOFProduct *)product andOptions:(NSCountedSet *)options;

@end

