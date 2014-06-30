//
//  MOFBannersDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 01/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFBaseDAO.h"

@interface MOFBannersDAO : MOFBaseDAO

- (MOFNetworkConnection *)loadBanners:(MOFNetworkAnimation)animation
                             onResult:(MOFBaseDAOResultBlock)resultBlock
                              onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
