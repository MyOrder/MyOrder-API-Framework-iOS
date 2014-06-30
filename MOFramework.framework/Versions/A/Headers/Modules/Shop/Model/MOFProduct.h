//
//  MOFProduct.h
//  MyOrderApp
//
//  Created by Angel Garcia on 04/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFCategory;
@class MOFMerchant;
@class MOFMerchantType;

@interface MOFProduct : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * details;
@property (nonatomic, strong) NSNumber * active;
@property (nonatomic, strong) NSString * externalId;
@property (nonatomic, strong) NSDictionary *extraInfo;
@property (nonatomic, strong) NSOrderedSet *medias;
@property (nonatomic, strong) NSOrderedSet *options;
@property (nonatomic, strong) NSNumber * retailPrice;
@property (nonatomic, strong) NSNumber * salePrice;
@property (nonatomic, strong) NSString * shortName;
@property (nonatomic, strong) NSString *categoryId;
@property (nonatomic, strong) NSString *merchantId;
@property (nonatomic, strong) NSNumber *typeId;

@end

@interface MOFProduct (Utils)
- (BOOL)hasVariablePrice;
- (CGFloat)minimumPrice;
- (CGFloat)maximumPrice;
@end

@interface MOFProduct (Relations)

@property (nonatomic, weak) MOFMerchantType *type;
@property (nonatomic, weak) MOFMerchant *merchant;
@property (nonatomic, weak) MOFCategory *category;
@property (nonatomic, readonly) NSNumber *onSale;

@end


@interface MOFProduct (ExtraInfo)

@property (nonatomic, readonly) NSString *videoUrl;
@property (nonatomic, readonly) NSString *externalUrl;
@property (nonatomic, readonly) NSNumber *allowExport;
@property (nonatomic, readonly) NSString *extraLines;
@property (nonatomic, readonly) NSString *extraDescription;

@end