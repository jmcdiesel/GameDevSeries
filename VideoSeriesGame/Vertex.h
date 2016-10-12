//
//  Vertex.h
//  VideoSeriesGame
//
//  Created by Joshua McDonald on 10/10/16.
//  Copyright (c) 2016 Joshua McDonald. All rights reserved.
//

#include <OpenGL/gl3.h>

#ifndef VideoSeriesGame_Vertex_h
#define VideoSeriesGame_Vertex_h

typedef struct {
    
    struct {
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;
    } position;
    
    struct {
        char r = 255;
        char g = 255;
        char b = 255;
        char a = 255;
        
    } color;
    
} Vertex;

#endif
