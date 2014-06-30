//
//  MOFTicketsDAO.h
//  MyOrderApp
//
//  Created by Angel Vasa on 3/24/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"
#import "MOFTickets.h"

@class MOFCoupon;

@interface MOFTicketsDAO : MOFBaseDAO

- (MOFNetworkConnection *)loadTicketsWithAnimation:(MOFNetworkAnimation)animation
                                          onResult:(MOFBaseDAOResultBlock)resultBlock
                                           onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadTicketsDetail:(MOFTickets *)ticket
                                  animation:(MOFNetworkAnimation)animation
                                   onResult:(MOFBaseDAOResultBlock)resultBlock
                                    onError:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadTicketsDetailToMarkUsed:(MOFTickets *)ticket
                                            animation:(MOFNetworkAnimation)animation
                                             onResult:(MOFBaseDAOResultBlock)resultBlock
                                              onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
