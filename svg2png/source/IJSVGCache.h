//
//  IJSVGCache.h
//  IconJar
//
//  Created by Curtis Hard on 02/09/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <sys/stat.h>
#import "IJSVG.h"

@interface IJSVGCache : NSObject {
    
}

+ (IJSVG *)cachedSVGForFileURL:(NSURL *)aURL;
+ (void)cacheSVG:(IJSVG *)svg fileURL:(NSURL *)aURL;
+ (void)flushCache;
+ (BOOL)enabled;
+ (void)setEnabled:(BOOL)flag;

@end
