//
//  MOFFulfillmentMethod.h
//  MyOrderApp
//
//  Created by Angel Garcia on 22/01/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFModelObject.h"


/** Constant with the possible values of fulfilment types **/
extern NSString * const kMOFFulfillmentMethodTypeTakeAway;
extern NSString * const kMOFFulfillmentMethodTypeDelivery;
extern NSString * const kMOFFulfillmentMethodTypeLocale;


/** Constant with the possible values of the target screen **/
extern NSString * const kMOFFulfillmentMethodTargetScreenTicket;
extern NSString * const kMOFFulfillmentMethodTargetScreenReceipt;
extern NSString * const kMOFFulfillmentMethodTargetScreenTimer;


@interface MOFFulfillmentMethod : MOFModelObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSNumber *active;
@property (nonatomic, strong) NSNumber *priceAdjustment;
@property (nonatomic, strong) NSArray *extraInfo;
@property (nonatomic, strong) NSString *targetScreen;

@end


/** Constant with the possible values of method parameter types **/
extern NSString * const kMOFFulfillmentMethodParameterTypeText;
extern NSString * const kMOFFulfillmentMethodParameterTypeNumber;
extern NSString * const kMOFFulfillmentMethodParameterTypeTime;
extern NSString * const kMOFFulfillmentMethodParameterTypeTimeBlock;
extern NSString * const kMOFFulfillmentMethodParameterTypeBlock;

/** Constant with the possible values of method parameter names **/
extern NSString * const kMOFFulfillmentMethodParameterNameIWantItNow;

/** Constant with special values **/
extern NSString * const kMOFFulfillmentMethodParameterValueASAP;



@interface MOFFulfillmentMethodParameter : MOFModelObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSNumber *required;

@property (nonatomic, strong) NSArray *values;
@property (nonatomic, strong) NSString *selectedValue;

- (BOOL)isValid;

@end

@interface MOFFulfillmentMethodParameter (Utils)

- (NSDate *)selectedValueToDate;
- (NSString *)dateToValue:(NSDate *)date;

@end