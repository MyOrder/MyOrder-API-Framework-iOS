//
//  MOPasswordVerificationView.h
//  MyOrder
//
//  Created by Angel Garcia on 9/6/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^MOPasswordVerificationBlock)(NSString *activationCode, NSString *password);

@interface MOPasswordVerificationView : UIScrollView

- (id)initWithPhone:(NSString *)phone;

@property (nonatomic, copy) MOPasswordVerificationBlock onConfirm;

@end
