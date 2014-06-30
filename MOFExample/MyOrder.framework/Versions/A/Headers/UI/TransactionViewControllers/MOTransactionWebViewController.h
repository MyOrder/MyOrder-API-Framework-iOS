//
//  MOTransactionWebViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/30/13.
//
//

#import <UIKit/UIKit.h>
@class MOTransaction;

@interface MOTransactionWebViewController : UIViewController <UIWebViewDelegate>

@property (nonatomic, strong) MOTransaction *transaction;
@property (nonatomic, strong) UIWebView *webView;
@property (nonatomic, strong) NSString *url;


//TODO: Or delegates would be better?
@property (nonatomic, copy) void (^completionBlock)(MOTransactionWebViewController *controller);

@end
