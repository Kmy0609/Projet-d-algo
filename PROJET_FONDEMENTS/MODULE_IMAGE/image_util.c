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
 * A complete description of the function.
 *
 * @param par1 description of the paramter par1.
 * @param par2 description of the paramter par2.
 * @return description of the result.
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



extern void give_moments(struct image picture,int xmin,int ymin,int xmax,int ymax,int* m0,double* m1,double* m2){
   point p;
   COORDX(p)=xmin;
   COORDY(p)=ymin;
   int i,j;
   if(picture.dim==3){
      *m0=(xmax-xmin)*(ymax-ymin)/3;
      m1[0]=0;
      m1[1]=0;
      m1[2]=0;
      for(i=0;i<(ymax-ymin)/3;i++){
         for(j=0;j<(xmax-xmin);j++){
            m1[0]+=image_get_comp(picture,p,0);
            m1[1]+=image_get_comp(picture,p,1);
            m1[2]+=image_get_comp(picture,p,2);
            MOVE_RIGHT_POINT(p);
         }
         COORDX(p)=xmin;
         MOVE_DOWN_POINT(p);
      }
      m2[0]=0;
      m2[1]=0;
      m2[2]=0;
      for(i=0;i<(ymax-ymin)/3;i++){
         for(j=0;j<(xmax-xmin);j++){
            m2[0]+=(image_get_comp(picture,p,0))*(image_get_comp(picture,p,0));
            m2[1]+=(image_get_comp(picture,p,1))*(image_get_comp(picture,p,1));
            m2[2]+=(image_get_comp(picture,p,2))*(image_get_comp(picture,p,2));
            MOVE_RIGHT_POINT(p);
         }
         COORDX(p)=xmin;
         MOVE_DOWN_POINT(p);
      }
      printf("M0 = %d\nM1 = {%lf, %lf %lf}\nM2 = {%lf, %lf %lf}", *m0, m1[0], m1[1], m1[2], m2[0], m2[1], m2[2]);
   }
   else{
      *m0=(xmax-xmin)*(ymax-ymin);
      *m1=0;
      for(i=0;i<(ymax-ymin);i++){
         for(j=0;j<(xmax-xmin);j++){
            *m1+=image_get_comp(picture,p,0);
            MOVE_RIGHT_POINT(p);
         }
         COORDX(p)=xmin;
         MOVE_DOWN_POINT(p);
      }
      *m2=0;
      for(i=0;i<(ymax-ymin);i++){
         for(j=0;j<(xmax-xmin);j++){
            *m1+=(image_get_comp(picture,p,0))*(image_get_comp(picture,p,0));
            MOVE_RIGHT_POINT(p);
         }
         COORDX(p)=xmin;
         MOVE_DOWN_POINT(p);
      } 
      printf("M0 = %d\nM1 = %lf\nM2 = %lf", *m0, *m1, *m2);
   }
}
