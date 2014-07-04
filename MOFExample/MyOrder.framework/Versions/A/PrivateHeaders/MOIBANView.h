//
//  MOIBANView.h
//  MyOrder
//
//  Created by Angel Garcia on 06/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOIBANView : UIView

- (void)configureWithIBAN:(NSString *)IBAN;
- (NSString *)filledInIBAN;

@end
