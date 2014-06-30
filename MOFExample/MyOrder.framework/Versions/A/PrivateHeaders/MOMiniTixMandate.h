//
//  MOMiniTixMandate.h
//  MyOrder
//
//  Created by Angel Garcia on 05/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

@class MOMiniTixMandate;

typedef void(^MOMandateBlock)(MOMiniTixMandate *mandate);

@interface MOMiniTixMandate : NSObject

@property (nonatomic, strong) NSString *resultCode;
@property (nonatomic, strong) NSString *requestId;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *confirmationCode;

@property (readonly) BOOL requiresConfirmation;

/**
 Loads a mandate for an automatic payment or reload of wallet. It requires bank account and returns the mandate text and request id
 @param bankAccount IBAN bank account
 @param isOTA Bool indicating whether the operation will be part of an OTA transaction or an automatic charge of wallet
 @param block Block executed when the load finishes successfully. Includes the retrieved mandate
 @param errorBlock Block executed when an error occurs
 */
+ (void)loadMiniTixMandateForBankAccount:(NSString *)bankAccount isOTA:(BOOL)isOTA onSuccess:(MOMandateBlock)block error:(MOErrorBlock)errorBlock;


@end
