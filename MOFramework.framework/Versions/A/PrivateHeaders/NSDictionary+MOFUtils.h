//
//  NSDictionary+MOFUtils.h
//
//  Created by Angel Garcia on 3/4/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (MOF_Utils)

- (NSString *)MOF_stringWithURLEncodedEntries;
- (NSString *)MOF_JSONString;

- (NSNumber *)MOF_numberForKey:(NSString *)key;
- (NSString *)MOF_stringForKey:(NSString *)key;
- (NSNumber *)MOF_booleanForKey:(NSString *)key;
- (NSArray *)MOF_arrayForKey:(NSString *)key;
- (NSDictionary *)MOF_dictionaryForKey:(NSString *)key;

@end
