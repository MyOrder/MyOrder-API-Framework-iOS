//
//  MOHeaderView.h
//  MyOrder
//
//  Created by Angel Garcia on 06/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOHeaderView : UIView

@property (readonly) UILabel *label;

- (id)initWithWidth:(CGFloat)width title:(NSString *)title;

@end
