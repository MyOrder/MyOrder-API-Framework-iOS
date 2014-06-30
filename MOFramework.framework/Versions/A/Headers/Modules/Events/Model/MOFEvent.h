//
//  MOFEvent.h
//  MyOrderApp
//
//  Created by Angel Garcia on 21/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"

@class MOFCategory;
@class MOFOrderItem;
@class MOFProduct;

@interface MOFEvent : MOFModelObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) MOFCategory *category;
@property (nonatomic, strong) NSArray *allProducts;
@property (nonatomic, strong) NSArray *allDates;
@property (nonatomic, strong) NSArray *allTimes;
@property (nonatomic, strong) NSArray *allCities;

+ (instancetype)objectWithEventCategory:(MOFCategory *)category;
+ (instancetype)objectWithEventProduct:(MOFProduct *)product;

@end

@interface MOFEvent (Utils)

+ (NSArray *)datesForProducts:(NSArray *)products;
+ (NSArray *)timesForProducts:(NSArray *)products;
+ (NSArray *)citiesForProducts:(NSArray *)products;
+ (NSArray *)filterProducts:(NSArray *)products city:(NSString *)city date:(NSString *)date time:(NSString *)time;

@end

