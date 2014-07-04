//
//  MyOrder.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MOErrorCodes.h"
#import "MOApiConnection.h"
#import "MOTransaction.h"
#import "MOPaymentOperation.h"

@class MOTransactionViewController;
@class MOOperationViewController;

typedef void(^MOBlock)(void);
typedef void(^MOResponseDictionaryBlock)(NSDictionary *response);
typedef void(^MOResponseArrayBlock)(NSArray *response);
typedef void(^MOErrorBlock)(NSError *error);

@protocol MOTransactionProtocol;


typedef enum MyOrderEnvironment
{
    MyOrderEnvironmentNone,         // No environment set
    MyOrderEnvironmentLive,         // Live environment for production
    MyOrderEnvironmentSandbox,      // Sandbox environment for developing purposes
    MyOrderEnvironmentPlayground,      // Playground environment is a sandbox one but open for any third party with mock data
    MyOrderEnvironmentOther,         // Other environment used only for automated tests or debuging
} MyOrderEnvironment;


@interface MyOrder : NSObject

/**
 @name User defined properties
 */

/** MyOrder environment to use. Use `MyOrderEnvironmentLive` for live or `MyOrderEnvironmentSandbox` for sandbox */
@property (nonatomic, assign) MyOrderEnvironment environment;

/** MyOrder api key to use. Also known as userId */
@property (nonatomic, strong) NSString *apiKey;

/** MyOrder api secret to use. Also known as password */
@property (nonatomic, strong) NSString *apiSecret;

/** User's phone number used in all login and transaction operations */
@property (nonatomic, strong) NSString *phoneNumber;

/** Payment description to use in transaction operations that allows customization (Ex: iDeal). Defaults to app name */
@property (nonatomic, strong) NSString *defaultMerchantDescription;

/** URL Scheme used by the app. Required for some payment methods (Ex: iDeal). Defaults to nil */
@property (nonatomic, strong) NSString *URLScheme;


/**
 @name Readonly properties
 */

/** List of available payment provider names in MyOrder library */
@property (nonatomic, strong, readonly) NSArray *availablePaymentProviders;

/** List of payment provider configured by configureWithPaymentProviders: */
@property (nonatomic, strong, readonly) NSArray *configuredPaymentProviders;

/** Returns the current transaction started with newTransactionForProvider: */
@property (nonatomic, strong, readonly) id<MOTransactionProtocol> currentTransaction;

/** List of available payment operations names in MyOrder library */
@property (nonatomic, strong, readonly) NSArray *availablePaymentOperations;

/** List of payment options configured by configureWithPaymentOptions: */
@property (nonatomic, strong, readonly) NSArray *configuredPaymentOperations;


/** Returns the current balance in euros retrieved by updateBalanceOnSuccess:error:. nil if the balance has not been retrieved yet */
@property (nonatomic, strong, readonly) NSNumber *balance;

/** Returns the last receipts retrieved by updateReceiptsOnSuccess:error:. nil if the receipts have not been retrieved yet */
@property (nonatomic, strong, readonly) NSArray *receipts;


/**
 @name Generic methods
 */

/**
 @return Singleton MyOrder object.
 */
+ (MyOrder *)shared;

/**
 Customize available providers
 @param providers List of plug in names, NSString.
 */
- (void)configureWithPaymentProviders:(NSArray *)providers;

/**
 Customize available options
 @param options List of payment options names, NSString.
 */
- (void)configureWithPaymentOperations:(NSArray *)operations;


/**
 Create a new transaction for a payment provider
 @param providerName NSString of provider name.
 @returns New transaction instance
 */
- (id<MOTransactionProtocol>)newTransactionForProvider:(NSString *)providerName;


/**
 Returns the transaction information related to a particular provider
 @param providerName NSString of provider name.
 @returns NSDictionary with transaction information for the particular provider
 */
- (NSDictionary *)transactionInfoForProvider:(NSString *)providerName;

/**
 Returns the operation information related to a particular operation name
 @param operationName NSString of operation name.
 @returns NSDictionary with operation information for the particular name
 */
- (NSDictionary *)infoForOperation:(NSString *)operationName;


/**
 Returns a BOOL indicating if the URL has been handled by MyOrder. Some payment methods (like iDeal) require this method to be implemented.
 @param url NSURL received in - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation method.
 @returns BOOL YES if the URL has been handled
 */
- (BOOL)handleURL:(NSURL *)url;

@end


@interface MyOrder (UI)

/**
 Returns the transaction UIViewController related to a particular provider. If the controller is meant to be used for payments, you need to pass the MOOrder to the  vc.transaction.order, otherwise the operation will try to fill your wallet
 @param providerName NSString of provider name.
 @returns UIViewController for specific transaction
 */
- (MOTransactionViewController *)transactionViewControllerForProvider:(NSString *)providerName;


/**
 Returns the MOOperationViewController related to a particular payment operation
 @param operationName NSString of operation name.
 @returns UIViewController for specific transaction
 */
- (MOOperationViewController *)operationViewControllerForPaymentOperation:(NSString *)operationName;


/**
 Creates and returns a UIViewController with the users wallet and payment methods. Note that some payment providers can be used without login as long as the mobile phone is set
 @param forceLogin If set to YES and the user is not logged in, it will return the login controller instead
 @returns UIViewController for wallet
 */
- (UIViewController *)walletViewControllerWithLogin:(BOOL)forceLogin;

/**
 Creates and returns a UIViewController for selecting payment options for a specific order. Note that some payment providers can be used without login as long as the mobile phone is set
 @param order MOOrder with the purchase details
 @param forceLogin If set to YES and the user is not logged in, it will return the login controller instead
 @param completionBlock Block executed when the order has been payed
 @returns UIViewController for specific order purchase
 */
