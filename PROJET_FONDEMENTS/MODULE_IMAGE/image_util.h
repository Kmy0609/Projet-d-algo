#ifndef IMAGE_UTIL_H
#define IMAGE_UTIL_H


#include <stdio.h> 
#include <math.h>
#include "point.h"
#include "image.h"
#include "classe.h"
#include "move_type.h"
#include "objet.h"
#include "type_obj.h"
#include "exit_if.h"

extern void draw_square(image picture, int xmin, int ymin, int xmax, int ymax, unsigned char* color);


extern void give_moments(struct image square,int xmin,int ymin,int xmax,int ymax,int* m0,double* m1,double* m2);


#endif /* IMAGE_UTIL_H */

