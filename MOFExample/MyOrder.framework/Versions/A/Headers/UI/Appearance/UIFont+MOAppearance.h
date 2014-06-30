//
//  UIFont+MOAppearance.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

/** This category allows third party developers to customize fonts inside the MyOrder library */
@interface UIFont (MOAppearance)


/**
 @name Customizable font setters
 */

/**
 Changes the main font used by regular labels in the library
 @param fontName Font to use on regular labels. Nil for returning to default
 */
+ (void)MO_setFontName:(NSString *)fontName;

/**
 Changes the main font used by bold labels in the library
 @param fontName Font to use on bold labels. Nil for returning to default
 */
+ (void)MO_setBoldFontName:(NSString *)fontName;

/**
 Changes the main font used by semi-bold labels in the library
 @param fontName Font to use on semi-bold labels. Nil for returning to default
 */
+ (void)MO_setMediumFontName:(NSString *)fontName;


//Getters
+ (UIFont *)MO_fontOfSize:(CGFloat)size;
+ (UIFont *)MO_boldFontOfSize:(CGFloat)size;
+ (UIFont *)MO_mediumFontOfSize:(CGFloat)size;

@end
