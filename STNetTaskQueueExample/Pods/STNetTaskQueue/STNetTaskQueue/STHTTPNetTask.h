//
//  STHTTPNetTask.h
//  Sth4Me
//
//  Created by Kevin Lin on 29/11/14.
//  Copyright (c) 2014 Sth4Me. All rights reserved.
//

#import "STNetTask.h"

// Error domains
FOUNDATION_EXPORT NSString *const STHTTPNetTaskServerError;
FOUNDATION_EXPORT NSString *const STHTTPNetTaskResponseParsedError;

// Error "userInfo" key
FOUNDATION_EXPORT NSString *const STHTTPNetTaskErrorStatusCodeUserInfoKey;
FOUNDATION_EXPORT NSString *const STHTTPNetTaskErrorResponseDataUserInfoKey;

FOUNDATION_EXPORT NSString *STHTTPNetTaskRequestObjectDefaultSeparator;

typedef NS_ENUM(NSUInteger, STHTTPNetTaskMethod) {
    STHTTPNetTaskGet,
    STHTTPNetTaskPost,
    STHTTPNetTaskPut,
    STHTTPNetTaskDelete,
    STHTTPNetTaskHead,
    STHTTPNetTaskPatch
};

typedef NS_ENUM(NSUInteger, STHTTPNetTaskRequestType) {
    STHTTPNetTaskRequestJSON,
    STHTTPNetTaskRequestKeyValueString,
    STHTTPNetTaskRequestFormData
};

typedef NS_ENUM(NSUInteger, STHTTPNetTaskResponseType) {
    STHTTPNetTaskResponseJSON,
    STHTTPNetTaskResponseString,
    STHTTPNetTaskResponseRawData
};

@protocol STHTTPNetTaskRequestObject <NSObject>

// Properties which should be ignored when packing parameters for reqeust
- (NSArray *)ignoredProperties;

@optional
- (NSString *)parameterNameSeparator;

@end

@interface STHTTPNetTask : STNetTask<STHTTPNetTaskRequestObject>

@property (nonatomic, strong) id<STHTTPNetTaskRequestObject> requestObject;

- (STHTTPNetTaskMethod)method;
- (STHTTPNetTaskRequestType)requestType;
- (STHTTPNetTaskResponseType)responseType;
- (NSDictionary *)headers;
- (NSDictionary *)parameters;
- (NSDictionary *)datas;
- (void)didResponseDictionary:(NSDictionary *)dictionary;
- (void)didResponseArray:(NSArray *)array;
- (void)didResponseString:(NSString *)string;
- (void)didResponseData:(NSData *)data;

@end
