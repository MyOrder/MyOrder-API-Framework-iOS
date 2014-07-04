//
//  MOReceiptItemCell.h
//  MyOrder
//
//  Created by Angel Garcia on 6/18/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MOReceiptProduct;

@interface MOReceiptItemCell : UITableViewCell

- (void)configureWithProduct:(MOReceiptProduct *)product;

@end
