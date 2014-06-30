//
//  MOFSchedule.h
//  MyOrderApp
//
//  Created by Angel Garcia on 22/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOFSchedule : MOFModelObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *startTime;
@property (nonatomic, strong) NSString *endTime;
@property (nonatomic, strong) NSNumber *weekday;
@property (nonatomic, strong) NSNumber *isOpen;

@end
