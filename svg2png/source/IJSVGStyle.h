//
//  IJSVGStyle.h
//  IJSVGExample
//
//  Created by Curtis Hard on 03/09/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "IJSVGColor.h"

@interface IJSVGStyle : NSObject {
    
@private
    NSMutableDictionary * _dict;
    
}

+ (IJSVGStyle *)parseStyleString:(NSString *)string;

- (void)setPropertyValue:(id)value
             forProperty:(NSString *)key;
- (id)property:(NSString *)key;

@end
