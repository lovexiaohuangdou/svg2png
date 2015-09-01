//
//  IJSVGGradient.h
//  IJSVGExample
//
//  Created by Curtis Hard on 03/09/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "IJSVGGradient.h"

@interface IJSVGLinearGradient : IJSVGGradient

+ (NSGradient *)parseGradient:(NSXMLElement *)element
                     gradient:(IJSVGLinearGradient *)aGradient;

@end
