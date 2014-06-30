//
//  MOFTACook.h
//  MyOrderApp
//
//  Created by Angel Vasa on 3/6/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOFTAMeal;

@interface MOFTACook : MOFModelObject 

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * profileName;
@property (nonatomic, strong) NSString * details;
@property (nonatomic, strong) NSNumber * followersCount;
@property (nonatomic, strong) NSNumber * following;
@property (nonatomic, strong) NSNumber * lat;
@property (nonatomic, strong) NSNumber * lon;
@property (nonatomic, strong) NSNumber * mealCount;
@property (nonatomic, strong) NSNumber * mealsCurrentCount;
@property (nonatomic, strong) NSNumber * mealsPageCount;
@property (nonatomic, strong) NSNumber * mealsTotalCount;
@property (nonatomic, strong) NSNumber * thanksReceivedCount;
@property (nonatomic, strong) NSString * thumbnail;
@property (nonatomic, strong) NSNumber * vegetarian;
@property (nonatomic, strong) NSOrderedSet *meals;

@end
