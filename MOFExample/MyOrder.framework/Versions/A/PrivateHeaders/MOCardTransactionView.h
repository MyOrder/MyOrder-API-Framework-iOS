//
//  MOCardTransactionView.h
//  MyOrder
//
//  Created by Angel Garcia on 6/3/13.
//
//

#import "MOTransactionView.h"
#import "MOCardTransaction.h"

@interface MOCardTransactionView : MOTransactionView

@property(nonatomic, strong, readonly) MOCardTransaction *transaction;

@end
