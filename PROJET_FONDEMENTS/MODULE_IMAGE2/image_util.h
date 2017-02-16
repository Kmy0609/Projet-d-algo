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


/**
 * It draws a rectangle from the top left point (xmin,ymin) to the bottom right
 * point (xmax,ymax) in a chosen color.
 *
 * @param picture the image on which the square will be drawn.
 * @param xmin abscissa of the top left point.
 * @param ymin ordinate of the top left point.
 * @param xmax abscissa of the bottom right point.
 * @param ymax ordinate of the bottom right point.
 * @param color the color of the square.
 */

extern void draw_square(image picture, int xmin, int ymin, int xmax, int ymax, unsigned char* color);

/**
 * It calculates the momenta in a chosen rectangle.
 *
 * @param picture the image on which the square is drawn.
 * @param xmin abscissa of the top left point.
 * @param ymin ordinate of the top left point.
 * @param xmax abscissa of the bottom right point.
 * @param ymax ordinate of the bottom right point.
 * @param m0 the null order momentum (number of pixel in the square).
 * @param m1 the 1st order momentum (sum of the intensities of all the pixels in each color).
 * @param m0 the 2nd order momentum (sum of the square of the intensities of all the pixels in each color).
 */

extern void give_moments(image picture,int xmin,int ymin,int xmax,int ymax,double* m0,double* m1,double* m2);


#endif /* IMAGE_UTIL_H */

