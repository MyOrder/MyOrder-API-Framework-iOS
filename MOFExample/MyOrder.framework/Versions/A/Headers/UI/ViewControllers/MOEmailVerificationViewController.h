//
//  MOEmailVerificationViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/30/13.
//
//

#import <UIKit/UIKit.h>

@interface MOEmailVerificationViewController : UIViewController

@property (nonatomic, copy) void (^completionBlock)(MOEmailVerificationViewController *controller, BOOL verified);

@end
