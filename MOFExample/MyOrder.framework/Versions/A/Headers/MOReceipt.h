//
//  MOReceipt.h
//  MyOrder
//
//  Created by Angel Garcia on 10/03/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    MOReceiptStatusSuccess,
    MOReceiptStatusPending,
    MOReceiptStatusOnHold,
    MOReceiptStatusError,
    MOReceiptStatusInvalid,
    MOReceiptStatusUndefined
} MOReceiptStatus;

@interface MOReceipt : NSObject

@property (nonatomic, strong) NSString *orderId;
@property (nonatomic, strong) NSArray *fields;
@property (nonatomic, strong) NSDate *creationDate;
@property (nonatomic, strong) NSString *merchantName;
@property (nonatomic, strong) NSString *socialMessage;

@property (nonatomic, assign) NSInteger statusCode;
@property (nonatomic, strong) NSString *statusDescription;
@property (nonatomic, assign) MOReceiptStatus status;

@property (nonatomic, strong) NSArray *products;

- (id)initWithData:(NSDictionary *)data;

@end


@interface MOReceiptProduct : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *details;
@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, assign) double price;

- (id)initWithData:(NSDictionary *)data;

@end