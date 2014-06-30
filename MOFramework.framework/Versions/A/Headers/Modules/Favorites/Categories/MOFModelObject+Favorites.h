//
//  MOFModelObject+Favorites.h
//  MyOrderApp
//
//  Created by Angel Garcia on 11/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"

@interface MOFModelObject (Favorites)

/**
 *  Returns all favorite objects of the particular type of the class
 *
 *  @return List of favorite objects of this class
 */
+ (NSArray *)allFavorites;


/**
 *  Check if an object is in favorite list
 */
@property (nonatomic, assign, getter = isFavorite) BOOL favorite;


@end
