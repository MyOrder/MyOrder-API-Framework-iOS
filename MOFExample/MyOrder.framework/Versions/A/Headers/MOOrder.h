//
//  MOOrder.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/29/13.
//
//

#import <Foundation/Foundation.h>

@interface MOOrder : NSObject

/**
 The price of the order, must correspond with the total price of the given items in euros
 If not set, will return `totalPriceForItems`
 */
@property (nonatomic, assign) double price;

/**
 Order Id given by the external system behind the transaction. Required
*/
@property (nonatomic, strong) NSString *externalOrderId;


/**
 Internal Order Id used by MyOrder. If provided, payment will be done with previous fulfillment data. Optional
 */
@property (nonatomic, strong) NSString *orderId;


/**
 The items to be ordered. Array of dictionaries with keys:
 - Name – The name of the item
 - Price – The price of the item in cents
 - Quantity – The quantity of the item
 */
@property (nonatomic, strong, readonly) NSArray *items;

/**
 Add an item to the order
 @param name Name of the item
 @param price Price of the item in euros
 @param quantity Number of items
 */
- (void)addItemWithName:(NSString *)name price:(double)price quantity:(NSUInteger)quantity;

@end
