//
//  MOFCoupon.h
//  MyOrderApp
//
//  Created by Angel Garcia on 17/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"

@class MOFMerchant;

@interface MOFCoupon : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * details;
@property (nonatomic, strong) NSDate * startTime;
@property (nonatomic, strong) NSDate * endTime;
@property (nonatomic, strong) NSNumber * amount;
@property (nonatomic, strong) NSNumber * activationLimit;
@property (nonatomic, strong) NSNumber * activationLimitPerCustomer;
@property (nonatomic, strong) NSNumber * activationsLeft;
@property (nonatomic, strong) NSNumber * active;
@property (nonatomic, strong) NSNumber * visible;
@property (nonatomic, strong) NSString * status;
@property (nonatomic, strong) NSNumber * saved;
@property (nonatomic, strong) NSNumber * pushEnabled;
@property (nonatomic, strong) NSOrderedSet *medias;
@property (nonatomic, strong) NSString *merchantId;


@end

@interface MOFCoupon (Relations)

@property (nonatomic, weak) MOFMerchant *merchant;

@end
