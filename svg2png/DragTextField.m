//
//  DragTextField.m
//  svg2png
//
//  Created by coco on 15/9/1.
//  Copyright (c) 2015年 coco. All rights reserved.
//

#import "DragTextField.h"

@implementation DragTextField
- (id) initWithFrame:(NSRect)frameRect {
  self = [super initWithFrame:frameRect];
  if (self) {
    [self registerForDraggedTypes:@[NSFilenamesPboardType]];
  }
  return self;
}

-(NSDragOperation)draggingEntered:(id<NSDraggingInfo>)sender{
  NSPasteboard *pboard = [sender draggingPasteboard];
  
  if ([[pboard types] containsObject:NSFilenamesPboardType]) {
    return NSDragOperationCopy;
  }
  
  return NSDragOperationNone;
}

-(BOOL)prepareForDragOperation:(id<NSDraggingInfo>)sender{
  // 1）、获取拖动数据中的粘贴板
  NSPasteboard *zPasteboard = [sender draggingPasteboard];
  // 2）、从粘贴板中提取我们想要的NSFilenamesPboardType数据，这里获取到的是一个文件链接的数组，里面保存的是所有拖动进来的文件地址，如果你只想处理一个文件，那么只需要从数组中提取一个路径就可以了。
  NSArray *list = [zPasteboard propertyListForType:NSFilenamesPboardType];
  self.stringValue = list[0];
  return YES;
}

@end
