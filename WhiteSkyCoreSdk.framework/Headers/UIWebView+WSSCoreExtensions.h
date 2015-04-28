//
//  UIWebView+WSSCoreExtensions.h
//  WSWebView
//
//  Created by Jonathan Wells on 12/12/13.
//  Copyright (c) 2013 Jonathan Wells. All rights reserved.
//

#import <UIKit/UIKit.h>

#define UIWebViewNavigationTypeString(enum)                                    \
  [@[                                                                          \
    @"linkClicked",                                                            \
    @"formSubmitted",                                                          \
    @"backForward",                                                            \
    @"reload",                                                                 \
    @"formSubmitted",                                                          \
    @"other"                                                                   \
  ] objectAtIndex:enum]

@interface UIWebView (WSSCoreExtensions)

@property(nonatomic, readonly, getter=readyState) NSString *readyState;
@property(nonatomic, readonly, getter=documentTitle) NSString *documentTitle;
@property(nonatomic, readonly, getter=userAgent) NSString *userAgent;

- (void)loadUrlString:(NSString *)urlString;

- (void)logByEvaluatingJavaScriptFromString:(NSString *)javascript;

- (BOOL)elementExistsByQuerySelector:(NSString *)selector;

- (void)hitEnter;

- (void)clickByQuerySelector:(NSString *)selector;

- (BOOL)setInputFieldWithQuerySelector:(NSString *)selector
                              andValue:(NSString *)value;

- (BOOL)isEnhancedMode;

@end
