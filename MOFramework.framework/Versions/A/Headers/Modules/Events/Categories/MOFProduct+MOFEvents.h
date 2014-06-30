//
//  MOFProduct+MOFEvents.h
//  MyOrderApp
//
//  Created by Angel Garcia on 21/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFProduct.h"

@interface MOFProduct (MOFEvents)

@property (nonatomic, strong) NSString *eventName;
@property (nonatomic, strong) NSString *eventDate;
@property (nonatomic, strong) NSString *eventTime;
@property (nonatomic, strong) NSString *eventCity;

@end
