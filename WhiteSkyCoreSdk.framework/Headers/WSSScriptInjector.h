//
//  WSSScriptInjector.h
//  CoreSdkApp
//
//  Created by Rashmi Singh on 9/10/14.
//  Copyright (c) 2014 WhiteSky. All rights reserved.
//

#import "WSSWebView+WSSCoreExtensions.h"
#import "WSSScriptServices.h"

typedef NS_ENUM(NSInteger, WSSScriptInjectorMethod) {
  WSSScriptInjectorMethodInsertTag,
  WSSScriptInjectorMethodInsertCode,
  WSSScriptInjectorMethodExecute
};

typedef NS_ENUM(NSInteger, WSSScriptInjectorCachePolicy) {
  WSSScriptInjectorCachePolicyForceLoad,
  WSSScriptInjectorCachePolicyHttpProtocol
};

@interface WSSScriptInjector : NSObject

/**
 *  Method to inject script in the passed NSData
 *
 *  @param scriptId        WSSScriptId to be inserted
 *  @param data              Data in which script needs to be inserted
 *  @param httpResponse      <#httpResponse description#>
 *  @param completionHandler completionHandler with updated NSData,
 *updatedHttpResponse and error
 */
- (void)injectScript:(WSSScriptId)scriptId
               inData:(NSData *)data
         httpResponse:(NSHTTPURLResponse *)httpResponse
    completionHandler:(void (^)(NSData *returnData,
                                NSHTTPURLResponse *returnHttpResponse,
                                NSError *error))completionHandler;

- (void)injectScript:(WSSScriptId)scriptId
               inData:(NSData *)data
               method:(WSSScriptInjectorMethod)method
             encoding:(NSStringEncoding)encoding
    completionHandler:
        (void (^)(NSData *returnData, NSError *error))completionHandler;

- (void)injectScript:(WSSScriptId)scriptId
           inWebView:(WSSWebView *)webView
              method:(WSSScriptInjectorMethod)method;

+ (id)sharedInstance;
@end
