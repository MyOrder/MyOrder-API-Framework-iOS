//
//  MOFPickUps.h
//  MyOrderApp
//
//  Created by Angel Vasa on 6/4/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"

@interface MOFTAPickUp : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * timeEnd;
@property (nonatomic, strong) NSString * timeStart;
@property (nonatomic, strong) NSString * portionsAvailable;
@property (nonatomic, strong) NSString * portionsTotal;
@property (nonatomic, strong) NSString * requestUntil;
@property (nonatomic, strong) NSString * status;

@end
