//
//  MOFCategory.h
//  MyOrderApp
//
//  Created by Angel Garcia on 03/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"

@class MOFCategory, MOFMerchant, MOFProduct;

@interface MOFCategory : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * details;
@property (nonatomic, strong) NSNumber * active;
@property (nonatomic, strong) NSString * externalId;
@property (nonatomic, strong) NSDictionary *extraInfo;

@property (nonatomic, strong) NSNumber * numberOfProducts;
@property (nonatomic, strong) NSNumber * numberOfProductsOnSale;
@property (nonatomic, strong) NSString * shortName;
@property (nonatomic, strong) NSNumber * totalProducts;
@property (nonatomic, strong) NSString * url;
@property (nonatomic, strong) NSOrderedSet *subcategories;
@property (nonatomic, strong) NSOrderedSet *products;
@property (nonatomic, strong) NSOrderedSet *medias;

@property (nonatomic, strong) NSString * parentId;
@property (nonatomic, strong) NSString * merchantId;
@end


@interface MOFCategory (Relations)

@property (nonatomic, weak) MOFMerchant *merchant;
@property (nonatomic, weak) MOFCategory *parent;
@property (nonatomic, readonly) NSArray *allSubcategories;
@property (nonatomic, readonly) NSArray *allProducts;
@property (nonatomic, readonly) NSArray *allProductsOnSale;

@end


@interface MOFCategory (ExtraInfo)

@property (nonatomic, readonly) NSString *videoUrl;
@property (nonatomic, readonly) NSString *extraDescription;
@property (nonatomic, readonly) NSString *extraLines;
@property (nonatomic, readonly) NSString *extraAges;

@end
