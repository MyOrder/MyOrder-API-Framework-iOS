//
//  MOViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 7/4/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOViewController : UIViewController

@property(nonatomic, assign) BOOL requiresLogin;

- (void)handleError:(NSError *)error;
- (void)presentLoginController:(BOOL)animated;


@end
