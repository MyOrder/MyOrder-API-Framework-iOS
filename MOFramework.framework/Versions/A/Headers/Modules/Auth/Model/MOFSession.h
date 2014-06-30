//
//  MOFSession.h
//  MyOrderApp
//
//  Created by Angel Garcia on 24/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOFSession : MOFModelObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *sessionKey;
@property (nonatomic, strong) NSDate *sessionDate;
@property (nonatomic, strong) NSString *moSessionId;
@property (nonatomic, strong) NSString *customerId;

- (BOOL)isAnonymous;
- (BOOL)isValid;

@end
