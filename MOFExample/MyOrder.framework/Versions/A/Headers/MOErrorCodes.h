//
//  MOErrorCodes.h
//  MyOrder
//
//  Created by Angel Garcia on 5/23/13.
//
//

//extern NSString * const MOErrorDomain;

#ifndef Pods_MOErrorCodes_h
#define Pods_MOErrorCodes_h

typedef enum {
    MOErrorGenericError = 10002,
    MOErrorServerCode = 10001,
    MOErrorNotLoggedIn = 5000,
    MOErrorSessionExpired = 5001,
    MOErrorTransactionMissingRequiredParam = 5002,
    MOErrorTransactionMissingReturnParam = 5003,
    MOErrorGenericMissingRequiredParam = 5004,
    MOErrorGenericTransactionFailure = 5005,
} MOErrorCode;

static NSString * const MOErrorDomain = @"com.myorder";

#endif
