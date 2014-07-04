//
//  MORegisterVerificationView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

@interface MORegisterVerificationView : UIScrollView

@property (nonatomic, strong) UIBarButtonItem *nextButtonItem;
@property (nonatomic, readonly) NSString *activationCode;

- (id)initWithPhone:(NSString *)phone;

@end
