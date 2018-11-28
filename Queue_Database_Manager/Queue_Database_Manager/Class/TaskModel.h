//
//  TaskModel.h
//  Queue_Database_Manager
//
//  Created by sh-lx on 2018/11/23.
//  Copyright © 2018年 sh-lx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RSModel.h"


typedef NS_ENUM(NSInteger ,RSTaskQueueTaskModelStatus) {
    RSTaskQueueTaskModelStatusInit,
    RSTaskQueueTaskModelStatusRunning,
    RSTaskQueueTaskModelStatusSuspend,
    RSTaskQueueTaskModelStatusFinish,
    RSTaskQueueTaskModelStatusFail,
    RSTaskQueueTaskModelStatusRemove,
};

typedef NS_ENUM(NSInteger ,RSTaskQueueTaskModelPriority) {
    RSTaskQueueTaskModelPriorityLow,
    RSTaskQueueTaskModelPriorityMiddle,
    RSTaskQueueTaskModelPriorityHigh,
};


NS_ASSUME_NONNULL_BEGIN

@interface TaskModel : RSModel
@property (nonatomic, assign) NSInteger taskId;
@property (nonatomic, assign) RSTaskQueueTaskModelStatus status;
@property (nonatomic, assign) RSTaskQueueTaskModelPriority priority;
@property (nonatomic, strong) NSString *customId;
@property (nonatomic, strong) NSString *customType;
@property (nonatomic, strong) NSString *className;
@property (nonatomic, strong) NSData *data;
@property (nonatomic, assign) NSInteger runCount;

-(void)run;//任务运行主入口，子类需要实现它
-(void)suspend;//执行异步操作时调用，可以挂起当前任务，防止任务队列被阻塞
-(void)pop;//任务执行成功需要显式调用，将任务从队列中移除
-(void)fail;//任务执行失败需要显式调用, 修改任务的状态
-(void)retryNextTime;//重新入队，等待重试
-(BOOL)prepareForAddToQueue;//任务被插入任务队列前，自动调用，子类可以重载它。返回失败则任务不用被加入任务队列
-(BOOL)remove;//从任务队列中移除任务


@end

NS_ASSUME_NONNULL_END
