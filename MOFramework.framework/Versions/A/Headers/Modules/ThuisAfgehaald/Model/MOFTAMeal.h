//
//  MOFTAMeal.h
//  MyOrderApp
//
//  Created by Angel Vasa on 3/6/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
@import MapKit;

@class MOFTAThank, MOFTAPickUp, MOFTACook;

@interface MOFTAMeal : MOFModelObject

@property (nonatomic, strong) NSString * identifier;
@property (nonatomic, strong) NSString * category;
@property (nonatomic, strong) NSString * details;
@property (nonatomic, strong) NSString * imageUrl;
@property (nonatomic, strong) NSString * place;
@property (nonatomic, strong) NSNumber * price;
@property (nonatomic, strong) NSNumber * request;
@property (nonatomic, strong) NSNumber * thanksCount;
@property (nonatomic, strong) NSString * thumbnailUrl;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, weak) MOFTAPickUp * pickUp;
@property (nonatomic, strong) NSOrderedSet * thank;
@property (nonatomic, strong) NSString *cookIdentifier;
@property (nonatomic, strong) NSString *cookProfileName;
@property (nonatomic, strong) NSString *cookLat;
@property (nonatomic, strong) NSString *cookLng;
@end

@interface MOFTAMeal (MKAnnotation)<MKAnnotation>
@end


@interface MOFTAMeal (Relations)

@property (nonatomic, strong) MOFTACook *cook;

@end