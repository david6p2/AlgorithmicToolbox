//
//  main.swift
//  APlusB
//
//  Created by David Andres Cespedes on 10/19/17.
//  Copyright © 2017 David Andres Cespedes. All rights reserved.
//

import Foundation
print("Please write the two input number that are going to be sumed separated by a space: \n")
if let aAndBArray = readLine()?.components(separatedBy: " ") {
    let a = Int(aAndBArray[0]) ?? 0
    let b = Int(aAndBArray[1]) ?? 0
    print(a + b)
}
