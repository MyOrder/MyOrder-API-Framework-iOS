//
//  MOFCheckInStatus.h
//  MyOrderApp
//
//  Created by Angel Vasa on 6/18/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"

@interface MOFCheckInStatus : MOFModelObject

@property (nonatomic, strong) NSString *checkInCount;
@property (nonatomic, strong) NSString *isCheckedIn;

@end
