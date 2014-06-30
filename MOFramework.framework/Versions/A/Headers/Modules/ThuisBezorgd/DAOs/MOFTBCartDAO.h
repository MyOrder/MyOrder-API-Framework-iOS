//
//  MOFTBCartDAO.h
//  MyOrderApp
//
//  Created by Angel Garcia on 19/05/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import "MOFCartDAO.h"

/**
 *  DAO for supporting ThuisBezorg cart. Instantiating this DAO will replace the existing MOFCartDAO to provide a 
 *  transparent TB handling
 */
@interface MOFTBCartDAO : MOFCartDAO

@end
