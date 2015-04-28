//
//  BrowserViewController.swift
//  WhiteskyAppleWatchSample
//
//  Created by Rashmi Singh on 4/22/15.
//  Copyright (c) 2015 WhiteSky. All rights reserved.
//

import WebKit
import WhiteSkyCoreSdk

class BrowserViewController: WSSWKBrowserViewController {

  var siteLoginDictionary:[String:String]?
  var urlToLoad:String?
  var shouldGenerateStatistics:Bool = false
  var stats:String?
  
  override func viewWillAppear(animated: Bool) {
    
    super.viewWillAppear(animated)
    
    WSSNewtonManager.sharedInstance.newtonLoginScript( urlToLoad!, completionHandler: { (hasLoginScript, loginScript: String? ) -> Void in
      
      self.loadBrowserWithUrl ( self.urlToLoad!, loginScript: loginScript )
    })
  }
  
  func webView(wssWkWebView: WSSWKWebView, loginAvailable parameters: [String:String]? ) {
    
    if siteLoginDictionary != nil {
      let delayTime = dispatch_time(DISPATCH_TIME_NOW, Int64( 1.0 * Double(NSEC_PER_SEC)))
      dispatch_after(delayTime, dispatch_get_main_queue(), {
        self.loginPlayback( self.siteLoginDictionary! )
      })
    }
  }
  
  func webView(wssWkWebView: WSSWKWebView, loginExecuted parameters: [String : String]?) {
    
    println("Login successful!")
  }

}
