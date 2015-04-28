//
//  WSSScriptServices.h
//  CoreSdkApp
//
//  Created by Rashmi Singh on 9/10/14.
//  Copyright (c) 2014 WhiteSky. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kWSSScriptFullPath;
extern NSString *const kWSSScriptCheckJSName;
extern NSString *const kWSSScriptCheckJSValue;
extern NSString *const kWSSScriptEndPoint;

typedef NS_ENUM(NSInteger, WSSScriptId) {
  WSSScriptIdWhiteSky,
  WSSScriptIdClicker
};

@interface WSSScriptServices : NSObject

+ (NSDictionary *)scriptMeta:(WSSScriptId)scriptId;
@end
