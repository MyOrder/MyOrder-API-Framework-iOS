//
//  MODefines.h
//  MyOrder
//
//  Created by Taras Kalapun on 04-09-2013.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import "MyOrder.h"

#define MOLocalizedString(key, comment) \
[MyOrder localizedStringForKey:(key) value:@"" table:nil]


#if DEBUG
#define MOLog(...)  NSLog(@"MOLog: %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
#define MOLogDebug(...)  NSLog(@"MODebug: %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
#define MOLogInfo(...)  NSLog(@"MOInfo: %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
#else
#define MOLog(...)  do { } while(0)
#define MOLogDebug(...)  do { } while(0)
#define MOLogInfo(...)  do { } while(0)
#endif
#define MOLogWarning(...)  NSLog(@"MOWarning: %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
#define MOLogError(...)  NSLog(@"MOError: %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])

