//
//  MOFModelObject.h
//  MyOrderApp
//
//  Created by Angel Garcia on 11/04/14.
//  Copyright (c) 2014 MyOrder.nl. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Persistence type
 */
typedef enum {
    /**
     *  No persistence, always creates a new object
     */
    MOFModelObjectPersistenceNone,
    
    /**
     *  Persisted only while another entity retains it
     */
    MOFModelObjectPersistenceMemoryWeak,
    
    /**
     *  Persisted in an NSCache for an undetermined time (until system empties the cache)
     */
    MOFModelObjectPersistenceMemoryCached,
    
    /**
     *  Persisted in disk in a binary format
     */
    MOFModelObjectPersistenceDisk
    
} MOFModelObjectPersistence;


/**
 *  Basic model class for the MOFFramework. It provides methods to fetch object and persist them based on the MOFModelObjectPersistence 
 *  selected per class. Persisted objects in any way require an object identifier
 */
@interface MOFModelObject : NSObject <NSCoding>

/**
 *  Property with identifier of the object. Can be any kind of object.
 *  Requerided when any persistence is used
 */
@property (nonatomic, strong) id identifier;


/**
 *  Checks whether an existing object of this type exists or not
 *
 *  @param identifier object identifier
 *
 *  @return YES if an object exists in persistence store
 */
+ (BOOL)existsObjectWithIdentifier:(id)identifier;


/**
 *  Returns an object with the existing identifier or creates a new one if none exist
 *
 *  @param identifier object identifier
 *
 *  @return Instance of existing object (new instance if no previous one existed)
 */
+ (instancetype)objectWithIdentifier:(id)identifier;


/**
 *  Returns an array of objects with the passed object identifiers
 *
 *  @param identifiers List of object identifiers
 *
 *  @return Array with all persisted or new instances
 */
+ (NSArray *)objectsWithIdentifiers:(NSArray *)identifiers;


/**
 *  Returns an array of objects existing in the persitence store passing the
 *  predicate provided. Note that depending on the persistence store this
 *  method might return no results.
 *
 *  @param predicate       Predicate to evaluate
 *  @param sortDescriptors Sort descriptors applied to returning objects
 *
 *  @return Array with all existing objects passing predicate
 */
+ (NSArray *)objectsWithPredicate:(NSPredicate *)predicate sortedBy:(NSArray *)sortDescriptors;


/**
 *  Returns the persistence type of this model class. Override it to change it per
 *  class model. Defaults to MOFModelObjectPersistenceNone
 *
 *  @return Persistence type
 */
+ (MOFModelObjectPersistence)persistenceType;


/**
 *  Persists all unsaved data in the persistence store. This method only does
 *  something when used in combination with MOFModelObjectPersistenceDisk
 *
 *  @param wait Bool indicating if blocking of the calling thread until done.
 */
+ (void)persist:(BOOL)wait;


/**
 *  Inserts the object into the persistence context if it is not there yet. Automatically
 *  called by all the `objectWithIdentifier:` alike methods
 */
- (void)save;


/**
 *  Removes the object from the persistence context. A call to `persist` is still required
 *  if you want to persist changes on disk
 */
- (void)delete;


@end
