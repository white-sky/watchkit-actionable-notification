//
//  NSString+WSSCoreExtensions.h
//  WhiteSkySdkMaster
//
//  Created by Rashmi Singh on 4/21/14.
//  Copyright (c) 2014 White Sky Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (WSSCoreExtensions)

+ (NSString *)GUID;

/**
 *  Check if text is a valid integer
 *
 *  @param text
 *
 *  @return YES if the string is a valid integer
 */
+ (BOOL)stringIsValidInteger:(NSString *)text;

/**
 *  Check if text is nil or empty
 *
 *  @param text
 *
 *  @return YES is string is nil or empty
 */
+ (BOOL)stringIsNilOrEmpty:(NSString *)text;
@end
