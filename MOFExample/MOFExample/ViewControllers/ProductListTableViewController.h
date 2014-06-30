//
//  ProductListTableViewController.h
//  MOFExample
//
//  Created by Angel Garcia on 27/06/14.
//  Copyright (c) 2014 MyOrder. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MOFMerchant;

@interface ProductListTableViewController : UITableViewController
@property (nonatomic, strong) MOFMerchant *merchant;
@end
