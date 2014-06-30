//
//  MOOtaTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** One Time Authorization transaction. This type of transaction requires a valid email and a previously issued iDeal transaction */
@interface MOOtaTransaction : MOTransaction

/** IBAN number filled in by the user */
@property (nonatomic, strong) NSString *iban;

/** Confirmation code received by SMS */
@property (nonatomic, strong) NSString *confirmationCode;

/** Request ID */
@property (nonatomic, strong) NSString *requestId;

/** Check if the OTA module is valid for the logged in user
 @param block Success block (OTA is valid)
 @param errorBlock Error block (OTA not valid)
 */
- (void)checkAllowanceOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

@end