- (UIViewController *)paymentViewControllerForOrder:(MOOrder *)order forceLogin:(BOOL)forceLogin onCompletion:(dispatch_block_t)completionBlock;


/**
 Creates and returns a UIViewController with the receipts list of the user
 @returns UIViewController for receipts
 */
- (UIViewController *)receiptsViewController;


@end


@interface MyOrder (API)

/**
 Returns a BOOL indicating if the user has is logged in
 */
@property (nonatomic, assign, readonly) BOOL isLoggedIn;

/**
 Returns a String with the MyOrder Session Id
 */
@property (nonatomic, strong, readonly) NSString *sessionId;


/**
Returns a BOOL indicating if the user has been loggedIn before and saved his credentials for future logins. If YES, then the login can potentially be done without password.
 @returns YES if enough information for an automatic login has been previously saved.
 */
- (BOOL)hasSavedCredentials;

/**
 Logs in the user with the provided password and optionally saves the credentials in the KeyChain. Note that the mobilePhone is set as a property in MyOrder instance.
 @param password Password of the user. Pass nil to use previously stored password
 @param save If set to YES and the user is sucessfully logged in, then the password will be stored for future logins
 @param block Block executed when the login finishes successfully
 @param errorBlock Block executed when an error occurs
 */
- (void)loginWithPassword:(NSString *)password saveCredentials:(BOOL)save onSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Logs in the user with the stored credentials from a previously saved login
 @param block Block executed when the login finishes successfully 
 @param errorBlock Block executed when an error occurs
 */
- (void)loginOnSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Logs out the user and deletes saved credentials
 @param block Block executed when the logout finishes successfully 
 @param errorBlock Block executed when an error occurs
 */
- (void)logoutOnSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;


/**
 Check if the provided phone number is a register user or not
 @param block Block executed when the user exists
 @param errorBlock Block executed when user is not register or error happens
 */
- (void)userExistsOnSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Starts the registration of a new mobile phone number. The process needs to be verified with a SMS code before the account is actived with verifyRegistrationWithActivationCode:newPassword:onSuccess:error:. Note that the mobilePhone is set as a property in MyOrder instance.
 @param force BOOL indicating if the user registration can succed even if it exists
 @param block Block executed when the registration successfully finishes
 @param errorBlock Block executed when an error occurs
 @see verifyRegistrationWithActivationCode:newPassword:onSuccess:error:
 */
- (void)registerUser:(BOOL)force onSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Verifies a registered phone number started on registerOnSuccess:error: with the received SMS code and sets a new password. If the verification succeds then a login is automatically performed. Note that the mobilePhone is set as a property in MyOrder instance.
 @param activationCode SMS code received when registering
 @param password New password to set for the user's account. Pass nil if you do not want to set a password.
 @param block Block executed when the verification finishes successfully 
 @param errorBlock Block executed when an error occurs
 @see registerOnSuccess:error:
 */
- (void)verifyRegistrationWithActivationCode:(NSString *)activationCode newPassword:(NSString *)password onSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Set a new user's password. It requires user to be logged in
 @param password New password to set for the user's account
 @param block Block executed when the update finishes successfully
 @param errorBlock Block executed when an error occurs
 */
- (void)updatePassword:(NSString *)password onSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Updates the user's balance
 @param block Block executed when the update finishes successfully
 @param errorBlock Block executed when an error occurs
 */
- (void)updateBalanceOnSuccess:(MOBlock)block error:(MOErrorBlock)errorBlock;

/**
 Set a new user's email and starts the verification process. Process needs to be finished by verifyEmailWithRequestId:confirmationCode:onSuccess:error:
 @param email New email to set for the user's account
 @param block Block executed when the email verification starts successfully. Passes a dictionary with attributes for the verification process
 @param errorBlock Block executed when an error occurs
 @see verifyEmailWithRequestId:confirmationCode:onSuccess:error:
 */
- (void)startEmailVerification:(NSString *)email onSuccess:(MOResponseDictionaryBlock)block error:(MOErrorBlock)errorBlock;

/**
 Verifies the started verification process.
 @param requestId Id of the started verification process. Contained in the start `response[@"RequestId"]`
 @param confirmationCode Received confirmation code
 @param block Block executed when the email verification ends successfully
 @param errorBlock Block executed when an error occurs
 @see startEmailVerification:onSuccess:error:
 */
- (void)verifyEmailWithRequestId:(NSString *)requestId confirmationCode:(NSString *)confirmationCode onSuccess:(MOResponseDictionaryBlock)block error:(MOErrorBlock)errorBlock;

/** @name Getting transaction history */

/**
 Loads Purchase history and returns MOReceipts
 @param block Block executed when the history is loaded. Contains parsed MOReceipts
 @param errorBlock Block executed when an error occurs
 */
- (void)updateReceiptsOnSuccess:(MOResponseArrayBlock)block error:(MOErrorBlock)errorBlock;

/**
 Loads history of topping the Wallet
 @param block Block executed when the history is loaded
 @param errorBlock Block executed when an error occurs
 */
- (void)loadWalletHistoryOnSuccess:(MOResponseDictionaryBlock)block error:(MOErrorBlock)errorBlock;


+ (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)tableName NS_FORMAT_ARGUMENT(1);

@end


@interface MOApiConnection (MyOrderWrapper)
+ (MOApiConnection *)load:(NSString *)path params:(NSDictionary *)params onSuccess:(MOApiConnectionSuccessBlock)block onError:(MOApiConnectionErrorBlock)errorBlock;
@end
