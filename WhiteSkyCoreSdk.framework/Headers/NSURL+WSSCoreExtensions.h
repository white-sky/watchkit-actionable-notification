//
//  NSURL+WSSCoreExtensions.h
//  WSWebView
//
//  Created by Jonathan Wells on 2/27/14.
//  Copyright (c) 2014 Jonathan Wells. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString *const kWSSeventScheme;

@interface NSURL (WSSCoreExtensions)

- (BOOL)isFragmentJumpFromUrl:(NSURL *)url;

@property(nonatomic, readonly, getter=isHttp) BOOL Http;
@property(nonatomic, readonly, getter=isWssEvent) BOOL WssEvent;

@end
