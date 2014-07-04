//
//  MOInputAccessoryView.h
//  MyOrder
//
//  Created by Angel Garcia on 6/5/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOInputAccessoryView : UIView

+ (MOInputAccessoryView *)inputAccessoryViewForTextField:(UITextField *)textfield;
- (id)initWithTextField:(UITextField *)textfield;

@end
