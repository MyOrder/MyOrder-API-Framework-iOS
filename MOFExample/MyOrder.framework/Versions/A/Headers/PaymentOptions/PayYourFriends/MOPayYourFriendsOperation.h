//
//  MOPayYourFriendsOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 24/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "MOPaymentOperation.h"


typedef enum {
    MOPayYourFriendsOperationStatusCodeComplete = 1,
    MOPayYourFriendsOperationStatusCodeStarted = 2,
    MOPayYourFriendsOperationStatusCodeConfirmed = 3
} MOPayYourFriendsOperationStatus;

@interface MOPayYourFriendsOperation : MOPaymentOperation

@property (nonatomic, strong) NSString *mobileNumber;
@property (nonatomic, assign) CGFloat amount;
@property (nonatomic, strong) NSString *details;

@property (nonatomic, assign, readonly) MOPayYourFriendsOperationStatus status;

- (void)completeWithCode:(NSString *)code onCompletion:(MOOperationBlock)completionBlock onError:(MOOperationErrorBlock)errorBlock;

@end
