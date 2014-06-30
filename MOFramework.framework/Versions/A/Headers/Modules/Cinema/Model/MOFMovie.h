//
//  MOFMovie.h
//  MyOrderApp
//
//  Created by Angel Garcia on 14/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"
@class MOFCategory;
@class MOFOrderItem;
@class MOFProduct;

@interface MOFMovie : MOFModelObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSSet *categories;

+ (instancetype)objectWithMovieCategory:(MOFCategory *)category;
+ (instancetype)objectWithOrderItem:(MOFOrderItem *)orderItem;
+ (instancetype)objectWithProduct:(MOFProduct *)product;

@end

@interface MOFMovie (Relations)

/**
 *  List of all merchants that display a movie
 */
@property (nonatomic, readonly) NSArray *allMerchants;

/**
 *  List of all dates available for a movie
 *  Dates are represented internally by MOFCategory
 */
@property (nonatomic, readonly) NSArray *allDates;

/**
 *  List of all avaible times for a movie
 *  Times are represented internally by MOFProduct
 */
@property (nonatomic, readonly) NSArray *allTimes;


@end

