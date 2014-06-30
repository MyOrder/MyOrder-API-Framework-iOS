//
//  MOTransactionView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/31/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTransaction.h"
#import "MOTextField.h"
#import "MOButton.h"

@interface MOTransactionView : UIView <UITableViewDataSource, UITableViewDelegate>

@property(nonatomic, copy) dispatch_block_t confirmationBlock;
@property (nonatomic, strong, readonly) MOTransaction *transaction;

@property (nonatomic, strong, readonly) UITableView *tableView;
@property (nonatomic, strong, readonly) MOTextField *amountTextField;
@property (nonatomic, strong, readonly) UIButton *confirmButton;

- (id)initWithTransaction:(MOTransaction *)transaction;
- (void)confirmAction:(id)sender;

@end
