//
//  IJSVGForeignObject.h
//  IconJar
//
//  Created by Curtis Hard on 02/09/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "IJSVGNode.h"

@interface IJSVGForeignObject : IJSVGNode {
    
    NSString * requiredExtension;
    
}

@property ( nonatomic, copy ) NSString * requiredExtension;

@end
