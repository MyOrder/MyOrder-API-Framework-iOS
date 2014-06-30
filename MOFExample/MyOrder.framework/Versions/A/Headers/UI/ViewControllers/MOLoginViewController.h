//
//  MOLoginViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

/** Login controller. Presents a login screen with remember and registration options */
@interface MOLoginViewController : UIViewController

/** If YES, tries to login the user automatically with saved credentials. Default YES */
@property (nonatomic, assign) BOOL allowAutomaticLogin;

/** Completion block called when login is completed */
@property (nonatomic, copy) void (^completionBlock)(MOLoginViewController *controller);

@end
