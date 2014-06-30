//
//  MOMiniTixAccount.h
//  MyOrder
//
//  Created by Angel Garcia on 25/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** Constant with the possible values of periods **/
extern NSString * const kMOMiniTixAccountPeriodMonth;
extern NSString * const kMOMiniTixAccountPeriodWeek;

typedef void(^MOMiniTixConfirmationBlock)(NSInteger code, NSString *updatedRequestId);


@interface MOMiniTixAccount : NSObject

@property (nonatomic, strong) NSString *bankAccountNumber;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *IBAN;
@property (nonatomic, strong) NSString *BIC;
@property (nonatomic, strong) NSNumber *autoCharge;
@property (nonatomic, strong) NSNumber *autoChargeAllowed;
@property (nonatomic, strong) NSNumber *autoChargeAmount;
@property (nonatomic, strong) NSNumber *autoChargeAuthorizationSend;
@property (nonatomic, strong) NSNumber *autoChargeBlocked;
@property (nonatomic, strong) NSNumber *autoChargeContractActive;
@property (nonatomic, strong) NSNumber *autoChargePending;
@property (nonatomic, strong) NSString *autoChargePeriod;

/**
 Returns the last loaded MiniTix account
 @return MOMiniTixAccount loaded by updateMiniTixAccountOnSuccess:error:
 */
+ (MOMiniTixAccount *)account;


/**
 Updates the MiniTix acccount settings of the user
 @param block Block executed when the update finishes successfully
 @param errorBlock Block executed when an error occurs
 */
+ (void)updateMiniTixAccountOnSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;


/**
 Saves the new MiniTix account settings for the user
 @param bankAccount Full bank account linked to user. Required
 @param active Change the autocharging active state to this new value. Optional
 @param period Change the autocharging period to this new value. Optional
 @param amount Change the autocharging amount to this new value. Optional
 @param block Block executed when the update finishes successfully
 @param errorBlock Block executed when an error occurs
 */
+ (void)saveMiniTixAccountWithBank:(NSString *)bankAccount
                  autoChargeActive:(NSNumber *)active
                  autoChargePeriod:(NSString *)period
                  autoChargeAmount:(NSNumber *)amount
                         onSuccess:(MOResponseDictionaryBlock)block
                             error:(MOErrorBlock)errorBlock;


/**
 Confirms a MiniTix change
 @param requestId Request id associated to the operation
 @param code Confirmation code (SMS normally)
 @param block Block executed when the update finishes successfully
 @param errorBlock Block executed when an error occurs
 */
+ (void)confirmMiniTixOperationWithRequestId:(NSString *)requestId
                                        code:(NSString *)code
                                   onSuccess:(MOMiniTixConfirmationBlock)block
                                       error:(MOErrorBlock)errorBlock;


@end
