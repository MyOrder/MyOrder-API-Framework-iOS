//
//  MORegisterViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

/** Registration controller. Presents a form for creating a new account or retrieving a forgotten password */
@interface MORegisterViewController : UIViewController

/** Completion block called when the registration is completed (and verified) */
@property (nonatomic, copy) void (^completionBlock)(MORegisterViewController *controller);

/** Bool indicating if the user is trying to remember his password. Default to NO (register new user) */
@property (nonatomic, assign) BOOL passwordForget;


@end
