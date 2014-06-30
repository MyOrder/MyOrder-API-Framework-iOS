//
//  MOPaymentMethodsCell.h
//  MyOrder
//
//  Created by Angel Garcia on 5/29/13.
//
//

#import <UIKit/UIKit.h>

typedef void(^MOPaymentMethodBlock)(NSDictionary *providerInfo);

@interface MOPaymentMethodsCell : UITableViewCell

@property (nonatomic, strong) NSDictionary *providerInfo;
@property (nonatomic, copy) MOPaymentMethodBlock onMethodSelected;
@property (nonatomic, assign) BOOL isWalletOperation;

+ (CGFloat)heightOfCell;

@end
