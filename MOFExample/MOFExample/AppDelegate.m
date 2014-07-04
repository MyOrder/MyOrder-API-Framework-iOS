//
//  AppDelegate.m
//  MOFExample
//
//  Created by Angel Garcia on 27/06/14.
//  Copyright (c) 2014 MyOrder. All rights reserved.
//

#import "AppDelegate.h"

#import <MOFramework/MOFramework.h>
#import <MOFramework/Modules/Auth/MOFAuth.h>
#import <MOFramework/Modules/Shop/MOFShop.h>

#import <MyOrder/MyOrder.h>
#import <MyOrder/UI/Components/MOProgressHUD.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // MyOrder SDK setup
    MyOrder *myOrder = [MyOrder shared];
    myOrder.apiKey = @"36bd8913-bf56-4aa0-9492-49a3240597ea";
    myOrder.apiSecret = @"12H@c9kT$At";
    myOrder.URLScheme = @"mof-example";
    myOrder.environment = MyOrderEnvironmentPlayground;
    [myOrder configureWithPaymentProviders:@[@"MiniTix", @"iDeal", @"Card", @"OTA"]];   //We do not support credit card or Paypal in this example
    
    //MOFramework setup
    [MOFNetworkConnection setBaseUrl:@"http://playground-java.myorder.nl/api/v1/"];
    [MOFNetworkConnection setAnimationHandler:^(MOFNetworkConnection *connection, MOFNetworkAnimationStatus status) {
        switch (status) {
            case MOFNetworkAnimationStatusStart:
                if (connection.animation == MOFNetworkAnimationHUD || connection.animation == MOFNetworkAnimationHUDWithConfirmation) {
                    [MOProgressHUD show];
                }
                break;
                
            case MOFNetworkAnimationStatusError:
                [MOProgressHUD showError:connection.mapperError];
                break;
                
            case MOFNetworkAnimationStatusSuccess:
                if (connection.animation == MOFNetworkAnimationHUDWithConfirmation) {
                    [MOProgressHUD showSuccessWithStatus:connection.successMessage];
                }
                else {
                    [MOProgressHUD dismiss];
                }
                break;
        }
    }];
    
    //Instantiate desired modules. For this demo only the following:
    [MOFAuthDAO instantiate];
    [MOFShopDAO instantiate];
    
    return YES;
}

// Handle the iDeal redirects
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    return [[MyOrder shared] handleURL:url];
}


@end
