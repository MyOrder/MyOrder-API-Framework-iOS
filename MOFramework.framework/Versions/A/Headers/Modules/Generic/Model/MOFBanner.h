//
//  MOFBanner.h
//  MyOrderApp
//
//  Created by Angel Garcia on 01/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"
@class MOFMerchant;

@interface MOFBanner : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSNumber * active;
@property (nonatomic, strong) NSNumber * minAmount;
@property (nonatomic, strong) NSNumber * maxAmount;
@property (nonatomic, strong) NSDate * fromDate;
@property (nonatomic, strong) NSDate * tillDate;
@property (nonatomic, strong) NSNumber * credits;
@property (nonatomic, strong) NSNumber * discountAmount;
@property (nonatomic, strong) NSNumber * usePercentageAsDiscount;
@property (nonatomic, strong) NSNumber * allowExport;
@property (nonatomic, strong) NSString * merchantId;
@property (nonatomic, strong) NSString * imageURL;
@property (nonatomic, strong) NSOrderedSet *products;

@end

@interface MOFBanner (Relations)

@property (nonatomic, weak) MOFMerchant *merchant;

@end
