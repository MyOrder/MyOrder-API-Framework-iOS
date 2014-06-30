//
//  MOFParkingPoint.h
//  MyOrderApp
//
//  Created by Angel Garcia on 15/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"


@interface MOFParkingPoint : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * address;

@end
