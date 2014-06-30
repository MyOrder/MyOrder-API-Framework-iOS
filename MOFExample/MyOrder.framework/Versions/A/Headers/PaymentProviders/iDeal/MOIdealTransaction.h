//
//  MOIdealTransaction.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/23/13.
//
//

#import "MOTransaction.h"

/** iDeal transaction */
@interface MOIdealTransaction : MOTransaction

/** Return url to use on the external party service as callback */
@property (nonatomic, strong) NSString *returnUrl;

/** Issuer url to open for confirm the transaction */
@property (nonatomic, strong) NSString *issuerUrl;

/** Transaction ID */
@property (nonatomic, strong) NSString *transactionId;

/** Selected Issuer */
@property (nonatomic, strong) NSDictionary *selectedIssuer;

/** List of issuers */
@property (nonatomic, strong) NSArray *issuers;

/** Number of minutes to expire the iDeal transaction */
@property (nonatomic, strong) NSNumber *expirationMinutes;


/** Load all available issuers
 @param block Success block
 @param errorBlock Error block
 */
- (void)loadIssuersOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/** Check if the ideal transaction status
 @param block Success block
 @param errorBlock Error block
 */
- (void)checkIdealStatusOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;


/** Returns the default isssuer (last selected issuer)
 @return NSDictionary with issuer information
 */
+ (NSDictionary *)defaultIssuer;


@end
