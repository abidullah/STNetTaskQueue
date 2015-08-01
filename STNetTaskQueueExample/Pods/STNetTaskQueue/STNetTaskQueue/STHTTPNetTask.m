//
//  STHTTPNetTask.m
//  Sth4Me
//
//  Created by Kevin Lin on 29/11/14.
//  Copyright (c) 2014 Sth4Me. All rights reserved.
//

#import "STHTTPNetTask.h"

NSString *const STHTTPNetTaskServerError = @"STHTTPNetTaskServerError";
NSString *const STHTTPNetTaskResponseParsedError = @"STHTTPNetTaskResponseParsedError";

@implementation STHTTPNetTask

- (STHTTPNetTaskMethod)method
{
    return STHTTPNetTaskGet;
}

- (STHTTPNetTaskRequestType)requestType
{
    return STHTTPNetTaskRequestKeyValueString;
}

- (STHTTPNetTaskResponseType)responseType
{
    return STHTTPNetTaskResponseJSON;
}

- (NSDictionary *)datas
{
    return nil;
}

- (NSDictionary *)parameters
{
    return nil;
}

- (void)didResponse:(id)response
{
    if ([response isKindOfClass:[NSDictionary class]]) {
        [self didResponseJSON:response];
    }
    else if ([response isKindOfClass:[NSString class]]) {
        [self didResponseString:response];
    }
    else if ([response isKindOfClass:[NSData class]]) {
        [self didResponseData:response];
    }
    else {
        NSAssert(NO, @"Invalid response");
    }
}

- (void)didResponseJSON:(NSDictionary *)json
{
    
}

- (void)didResponseString:(NSString *)string
{
    
}

- (void)didResponseData:(NSData *)data
{
    
}

@end