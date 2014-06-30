//
//  MOCreditCardCheck.h
//  MyOrder
//
//  Created by Taras Kalapun on 29/08/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOCreditCardCheck : NSObject

+ (NSString *)reformatCardNumber:(NSString *)number;
+ (NSString *)reformatExpDate:(NSString *)expDate;
+ (NSString *)reformatCVCNumber:(NSString *)cvcNumber;

+ (BOOL)checkCreditCardNumber:(NSString *)number expDate:(NSString *)expDate cvcNumber:(NSString *)cvcNumber;


@end
