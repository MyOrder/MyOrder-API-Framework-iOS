//
//  MOIdealTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MOApiConnection.h"
#import "MOOrder.h"

@protocol MOTransactionProtocol;

typedef void(^MOPluginBlock)(id<MOTransactionProtocol>plugin);
typedef void(^MOPluginErrorBlock)(id<MOTransactionProtocol>plugin, NSError *error);

typedef enum {
    MOTransactionStatusNotStarted,
    MOTransactionStatusInProgress,
    MOTransactionStatusConfirmed,
    MOTransactionStatusCanceled,
    MOTransactionStatusFinished,
    MOTransactionStatusError,
} MOTransactionStatus;


/**
 Consts used for the transaction info key
 */
extern const NSString *MOTransactionProviderName;
extern const NSString *MOTransactionCanBeOpen;
extern const NSString *MOTransactionAllowsWalletOperation;
extern const NSString *MOTransactionAllowsOrderOperation;
extern const NSString *MOTransactionPriority;
extern const NSString *MOTransactionProviderDescription;



@protocol MOTransactionProtocol <NSObject>

/**
 Returns the transaction info dictionary
 @return dictionary with provider information (name, description, allows wallet,...)
 */
+ (NSDictionary *)info;

/**
 Returns the transaction provider name
 @return string with provider name (ex: PayPal)
 */
+ (NSString *)providerName;


/**
 Confirms the transaction in the two phase payment methods
 */
- (void)confirm;

/**
 Cancels the transaction in any moment
 */
- (void)cancel;

/**
 Retrieves the current state
 @return status of the transaction
 */
- (MOTransactionStatus)status;

/**
 Start payment transaction to fill your wallet. (ChargeXXX)
 @param confirmationBlock Block that will be called on intermediate process (confirmation)
 @param block Sucess Block
 @param errorBlock Error Block
 */
- (void)fillWalletOnConfirmation:(MOPluginBlock)confirmationBlock onSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/**
 Start payment transaction with MOOrder object to make a payment (placeOrder)
 @param confirmationBlock Block that will be called on intermediate process (confirmation)
 @param block Sucess Block
 @param errorBlock Error Block
 */
- (void)placeOrderOnConfirmation:(MOPluginBlock)confirmationBlock onSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/**
 Returns a BOOL indicating if the URL has been handled by the transaction. By default returns NO.
 @param url NSURL to handle.
 @returns BOOL YES if the URL has been handled
 */
- (BOOL)handleURL:(NSURL *)url;


@end


/** Generic transaction */
@interface MOTransaction : NSObject<MOTransactionProtocol>

/**
 The ammount to charge in a wallet operation in euros
 */
@property (nonatomic, assign) double walletAmmount;

/**
 MOOrder to use for placing order. Required when placeOrder method called
 */
@property (nonatomic, strong) MOOrder *order;

/** Description to use in the receipt details. Only used by some transactions (iDeal) */
@property (nonatomic, strong) NSString *description;


@end
