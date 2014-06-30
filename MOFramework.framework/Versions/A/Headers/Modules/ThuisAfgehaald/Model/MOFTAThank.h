//
//  MOFTAThanks.h
//  MyOrderApp
//
//  Created by Angel Vasa on 3/6/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFTAMeal;

@interface MOFTAThank : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * comment;
@property (nonatomic, strong) NSString * datetime;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * thumbnail;
@property (nonatomic, strong) NSOrderedSet *meals;

@end
