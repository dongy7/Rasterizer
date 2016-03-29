//
//  frame-timer.h
//  PA3
//
//  Created by Dong Yeop Lee on 29/03/2016.
//  Copyright © 2016 Dong Yeop Lee. All rights reserved.
//

#ifndef frame_timer_h
#define frame_timer_h

void init_timer();
void start_timing();
float stop_timing();

float gTotalTimeElapsed;
int gTotalFrames;

#endif /* frame_timer_h */
