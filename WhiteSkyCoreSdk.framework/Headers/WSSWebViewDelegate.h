//
//  WSSWebViewDelegate.h
//  WhiteSkySdkMaster
//
//  Created by jonathan wells on 5/25/14.
//  Copyright (c) 2014 White Sky Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

// externs
//
extern NSString *const WSSWebViewDidReceiveDomEventNotification;
extern NSString *const WSSWebViewDidWindowLoadNotification;

@protocol WSSWebViewEventDelegate;

@interface WSSWebViewDelegate : NSObject <UIWebViewDelegate>

@property(nonatomic, weak) id<UIWebViewDelegate> outerDelegate;
@end

@protocol WSSWebViewEventDelegate <UIWebViewDelegate>

@optional

- (void)webViewDidWindowLoad:(UIWebView *)webView;
- (void)webView:(UIWebView *)webView didFindFields:(NSInteger *)count;
- (void)webView:(UIWebView *)webView didDomEventFired:(NSURL *)event;
@end