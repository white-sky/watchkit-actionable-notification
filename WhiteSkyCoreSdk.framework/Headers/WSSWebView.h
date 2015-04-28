//
//  WSSWebView.h
//  WhiteSkySdkMaster
//
//  Created by jonathan wells on 5/18/14.
//  Copyright (c) 2014 White Sky Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIWebView+WSSCoreExtensions.h"

@interface WSSWebView : UIWebView

@property(readonly, nonatomic, getter=version) NSString *version;

/**
 *  Property to enable/disable enhancedMode. Default is set to YES.
 *  If enhancedMode is set to NO :<br/>
    -- WSSSuperWebViewDelegate events will not be triggered. <br/>
    -- method
    fillFieldsWithUser:creditCard:billingAddress:shippingAddress:completionHandler:
 <br/>
    is ignored.
 */
@property(assign, nonatomic, getter=isEnhancedMode) BOOL enhancedMode;
@end

@protocol WSSSuperWebViewDelegate <UIWebViewDelegate>
@optional

- (void)webViewDidWindowLoad:(UIWebView *)webView;
- (void)webView:(UIWebView *)webView didFindFields:(NSInteger *)count;
- (void)webView:(UIWebView *)webView didDomEventFired:(NSURL *)event;
@end