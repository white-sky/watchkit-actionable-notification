//
//  InterfaceController.swift
//  WhiteSkyWatchkit2FactorAuth WatchKit Extension
//
//  Created by Rashmi Singh on 4/26/15.
//  Copyright (c) 2015 WhiteSky. All rights reserved.
//

import WatchKit
import Foundation


class InterfaceController: WKInterfaceController {
  
  override func awakeWithContext(context: AnyObject?) {
    super.awakeWithContext(context)
    
    // Configure interface objects here.
  }
  
  override func willActivate() {
    // This method is called when watch view controller is about to be visible to user
    super.willActivate()
  }
  
  override func didDeactivate() {
    // This method is called when watch view controller is no longer visible
    super.didDeactivate()
  }
  
  override func handleActionWithIdentifier(identifier: String?, forRemoteNotification remoteNotification: [NSObject : AnyObject]) {
  
    var loginCreds: [String:String] = [String:String]()
    
    if let userDefault = NSUserDefaults(suiteName: "group.com.whitesky.twofactorauthsample2") {

      loginCreds  = userDefault.objectForKey("c") as! [String:String]
    }
    
    WKInterfaceController.openParentApplication(loginCreds) { ( replyDict: [NSObject : AnyObject]!, error: NSError!) -> Void in
    }

  }

}
