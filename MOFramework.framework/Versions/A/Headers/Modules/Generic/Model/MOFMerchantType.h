//
//  MOFMerchantType.h
//  MyOrderApp
//
//  Created by Angel Garcia on 13/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

static const NSString *kMOFMerchantTypeShop = @"shop";
static const NSString *kMOFMerchantTypeCinema = @"cinema";
static const NSString *kMOFMerchantTypeEvents = @"events";
static const NSString *kMOFMerchantTypeOffers = @"offers";
static const NSString *kMOFMerchantTypeParking = @"parking";
static const NSString *kMOFMerchantTypeThuisAfgehaald = @"thuisafgehaald";
static const NSString *kMOFMerchantTypeThuisBezorgd = @"thuisbezorgd";

@interface MOFMerchantType : MOFModelObject

@property (nonatomic, strong) NSNumber * identifier;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * image;
@property (nonatomic, strong) NSNumber * userOrder;
@property (nonatomic, strong) NSNumber * displayOrder;
@property (nonatomic, strong) NSNumber * count;
@property (nonatomic, strong) NSString * messageTitle;
@property (nonatomic, strong) NSString * messageBody;
@property (nonatomic, strong) NSNumber * singleProduct;
@property (nonatomic, strong) NSString * tag;

@end
