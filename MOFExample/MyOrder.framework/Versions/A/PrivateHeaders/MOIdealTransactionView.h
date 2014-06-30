//
//  MOIdealTransactionView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/30/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTransactionView.h"
#import "MOIdealTransaction.h"

@interface MOIdealTransactionView : MOTransactionView

@property (nonatomic, strong, readonly) MOIdealTransaction *transaction;
@property (nonatomic, copy) dispatch_block_t onIssuerChange;

@end
