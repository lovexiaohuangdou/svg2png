//
//  IJSVGParser.h
//  IconJar
//
//  Created by Curtis Hard on 30/08/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "IJSVGForeignObject.h"
#import "IJSVGGroup.h"
#import "IJSVGPath.h"
#import "IJSVGUtils.h"
#import "IJSVGCommand.h"
#import "IJSVGColor.h"
#import "IJSVGTransform.h"
#import "IJSVGDef.h"
#import "IJSVGLinearGradient.h"
#import "IJSVGRadialGradient.h"

@class IJSVGParser;

@protocol IJSVGParserDelegate <NSObject>

@optional
- (BOOL)svgParser:(IJSVGParser *)svg
shouldHandleForeignObject:(IJSVGForeignObject *)foreignObject;
- (void)svgParser:(IJSVGParser *)svg
handleForeignObject:(IJSVGForeignObject *)foreignObject
   document:(NSXMLDocument *)document;

@end

@interface IJSVGParser : IJSVGGroup {
    
    NSRect viewBox;
    NSSize proposedViewSize;
    
@private
    id<IJSVGParserDelegate> _delegate;
    NSXMLDocument * _document;
    NSMutableArray * _glyphs;
    
}

@property ( nonatomic, readonly ) NSRect viewBox;
@property ( nonatomic, readonly ) NSSize proposedViewSize;

- (id)initWithFileURL:(NSURL *)aURL
             delegate:(id<IJSVGParserDelegate>)delegate;
- (id)initWithFileURL:(NSURL *)aURL
             encoding:(NSStringEncoding)encoding
             delegate:(id<IJSVGParserDelegate>)delegate;;
+ (IJSVGParser *)groupForFileURL:(NSURL *)aURL;
+ (IJSVGParser *)groupForFileURL:(NSURL *)aURL
                        delegate:(id<IJSVGParserDelegate>)delegate;
- (NSSize)size;
- (BOOL)isFont;
- (NSArray *)glyphs;

@end
