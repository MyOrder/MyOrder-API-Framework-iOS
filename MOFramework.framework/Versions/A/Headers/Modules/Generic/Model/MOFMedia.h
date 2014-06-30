//
//  MOFMedia.h
//  MyOrderApp
//
//  Created by Angel Garcia on 20/12/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kMOFMediaTypeLogo @"logo"
#define kMOFMediaTypePhoto @"photo"

@interface MOFMedia : MOFModelObject

@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *type;

- (NSURL *)serverURL;
- (NSURL *)serverURLWithSize:(CGSize)size;

@end
