//
//  MOFMerchant.h
//  MyOrderApp
//
//  Created by Angel Garcia on 03/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
@import MapKit;

@class MOFMedia;
@class MOFFulfillmentMethod;
@class MOFCategory;
@class MOFMerchantType;
@class MOFAddress;

@interface MOFMerchant : MOFModelObject

@property (nonatomic, strong) NSString * identifier;

@property (nonatomic, strong) MOFAddress *address;
@property (nonatomic, strong) NSString *detail;
@property (nonatomic, strong) NSString *externalId;
@property (nonatomic, strong) NSDictionary *extraInfo;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *numberOfProductsOnSale;
@property (nonatomic, strong) NSString *phoneNumber;
@property (nonatomic, strong) NSString *website;
@property (nonatomic, strong) NSOrderedSet *categories;
@property (nonatomic, strong) NSOrderedSet *products;

@property (nonatomic, strong) NSNumber *typeId;
@property (nonatomic, strong) NSOrderedSet *medias;
@property (nonatomic, strong) NSOrderedSet *fulfillmentMethods;
@property (nonatomic, strong) NSOrderedSet *schedules;

@end


@interface MOFMerchant (Relations)<MKAnnotation>

@property (nonatomic, weak)   MOFMerchantType *type;
@property (nonatomic, readonly) NSArray *allCategories;
@property (nonatomic, readonly) NSArray *allProducts;
@property (nonatomic, readonly) NSArray *allProductsOnSale;

- (MOFMedia *)mediaWithType:(NSString *)type;
- (MOFFulfillmentMethod *)fulfillmentMethodWithType:(NSString *)type;

@end


@interface MOFMerchant (ExtraInfo)

@property (nonatomic, readonly) NSNumber *isOpen;
@property (nonatomic, readonly) NSNumber *isNationWide;
@property (nonatomic, readonly) NSNumber *checkingCount;
@property (nonatomic, readonly) NSNumber *couponsCount;
@property (nonatomic, readonly) NSString *preOrderMessage;
@property (nonatomic, readonly) NSString *postOrderMessage;

@end