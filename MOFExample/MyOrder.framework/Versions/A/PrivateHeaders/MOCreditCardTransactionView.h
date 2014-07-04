//
//  MOCreditCardTransactionView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/30/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTransactionView.h"
#import "MOCreditCardTransaction.h"

@interface MOCreditCardTransactionView : MOTransactionView

@property (nonatomic, strong, readonly) MOCreditCardTransaction *transaction;

@property (nonatomic, copy) dispatch_block_t onCardReader;
@property (nonatomic, copy) dispatch_block_t onSavedCardUse;

@property (nonatomic, assign) BOOL enableCardReader;

@property (nonatomic, strong) MOTextField *numberTextField;
@property (nonatomic, strong) MOTextField *expirationTextField;
@property (nonatomic, strong) MOTextField *cvcTextField;

- (void)configureWithNumber:(NSString *)number expiration:(NSString *)expiration cvc:(NSString *)cvc;
- (void)configureWithSavedAlias:(NSString *)alias selected:(BOOL)selected;

@end
