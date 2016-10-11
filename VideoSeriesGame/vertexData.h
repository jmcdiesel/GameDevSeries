//
//  vertexData.h
//  VideoSeriesGame
//
//  Created by Joshua McDonald on 10/8/16.
//  Copyright (c) 2016 Joshua McDonald. All rights reserved.
//

#ifndef VideoSeriesGame_vertexData_h
#define VideoSeriesGame_vertexData_h

typedef struct {
    struct {
        GLfloat x = 0.0f;
        GLfloat y = 0.0f;
        GLfloat z = 0.0f;
        GLfloat w = 1.0f;
    } position;
    struct {
        GLbyte r = 255;
        GLbyte g = 255;
        GLbyte b = 255;
        GLbyte a = 255;
    } color;
} vertexData;

#endif
