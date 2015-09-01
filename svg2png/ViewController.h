//
//  ViewController.h
//  svg2png
//
//  Created by coco on 15/9/1.
//  Copyright (c) 2015年 coco. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "DragImageView.h"
#import "IJSVG.h"
#import "DragTextField.h"
@interface ViewController : NSViewController<DragDropViewDelegate>

@property (weak) IBOutlet NSTextField *size;
@property (weak) IBOutlet NSTextField *name;
@property (weak) IBOutlet DragTextField *path;
@property (weak) IBOutlet DragImageView *svgImage;
@property (weak) IBOutlet NSImageView *pngImage;
@property (copy) NSString *svgPath;
@end

