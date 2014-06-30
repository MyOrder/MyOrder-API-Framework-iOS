//
//  MOFCheckIn.h
//  MyOrderApp
//
//  Created by Angel Vasa on 5/8/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"

@interface MOFCheckIn : MOFModelObject

@property (nonatomic, strong) NSString *checkInStatus;
@property (nonatomic, strong) NSString *checkInMessage;

@end
