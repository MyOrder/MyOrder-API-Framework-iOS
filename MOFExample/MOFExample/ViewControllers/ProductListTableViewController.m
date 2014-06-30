//
//  ProductListTableViewController.m
//  MOFExample
//
//  Created by Angel Garcia on 27/06/14.
//  Copyright (c) 2014 MyOrder. All rights reserved.
//

#import "ProductListTableViewController.h"
#import <MOFramework/MOFramework.h>
#import <MOFramework/Modules/Shop/MOFShop.h>

@interface ProductListTableViewController ()
@property (nonatomic, strong) NSArray *products;
@end

@implementation ProductListTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = self.merchant.name;
    [self loadProducts];
}

- (void)loadProducts {
    if (self.merchant) {
        [[MOFShopDAO sharedInstance] loadProductsWithMerchantTypes:nil
                                                         merchants:@[self.merchant]
                                                              term:nil
                                                         animation:MOFNetworkAnimationHUD
                                                          onResult:^(NSArray *products) {
                                                              self.products = products;
                                                              [self.tableView reloadData];
                                                          } onError:^(NSError *error) {
                                                              NSLog(@"An error happened fetching products: %@", [error localizedDescription]);
                                                          }];
    }
}


#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.products count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    MOFProduct *product = self.products[indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"productCell" forIndexPath:indexPath];
    cell.textLabel.text = product.name;
    return cell;
}

@end
