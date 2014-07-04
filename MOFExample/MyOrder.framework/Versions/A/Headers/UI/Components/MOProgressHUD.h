//
//  MOProgressHUD.h
//  MyOrder
//
//  Created by Angel Garcia on 26/03/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOProgressHUD : NSObject


/**
 Set a custom handler for showing the HUD indicator. Use if custom HUD needed
 @param handler Block executed to display the HUD
 */
+ (void)setShowHandler:(dispatch_block_t)handler;

/**
 Set a custom handler for showing the HUD indicator in case of error. Use if custom HUD needed
 @param handler Block executed to display the error in the HUD
 */
+ (void)setShowErrorHandler:(void(^)(NSString *))handler;

/**
 Set a custom handler for showing the HUD indicator in case of success. Use if custom HUD needed
 @param handler Block executed to display the success message in the HUD
 */
+ (void)setShowSuccessHandler:(void(^)(NSString *))handler;

/**
 Set a custom handler for dismissing the HUD indicator. Use if custom HUD needed
 @param handler Block executed to dismiss the HUD
 */
+ (void)setDismissHandler:(dispatch_block_t)handler;


+ (void)show;
+ (void)showSuccessWithStatus:(NSString*)string;
+ (void)showError:(NSError *)error;
+ (void)showErrorWithStatus:(NSString *)error;
+ (void)dismiss;

@end
