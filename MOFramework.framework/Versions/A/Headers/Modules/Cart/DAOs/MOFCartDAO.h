//
//  MOFCartDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 02/12/13.
//  Copyright (c) 2013 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOFBaseDAO.h"

@class MOOrder;
@class MOFOrder;
@class MOFOrderItem;
@class MOFProduct;
@class MOFFulfillmentMethod;
@class MOFFulfillmentMethodParameter;

/**
 *  Constant with the Notification fired when the cart is updated. Note that Cart methods do not return MOFNetworkConnection
 *  objects because one single operation normally requires multiple server requests, and so they should not be canceled or modified
 */
static const NSString *kMOFCartUpdateNotification = @"kMOFCartUpdateNotification";

/**
 *  DAO used to manage the shopping cart. Cart is server side syncrhonized, and required MOFAuthDAO with existing session 
 *  (anonymous or logged in user)
 */
@interface MOFCartDAO : MOFBaseDAO


/**
 *  Loaded shopping cart order for the current session. It gets updated with any cart operation
 */
@property (nonatomic, readonly) MOFOrder *order;


/**
 *  Resets the shopping cart to a clean one
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)resetCartWithAnimation:(MOFNetworkAnimation)animation
                      onResult:(MOFBaseDAOResultBlock)resultBlock
                       onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Load an existing shopping cart from server. This methods gets called automatically on startup and when
 *  session status changes
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)loadCartWithAnimation:(MOFNetworkAnimation)animation
                     onResult:(MOFBaseDAOResultBlock)resultBlock
                      onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Addes a new product to the cart
 *
 *  @param product     Product to add
 *  @param options     Option values selected by user. Same option value can be passed multiple times
 *  @param quantity    Amount of units to add
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)addNewProductToCart:(MOFProduct *)product
                withOptions:(NSCountedSet *)options
                   quantity:(NSInteger)quantity
                  animation:(MOFNetworkAnimation)animation
                   onResult:(MOFBaseDAOResultBlock)resultBlock
                    onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Removes a product from the cart. Note that if the product is added multiple times with different
 *  option values they will all be deleted
 *
 *  @param product     Product to delete
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)removeProductFromCart:(MOFProduct *)product
                    animation:(MOFNetworkAnimation)animation
                     onResult:(MOFBaseDAOResultBlock)resultBlock
                      onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Removes a particular item from the cart.
 *
 *  @param orderItem   Order item to remove
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)removeItem:(MOFOrderItem *)orderItem
         animation:(MOFNetworkAnimation)animation
          onResult:(MOFBaseDAOResultBlock)resultBlock
           onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Updates the quantity or selected values of a particular item in the cart. 
 *  If quantity is equal or lower than 0, this method will invoke `removeItem:` automatically
 *
 *  @param orderItem   Order item to update
 *  @param options     New set of product option values to update. If none passed, then previous values will be removed
 *  @param quantity    New amount to set
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)updateItem:(MOFOrderItem *)orderItem
       withOptions:(NSCountedSet *)options
          quantity:(NSInteger)quantity
         animation:(MOFNetworkAnimation)animation
          onResult:(MOFBaseDAOResultBlock)resultBlock
           onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Sets one fulfillment method as the selected one. This call is required before proceding with the checkout
 *
 *  @param method      Fulfillment method selected by the user
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)selectFulfillmentMethod:(MOFFulfillmentMethod *)method
                      animation:(MOFNetworkAnimation)animation
                       onResult:(MOFBaseDAOResultBlock)resultBlock
                        onError:(MOFBaseDAOErrorBlock)errorBlock;


/**
 *  Load all fulfillment method value for a particular fulfillment method. Important to load before checkout
 *  to check that the selected value is correct in case of timeblocks or blocks
 *
 *  @param method      Fulfillment method to load
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFFulfillmentMethod
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)loadFulfillmentMethodValues:(MOFFulfillmentMethod *)method
                          animation:(MOFNetworkAnimation)animation
                           onResult:(MOFBaseDAOResultBlock)resultBlock
                            onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Start the checkout of the shopping cart. This method returns an MOOrder object that can be passed directly to the MyOrder
 *  payment SDK to start the payment and removes the current cart (it is now checked out)
 *
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the created MOOrder to pay
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)startCheckoutWithAnimation:(MOFNetworkAnimation)animation
                       onResult:(MOFBaseDAOResultBlock)resultBlock
                        onError:(MOFBaseDAOErrorBlock)errorBlock;


#warning Check if this can be remvoed
- (void)completeCheckoutWithMOOrder:(MOOrder *)order
                          animation:(MOFNetworkAnimation)animation
                           onResult:(MOFBaseDAOResultBlock)resultBlock
                            onError:(MOFBaseDAOErrorBlock)errorBlock;

/**
 *  Cancels a previsouly checkout out order. This method will revert the order back into a valid shopping cart
 *
 *  @param order       Checked out cart to revert into a regular cart
 *  @param animation   Animation type to pass to the animation handler of the request
 *  @param resultBlock Block executed with the resulting updated MOFOrder
 *  @param errorBlock  Block executed with the resulting error if any.
 */
- (void)cancelCheckoutOfOrder:(MOFOrder *)order
                    animation:(MOFNetworkAnimation)animation
                     onResult:(MOFBaseDAOResultBlock)resultBlock
                      onError:(MOFBaseDAOErrorBlock)errorBlock;

@end
