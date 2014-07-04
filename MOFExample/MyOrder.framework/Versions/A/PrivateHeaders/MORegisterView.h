//
//  MORegisterView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

typedef enum {
    MOConditionsTypeMinitix,
    MOConditionsTypeMyOrder
} MOConditionsType;

typedef void(^MOConditionsBlock)(MOConditionsType conditions);

@interface MORegisterView : UIScrollView

@property (nonatomic, strong) UISwitch *conditionsSwitch;
@property (nonatomic, copy) dispatch_block_t onNext;
@property (nonatomic, copy) MOConditionsBlock onConditions;
@property (nonatomic, readonly) NSString *phone;

- (id)initWithPhone:(NSString *)phone;

@end
