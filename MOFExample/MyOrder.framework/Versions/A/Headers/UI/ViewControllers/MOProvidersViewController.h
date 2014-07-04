//
//  MOWalletTableViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>
#import "MOOrder.h"
#import "MOViewController.h"

@interface MOProvidersViewController : MOViewController <UITableViewDataSource, UITableViewDelegate>

/** MOOrder used for payments. Do not provide any for wallet operations */
@property (nonatomic, strong) MOOrder *order;

/** Completion block executed when payment/charge has been completed */
@property (nonatomic, copy) dispatch_block_t completionBlock;

/** BOOL indicating whether the provider cards should be expanded on click. Default to NO */
@property (nonatomic, assign) BOOL shouldExpandCards;

/** Main table used in the list */
@property (nonatomic, strong) IBOutlet UITableView *tableView;

/** Label indicating the price that will get updated */
@property (nonatomic, strong) IBOutlet UILabel *priceLabel;

/** Allows to add some extra sections on top of the wallet. Only useful if you want to customize the table view. Defaults to 0 */
@property (nonatomic, assign) NSInteger customSectionsOnTop;


- (id)initWithOrder:(MOOrder *)order;

/**
 Starts a payment with the selected payment method. This method is called when the user taps on a specific
 payment method, but could be called externally under some circumstances
 @param providerInfo Payment provider info
 */
- (void)payWithPaymentProvider:(NSDictionary *)providerInfo;


/**
 Starts a payment operation with the selected operation info. This method is called when the user taps on a specific
 payment operation, but could be called externally under some circumstances
 @param operationInfo Payment operation info
 */
- (void)executePaymentOperation:(NSDictionary *)operationInfo;


/**
 Open or close a payment provider card
 @param providerInfo Payment provider info
 */
- (void)togglePaymentProvider:(NSDictionary *)providerInfo;

/**
 Checks if a payment provider card is expanded or not
 @param providerInfo Payment provider info
 @return BOOL indicating if the card of the provider is expanded
 */
- (BOOL)isPaymentProviderExpanded:(NSDictionary *)providerInfo;

/**
 Configures the provider list to display by default some providers open. No provider is open by default. Sets shouldExpandCards to true if any provided
 @param paymentProviderNames Array with the provider names to be open by default
 */
+ (void)setDefaultOpenPaymentProvider:(NSArray *)paymentProviderNames;

@end
