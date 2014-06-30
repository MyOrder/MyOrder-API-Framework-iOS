//
//  MOMinitixTableViewCell.h
//  MyOrder
//
//  Created by Angel Garcia on 20/03/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOMinitixTableViewCell : UITableViewCell

- (void)setWalletAmount:(NSNumber *)walletAmount;

+ (CGFloat)heightOfCell;

@end
