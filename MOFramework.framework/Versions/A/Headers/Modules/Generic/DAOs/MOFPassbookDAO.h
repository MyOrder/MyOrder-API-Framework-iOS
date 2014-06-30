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


- (MOFNetworkConnection *)loadPassWithTicket:(NSString *)ticketId
                               withAnimation:(MOFNetworkAnimation)animation
                                   onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                   onFailure:(MOFBaseDAOErrorBlock)errorBlock;


- (MOFNetworkConnection *)loadPassForReceiptWithOrderId:(NSString *)orderId
                                            description:(NSString *)description
                                           takeAwayTime:(NSString *)takeAwayTime
                                          withAnimation:(MOFNetworkAnimation)animation
                                              onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                              onFailure:(MOFBaseDAOErrorBlock)errorBlock;


-(MOFNetworkConnection *)modifyPassForMerchant:(MOFMerchant*)merchant
                                 withAniamtion:(MOFNetworkAnimation)animation
                         currentPassIdentifier:(NSString *)passIdentifier
                       currentPassSerialNumber:(NSString *)serialNumber
                                     onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                     onFailure:(MOFBaseDAOErrorBlock)errorBlock;

-(MOFNetworkConnection *)removePassWithIdentifier:(NSString *)passIdentifier
                                 passSerialNumber:(NSString *)serialNumber
                                        onSuccess:(MOFBaseDAOResultBlock)resultBlock
                                        onFailure:(MOFBaseDAOErrorBlock)errorBlock;

@end
