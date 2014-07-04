//
//  PassHelper.h
//  MyOrderApp
//
//  Created by Angel Vasa on 5/1/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"


@class MOFMerchant;
@interface MOFPassbookDAO : MOFBaseDAO

/**
 *  Load passbook pass for Ticket
 *
 *  @param ticketId    Ticket Id
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains PKAddPassesViewController object
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadPassWithTicket:(NSString *)ticketId
                               withAnimation:(MOFNetworkAnimation)animation
                                   onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                   onFailure:(MOFBaseDAOErrorBlock)errorBlock;



/**
 *  Load Pass for Receipt Id
 *
 *  @param orderId      Order Id
 *  @param description  description for pass
 *  @param takeAwayTime take away time
 *  @param animation    loading indicator style
 *  @param resultBlock  Block executed when the result is returned result contains PKAddPassesViewController object
 *  @param errorBlock   Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)loadPassForReceiptWithOrderId:(NSString *)orderId
                                            description:(NSString *)description
                                           takeAwayTime:(NSString *)takeAwayTime
                                          withAnimation:(MOFNetworkAnimation)animation
                                              onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                              onFailure:(MOFBaseDAOErrorBlock)errorBlock;

@end
