//
//  DragImageView.h
//  svg2png
//
//  Created by coco on 15/9/1.
//  Copyright (c) 2015年 coco. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@protocol DragDropViewDelegate <NSObject>
-(void)dragDropViewFileList:(NSArray*)fileList view:(NSView *)view;
@end

@interface DragImageView : NSImageView
@property (weak) IBOutlet id<DragDropViewDelegate> delegate;
@end
