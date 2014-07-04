//
//  MOFTickets.h
//  MyOrderApp
//
//  Created by Angel Vasa on 4/3/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFMerchant;

@interface MOFTicket : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * date;
@property (nonatomic, strong) NSNumber * isUsed;
@property (nonatomic, strong) NSString * merchantId;
@property (nonatomic, strong) NSString * merchantName;
@property (nonatomic, strong) NSString * messages;
@property (nonatomic, strong) NSString * summary;
@property (nonatomic, strong) NSString * time;
@property (nonatomic, strong) NSString * code;
@property (nonatomic, strong) UIImage * barcode;

@end

@interface MOFTicket (Utils)

- (UIImage *)barcodeForWidth:(CGFloat)width;
- (NSDate *)timeStamp;

@end

@interface MOFTicket (Relations)

@property (nonatomic, weak) MOFMerchant *merchant;

@end
