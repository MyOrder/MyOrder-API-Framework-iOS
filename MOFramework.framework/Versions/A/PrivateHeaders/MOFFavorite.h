//
//  MOFFavorite.h
//  MyOrderApp
//
//  Created by Angel Garcia on 14/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  Internal model where favorites are stored. Do not use directly
 */
@interface MOFFavorite : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) MOFModelObject *object;

@end


@interface MOFFavorite (Relations)

+ (MOFFavorite *)favoriteForObject:(MOFModelObject *)object;

@end
