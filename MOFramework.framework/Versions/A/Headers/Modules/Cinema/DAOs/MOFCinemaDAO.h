//
//  MOFCinemaDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 10/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"

@class MOFMovie;

/**
 *  DAO to manage the movies section
 */
@interface MOFCinemaDAO : MOFBaseDAO


/**
*  Load all movies for a specific group of merchants
*
*  @param merchants   List of merchants to load the movies from. Optional
*  @param animation   Animation type to pass to the animation handler of the request
*  @param resultBlock Block executed with the resulting array of MOFMovie if any
*  @param errorBlock  Block executed with the resulting error if any.
*
*  @return Connection fired. Cancellable.
*/
- (MOFNetworkConnection *)loadMoviesWithMerchants:(NSArray *)merchants
                                        animation:(MOFNetworkAnimation)animation
                                         onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                          onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load movie detail. Returns list of movies with same title
 *
 *  @param movie       Movie to load
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting array of MOFMovie if any
 *  @param errorBlock  Block executed with the resulting error if any.
 *
 *  @return Connection fired. Cancellable.
 */
- (MOFNetworkConnection *)loadMovieDetail:(MOFMovie *)movie
                                animation:(MOFNetworkAnimation)animation
                                 onResult:(MOFBaseDAOResultArrayBlock)resultBlock
                                  onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
