//
//  MOOtaTransactionView.h
//  MyOrder
//
//  Created by Angel Garcia on 24/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <MyOrder/MyOrder.h>
#import "MOTransactionView.h"
#import "MOOtaTransaction.h"

@interface MOOtaTransactionView : MOTransactionView

@property (nonatomic, strong, readonly) MOOtaTransaction *transaction;
@property (nonatomic, strong) NSString *savedIban;

@end
