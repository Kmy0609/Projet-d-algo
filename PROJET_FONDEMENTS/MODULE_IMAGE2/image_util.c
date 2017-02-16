/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Guillaume ZUNINO <guillaume.zunino@ecole.ensicaen.fr> 
 * @version 0.0.1 - Wed Feb  8 2017
 */

/**
 * @file image_util.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "image_util.h"


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

extern void draw_square(image picture, int xmin, int ymin, int xmax, int ymax, unsigned char* color){
   int i = ymin;
   do{
      image_write_pixel(picture,xmin,i,color);
      image_write_pixel(picture,xmax,i,color);
      i++;
   }
   while(i<ymax);
   i=xmin;
   do{
      image_write_pixel(picture,i,ymin,color);
      image_write_pixel(picture,i,ymax,color);
      i++;
   }
   while(i<xmax);
}

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

extern void give_moments(image picture,int xmin,int ymin,int xmax,int ymax,double* m0,double* m1,double* m2){
   int i,j,k,dim;
   unsigned char* pixel;
   dim=image_give_dim(picture);
   pixel=malloc(dim*sizeof(unsigned char));
   *m0=(xmax-xmin)*(ymax-ymin);
   for(i=ymin;i<ymax;i++){
      for(j=xmin;j<xmax;j++){
         image_read_pixel(picture,i,j,pixel);
         for(k=0;k<dim;k++){
            m1[k]+=pixel[k];
            m2[k]+=pixel[k]*(pixel[k]);
         }
      }
   }
   free(pixel);
}
