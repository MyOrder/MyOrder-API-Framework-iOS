//
//  MOLoginView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

typedef void(^MOLoginBlock)(NSString *phone, NSString *password, BOOL saveCredentials);
typedef void(^MORegisterBlock)(NSString *phone);

@interface MOLoginView : UIScrollView

- (id)initWithPhone:(NSString *)phone;

@property (nonatomic, copy) MOLoginBlock onLogin;
@property (nonatomic, copy) MORegisterBlock onRegister;

@end
