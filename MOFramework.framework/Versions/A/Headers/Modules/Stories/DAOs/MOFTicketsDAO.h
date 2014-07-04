//
//  MOFTicketsDAO.h
//  MyOrderApp
//
//  Created by Angel Vasa on 3/24/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"
#import "MOFTicket.h"

@class MOFCoupon;

@interface MOFTicketsDAO : MOFBaseDAO

/** 
 *  Load Ticket
 *
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains Array of MOFTicket
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */

- (MOFNetworkConnection *)loadTicketsWithAnimation:(MOFNetworkAnimation)animation
                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                           onError:(MOFBaseDAOErrorBlock)errorBlock;


/** 
 *  Load Ticket Detail
 *
 *  @param ticket      Ticket object
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTicket
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */



- (MOFNetworkConnection *)loadTicketsDetail:(MOFTicket *)ticket
                                  animation:(MOFNetworkAnimation)animation
                                   onResult:(MOFBaseDAOResultBlock)resultBlock
                                    onError:(MOFBaseDAOErrorBlock)errorBlock;


/** 
 *  Mark Ticket Used
 *
 *  @param ticket      Ticket Object
 *  @param animation   loading indicator style
 *  @param resultBlock Block executed when the result is returned result contains MOFTicket
 *  @param errorBlock  Block to execute in case of error
 *
 *  @return Connection fired. Cancellable.
 */


- (MOFNetworkConnection *)markTicketUsed:(MOFTicket *)ticket
                               animation:(MOFNetworkAnimation)animation
                                onResult:(MOFBaseDAOResultBlock)resultBlock
                                 onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
