//
//  MOFAddress.h
//  MyOrderApp
//
//  Created by Angel Garcia on 27/11/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@interface MOFAddress : MOFModelObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *number;
@property (nonatomic, strong) NSString *street;
@property (nonatomic, strong) NSString *postCode;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, strong) NSString *location;

@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

@end
