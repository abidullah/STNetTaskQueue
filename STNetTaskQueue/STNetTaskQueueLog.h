//
//  STNetTaskQueueLog.h
//  STNetTaskQueue
//
//  Created by Kevin Lin on 6/9/15.
//  Copyright (c) 2014 Sth4Me. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface STNetTaskQueueLog : NSObject

+ (void)log:(NSString *)content, ...;

@end

NS_ASSUME_NONNULL_END
