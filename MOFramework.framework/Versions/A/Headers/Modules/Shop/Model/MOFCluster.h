//
//  MOFCluster.h
//  MyOrderApp
//
//  Created by Angel Garcia on 02/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFModelObject.h"
@import MapKit;

@interface MOFCluster : MOFModelObject <MKAnnotation>

@property (nonatomic, strong) NSNumber *lat;
@property (nonatomic, strong) NSNumber *lon;
@property (nonatomic, strong) NSNumber *count;

@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

@end
