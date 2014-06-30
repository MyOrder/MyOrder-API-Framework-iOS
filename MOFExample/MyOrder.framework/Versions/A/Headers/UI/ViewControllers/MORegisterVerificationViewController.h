//
//  MORegisterVerificationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

@interface MORegisterVerificationViewController : UIViewController

@property (nonatomic, copy) void (^completionBlock)(MORegisterVerificationViewController *controller);

@end
