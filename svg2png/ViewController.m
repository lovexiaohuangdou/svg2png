//
//  ViewController.m
//  svg2png
//
//  Created by coco on 15/9/1.
//  Copyright (c) 2015年 coco. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];

  // Do any additional setup after loading the view.
}
- (IBAction)convert:(id)sender {
  [self exeCommand:self.svgPath path2:self.path.stringValue size:self.size.stringValue name:self.name.stringValue];
  NSString *path = [NSString stringWithFormat:@"%@/%@.png",self.path.stringValue, self.name.stringValue];
  NSImage *image = [[NSImage alloc] initWithContentsOfFile: path];
  if (image != nil) {
    self.pngImage.image = image;
  } else {
    NSLog(@"convert failed");
  }
}

- (void)setRepresentedObject:(id)representedObject {
  [super setRepresentedObject:representedObject];
}

-(void)dragDropViewFileList:(NSArray*)fileList view:(NSView *)view {
  NSString *filePath = fileList[0];
  IJSVG *svg = [[IJSVG alloc] initWithFile: filePath];
  NSImage *svgImage = [svg imageWithSize:NSMakeSize(100.f,100.f)];
  self.svgImage.image = svgImage;
  self.svgPath = filePath;
}


- (void) exeCommand:(NSString *) path1 path2:(NSString *)path2 size:(NSString *) size name:(NSString *) name {
  NSString *cmd = [NSString stringWithFormat:@"qlmanage -t -s %@ -o %@ %@", size, path2, path1];
  [[NSTask launchedTaskWithLaunchPath:@"/bin/sh"
                            arguments:@[@"-c", cmd]]
   waitUntilExit];
  NSArray *array = [self.svgPath componentsSeparatedByString:@"/"];
  NSString *fileName = [NSString stringWithFormat:@"%@.png",[array lastObject]];
  NSString *mv = [NSString stringWithFormat:@"mv %@/%@ %@/%@.png",self.path.stringValue, fileName, self.path.stringValue, name];
  [[NSTask launchedTaskWithLaunchPath:@"/bin/sh"
                            arguments:@[@"-c", mv]]
   waitUntilExit];

}

@end
