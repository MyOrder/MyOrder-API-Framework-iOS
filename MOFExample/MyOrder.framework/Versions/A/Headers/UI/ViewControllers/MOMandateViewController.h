//
//  MOMandateViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 07/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOMiniTixMandate.h"

@interface MOMandateViewController : UIViewController

@property (nonatomic, strong) MOMiniTixMandate *mandate;

@property (nonatomic, copy) void (^acceptBlock)(MOMandateViewController *controller);

@end
