//
//  MOFProduct+Cart.h
//  MyOrderApp
//
//  Created by Angel Garcia on 04/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFProduct.h"

@interface MOFProduct (Cart)

//Sum of all amount of items in cart with any configuration
- (NSInteger)cartAmount;

//Array of items in cart with any configuration
- (NSArray *)cartItems;

@end
