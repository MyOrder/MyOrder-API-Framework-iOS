//
//  MOPasswordVerificationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 9/6/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOPasswordVerificationViewController : UIViewController

@property (nonatomic, copy) void (^completionBlock)(MOPasswordVerificationViewController *controller);

@end
