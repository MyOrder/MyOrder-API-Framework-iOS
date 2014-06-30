//
//  MOPayPalTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** Paypal transaction */
@interface MOPayPalTransaction : MOTransaction

/** Preapproval key issued by MyOrder */
@property (nonatomic, strong) NSString *preapprovalKey;

/** Confirmation key from the PayPal SDK */
@property (nonatomic, strong) NSString *confirmationKey;

@end
