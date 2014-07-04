//
//  MOPasswordChangeView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/28/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTextField.h"
@interface MOPasswordChangeView : UIView

@property (nonatomic, strong, readonly) MOTextField *passwordTextField;
@property (nonatomic, strong, readonly) MOTextField *confirmationTextField;
@property (nonatomic, strong, readonly) MOTextField *emailTextField;
@property (nonatomic, strong, readonly) UISwitch *rememberSwitch;

@end
