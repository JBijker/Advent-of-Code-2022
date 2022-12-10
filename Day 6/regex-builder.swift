//
//  main.swift
//  AoC
//
//  Created by Jeppe Bijker on 01/12/2022.
//

import Foundation

print((1...13).map { "(\\w)" + (1...$0).map { "(?!\\" + String($0) + ")" }.joined() }.joined() + "\\w")
