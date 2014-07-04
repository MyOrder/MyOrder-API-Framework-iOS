//
//  UIImageView+MOAppearance.h
//  MyOrder
//
//  Created by Angel Garcia on 5/30/13.
//
//

#import <UIKit/UIKit.h>

@interface UIImageView (MOAppearance)

- (void)MO_setImageWithURL:(NSURL *)url onCompletion:(dispatch_block_t)completionBlock;

@end
