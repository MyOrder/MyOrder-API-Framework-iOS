//
//  MOTransactionViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/29/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTransactionView.h"
#import "MyOrder.h"
#import "MOOrder.h"
#import "MOViewController.h"

@interface MOTransactionViewController : MOViewController

@property (nonatomic, strong) MOTransactionView *view;

/**
 Transaction attached to this controller
 */
@property (nonatomic, strong, readonly) MOTransaction *transaction;

/**
 Block called before the transaction starts. It allows the third party developer to introduce
 just in time checks or even to start a fulfilment just before moving to payment. Return YES to 
 continue. Return NO to cancel the start.
 */
@property (nonatomic, copy) BOOL (^startBlock)(MOTransactionViewController *controller);

/**
 Block called when the transaction is completed successfully
 */
@property (nonatomic, copy) void (^completionBlock)(MOTransactionViewController *controller);

/**
 Block called when the transaction is canceled
 */
@property (nonatomic, copy) void (^cancelBlock)(MOTransactionViewController *controller);

/**
 Block called when the transaction failed. Includes error.
 */
@property (nonatomic, copy) void (^errorBlock)(MOTransactionViewController *controller, NSError *error);


/**
 Injects the controller in the navigation passed. If the controller does not require a view to be presented, then it will automatically call `startProcess`
 @param navController Navigation controller to inject the controller in
 */
- (void)startInNavigationController:(UINavigationController *)navController;

/**
 Method to call when the user presses on Pay button. Call this method if you want to start the payment programatically.
 */
- (void)startProcess;


/**
 Method to call when the transaction needs to be canceled. Fires the cancelation block. Automatically called on deallocation
 */
- (void)cancelTransaction;

@end


/**
 Private methods. Do not call them. Only exposed for subclassing purposes
 */
@interface MOTransactionViewController (Private)


- (NSString *)providerName;
- (void)startProcessFillWallet;
- (void)startProcessPlaceOrder;
- (BOOL)shouldStartTransaction;
- (void)confirmTransaction;
- (void)finishedTransaction;
- (void)finishedTransactionWithError:(NSError *)error;

@end
