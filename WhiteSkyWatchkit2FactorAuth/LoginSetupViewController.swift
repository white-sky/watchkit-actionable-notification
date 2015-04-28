//
//  LoginSetupViewController.swift
//  WhiteskyAppleWatchSample
//
//  Created by Rashmi Singh on 4/23/15.
//  Copyright (c) 2015 WhiteSky. All rights reserved.
//

import UIKit

class LoginSetupViewController: UIViewController {
  
  @IBOutlet weak var usernameTextField: UITextField!
  @IBOutlet weak var passwordTextField: UITextField!
  
  override func viewDidLoad() {
    
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
  }
  
  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }
  
  @IBAction func saveTapped( sender: AnyObject ){
    
    // Save data to vault. For demo purposes, we will save the credentials in user defaults
    
    let credDict = ["u":usernameTextField.text, "p":passwordTextField.text]
    let userDefault = NSUserDefaults(suiteName: "group.com.whitesky.twofactorauthsample2")
    userDefault!.setObject(credDict, forKey: "c")
    userDefault!.synchronize()
    
    self.dismissViewControllerAnimated(true, completion: { () -> Void in
    })
  }

  @IBAction func cancelTapped( sender: AnyObject ){
    self.dismissViewControllerAnimated(true, completion: { () -> Void in
    })
  }
  
}
