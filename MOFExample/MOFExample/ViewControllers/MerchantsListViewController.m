//
//  MerchantsListViewController.m
//  MOFExample
//
//  Created by Angel Garcia on 27/06/14.
//  Copyright (c) 2014 MyOrder. All rights reserved.
//

#import "MerchantsListViewController.h"
#import <MOFramework/MOFramework.h>
#import <MOFramework/Modules/Shop/MOFShop.h>
#import <MOFramework/Modules/Generic/MOFGeneric.h>

@interface MerchantsListViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) NSArray *merchants;
@end

@implementation MerchantsListViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self loadAllMerchants];
}

- (void)loadAllMerchants {
    [[MOFShopDAO sharedInstance] loadMerchantsWithTypes:nil
                                               location:kCLLocationCoordinate2DInvalid
                                                   term:nil
                                              animation:MOFNetworkAnimationHUD
                                               onResult:^(NSArray *results) {
                                                   self.merchants = results;
                                                   [self.tableView reloadData];
                                               } onError:^(NSError *error) {
                                                   NSLog(@"An error happened fetching merchants: %@", [error localizedDescription]);
                                               }];
}


#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.merchants count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    MOFMerchant *merchant = self.merchants[indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"merchantCell" forIndexPath:indexPath];
    cell.textLabel.text = merchant.name;
    cell.detailTextLabel.text = [merchant.address description];
    return cell;
}



#pragma mark - Navigation

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    NSIndexPath *path = [self.tableView indexPathForSelectedRow];
    MOFMerchant *merchant = self.merchants[path.row];
    [segue.destinationViewController setMerchant:merchant];
}


@end
