//
//  UIColor+MOAppearance.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>


/** This category allows third party developers to customize colors inside the MyOrder library */
@interface UIColor (MOAppearance)


/**
 @name Customizable colors setters
 */

/**
 Changes the background color of the library
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setBackgroundColor:(UIColor *)color;

/**
 Changes the section border color (textfields and groups)
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setSectionBorderColor:(UIColor *)color;

/**
 Changes the text color of textfield labels
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setTextFieldTextColor:(UIColor *)color;

/**
 Changes the background color of textfield
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setTextFieldBackgroundColor:(UIColor *)color;


/**
 Changes the background color of table cells
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setCellBackgroundColor:(UIColor *)color;

/**
 Changes the color of switch enabled state
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setSwitchOnColor:(UIColor *)color;

/**
 Changes the text color of labels on top of a background view
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setTextColor:(UIColor *)color;


/**
 Changes the background color of the buttons
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setButtonBackgroundColor:(UIColor *)color;

/**
 Changes the background color of the buttons when active (selected or highlighted)
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setButtonBackgroundActiveColor:(UIColor *)color;

/**
 Changes the background color of the buttons when disabled
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setButtonBackgroundDisabledColor:(UIColor *)color;


/**
 Changes the text color of the buttons
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setButtonTextColor:(UIColor *)color;

/**
 Changes the text color of the links to external services
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setLinkTextColor:(UIColor *)color;

/**
 Changes the color of the texts in order details when success
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setOrderSuccessColor:(UIColor *)color;

/**
 Changes the color of the texts in order details when in progress
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setOrderProgressColor:(UIColor *)color;

/**
 Changes the color of the texts in order details when fail
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setOrderErrorColor:(UIColor *)color;


// Getters
+ (UIColor *)MO_backgroundColor;
+ (UIColor *)MO_sectionBorderColor;
+ (UIColor *)MO_textFieldTextColor;
+ (UIColor *)MO_textFieldBackgroundColor;
+ (UIColor *)MO_cellBackgroundColor;
+ (UIColor *)MO_switchOnColor;
+ (UIColor *)MO_textColor;
+ (UIColor *)MO_buttonBackgroundColor;
+ (UIColor *)MO_buttonBackgroundActiveColor;
+ (UIColor *)MO_buttonBackgroundDisabledColor;
+ (UIColor *)MO_buttonTextColor;
+ (UIColor *)MO_linkTextColor;
+ (UIColor *)MO_orderSuccessColor;
+ (UIColor *)MO_orderProgressColor;
+ (UIColor *)MO_orderErrorColor;
+ (UIColor *)MO_walletColor;

@end
