//
//  MOFParkingSession.h
//  MyOrderApp
//
//  Created by Angel Garcia on 13/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"

@class MOFParkingPoint;

@interface MOFParkingSession : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * address;
@property (nonatomic, strong) NSDate * endTime;
@property (nonatomic, strong) NSString * licensePlate;
@property (nonatomic, strong) NSString * pointId;
@property (nonatomic, strong) NSNumber * price;
@property (nonatomic, strong) NSDate * startTime;
@property (nonatomic, strong) NSNumber * status;
@property (nonatomic, strong) NSNumber * transactionPrice;
@property (nonatomic, strong) MOFParkingPoint *point;

@end
