//
//  MOEmailVerificationView.h
//  MyOrder
//
//  Created by Angel Garcia on 27/11/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    MOEmailVerificationViewStatusVerify,
    MOEmailVerificationViewStatusConfirm
} MOEmailVerificationViewStatus;

typedef void(^MOEmailVerificationBlock)(NSString *email, NSString *code);

@interface MOEmailVerificationView : UIScrollView

@property (nonatomic, assign) MOEmailVerificationViewStatus status;
@property (nonatomic, copy) MOEmailVerificationBlock verifyBlock;
@property (nonatomic, copy) MOEmailVerificationBlock confirmBlock;

- (id)initWithEmail:(NSString *)email;

@end
