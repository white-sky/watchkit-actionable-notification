//
//  ViewController.swift
//  WhiteskyAppleWatchSample
//
//  Created by Rashmi Singh on 4/22/15.
//  Copyright (c) 2015 WhiteSky. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
  
  @IBOutlet var waitingForAuthLabel:UILabel!
  var replyBlock:(([NSObject : AnyObject]!) -> Void)?
  
  deinit{
    
    NSNotificationCenter.defaultCenter().removeObserver(self)
  }
  
  override func viewDidLoad() {
    
    super.viewDidLoad()
    
  }
  
  override func viewWillAppear(animated: Bool) {
    
    waitingForAuthLabel.hidden = true
    
    NSNotificationCenter.defaultCenter().addObserver(self, selector: "authSuccessNotification:", name: "AuthDataReceivedNotification", object: nil)
    super.viewWillAppear(animated)
  }
  
  override func didReceiveMemoryWarning() {
    
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }
  
  func authSuccessNotification( notification: NSNotification){
    
    if let userInfo = notification.userInfo, username = userInfo["u"] as? String, password = userInfo["p"] as? String {
      
      let browserViewController = BrowserViewController()
      browserViewController.configureSecureView()
      
      browserViewController.siteLoginDictionary = ["username" : username, "password" : password]
      browserViewController.urlToLoad = "https://mobile.twitter.com/session/new"
      
      self.presentViewController(browserViewController, animated: true) { () -> Void in
      }
      
    } else {
      
      // Alert that authentication failed!
      println("Auth from watch failed!")
    }
  }
  
  @IBAction func autoLoginTapped( sender: AnyObject ){
    
    // If setup - ask for 2 factor auth
    waitForCredentialsFromWatch()
  }
  
  private func waitForCredentialsFromWatch(){
    
    println("waitForCredentialsFromWatch")
    waitingForAuthLabel.hidden = false
    
    let localNotification = UILocalNotification()
    localNotification.alertTitle = "Test"
    localNotification.fireDate = NSDate().dateByAddingTimeInterval(5)
    
    UIApplication.sharedApplication().scheduleLocalNotification(localNotification)
    
  }
}

