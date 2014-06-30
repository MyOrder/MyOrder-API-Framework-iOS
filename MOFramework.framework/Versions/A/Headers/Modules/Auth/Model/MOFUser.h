//
//  MOFUser.h
//  MyOrderApp
//
//  Created by Angel Garcia on 06/03/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOFUser : MOFModelObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *birthday;
@property (nonatomic, strong) NSString *mobilePhone;
@property (nonatomic, strong) UIImage *profileImage;
@property (nonatomic, strong) NSOrderedSet *addresses;

- (NSString *)fullName;

@end
