//
//  MOAutomaticChargeOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 06/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOPaymentOperation.h"

@interface MOAutomaticChargeOperation : MOPaymentOperation

@property (nonatomic, strong) NSString *bankAccount;
@property (nonatomic, assign) BOOL active;
@property (nonatomic, strong) NSString *period;
@property (nonatomic, strong) NSNumber *amount;

@property (readonly) BOOL requiresConfirmation;
@property (readonly) NSString *confirmationRequestId;

@end
