//
//  WSSWebView+Extensions.h
//  CoreSdkApp
//
//  Created by Rashmi Singh on 8/28/14.
//  Copyright (c) 2014 WhiteSky. All rights reserved.
//

#import "WSSWebView.h"

@interface WSSWebView (WSSCoreExtensions)

/**
 *  Method to auto fill credit cards and address fields
 *  Note: This method will be ignored if WSSWebView class property
 isEnhancedMode is set to NO
 *  @param user

        Sample User Data dictionary:

        @{@"email" : @"test@whitesky.com",
        @"phone" : @"123-123-1234"
        }
 *  @param creditCard

        Sample Credit Data dictionary:

        @{@"nameOnCard" : @"Test Name",
        @"cardType" : @"Visa",
        @"cardNumber" : @"4111111111111111",
        @"cvv" : @"111",
        @"expireMonth" : @12,
        @"expireYear" : @2020
        }
 *  @param billingAddress

        Sample Billing Address dictionary:

        @{
        @"firstName":@"Jilling",
        @"lastName":@"Doe",
        @"street":@"102 billing ave",
        @"city":@"Billings",
        @"state"@:"MT",
        @"zip":@"07070"
        }
 *  @param shippingAddress

        Sample Shipping Address dictionary:

        @{@"firstName":@"Jane",
        @"lastName":@"Doe",
        @"street":@"4001 18th Street",
        @"city":@"San Francisco",
        @"state":@"CA",
        @"zip":@"94114"
        }
 *  @param completionHandler

        filledDataDictionary -
        error - has data validation errors
 */
- (void)fillFieldsWithUser:(NSDictionary *)user
                creditCard:(NSDictionary *)creditCard
            billingAddress:(NSDictionary *)billingAddress
           shippingAddress:(NSDictionary *)shippingAddress
         completionHandler:(void (^)(NSDictionary *filledDataDictionary,
                                     NSError *error))completionHandler;

@end
