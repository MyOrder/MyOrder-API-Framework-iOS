//
//  MOFModelProtocol.h
//  MyOrderApp
//
//  Created by Angel Garcia on 10/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MOFModelProtocol <NSObject>

@property (nonatomic, strong) id identifier;

+ (id)MOF_objectWithIdentifier:(id)identifier;

@end
