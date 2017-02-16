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
 * @version 0.0.1 - Wed Feb  12 2017
 */

/**
 * @file quadtree.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "quadtree.h"

/**
 * A complete description of the function.
 * It creates a quad tree,empty for the moment.
 * @return qtree a quad tree cretaed by the function.
 */

extern quadtree create_quadtree(){
   int i;
   quadtree qtree;
   *(qtree.sons)=NULL;
   qtree.m0=0;
   for (i=0;i<3;i++){
      qtree.m1[i]=0;
      qtree.m2[i]=0;
   }
   return qtree;
}

/**
 * A complete description of the function.
 * It divides a quad tree in four sons.
 * @param qtree a quad tree
 */

extern void quadtree_subdivide(quadtree qtree){
   int i;
   for (i=0;i<4;i++){
      (*(qtree.sons[i]))=create_quadtree();
   } 
}

/**
 * A complete description of the function.
 * It removes all a quad tree.
 * @param qtree a quad tree
 */

extern void delete_quadtree(quadtree qtree){
   int i;
   for (i=0;i<4;i++){
      if(*((*(qtree.sons[i])).sons)!=NULL){
         delete_quadtree(*(qtree.sons[i]));
      }
      *((*(qtree.sons[i])).sons)=NULL;
   }
}

/**
 * A complete description of the function.
 * It creates a quad tree. It cuts nodes, in order to var<sill.
 * @param picture an image that the user wants to divide.
 * @param sill the sill that var has to be under.
 * @return qtree a quad tree of the picture.
 */

extern quadtree split_image(image picture,double sill,int xmin,int ymin,int xmax,int ymax){ 
   int i;
   quadtree qtree;
   qtree=create_quadtree();
   double* m0;
   double* m1;
   double* m2;
   double var;
   give_moments(picture,xmin,ymin,xmax,ymax,m0,m1,m2);
   var=((*m2)-((*m1)*(*m1))/(*m0))/(*m0);
   if(var>sill){
      quadtree_subdivide(qtree);
      for (i=0;i<4;i++){
         (*(qtree.sons[i]))=split_image(picture,sill,xmin/2,ymin/2,xmax/2,ymax/2);
      }
   }
   return qtree;
}
   
   
   
/**
 * A complete description of the function.
 * It draws the borders of the leafs of the quadtree on a chosen image.
 * @param picture an image on which the quadtree in drawn.
 * @param qtree the quadtree whose leafs are to be drawn.
 * @param color the color of the border of the leafs.
 */


extern void _draw_quadtree(image picture,quadtree qtree,unsigned char* color, int xmin, int ymin, int xmax, int ymax){
   width=(xmax-xmin)/2;
   height=(ymax-ymin)/2;
   if(qtree != NULL){
      draw_square(picture, xmin, ymin, int xmax, int ymax, color);
      _draw_quadtree(picture, qtree->sons[0], color, xmin, ymin, xmin + width, ymin + height);
      _draw_quadtree(picture, qtree->sons[1], color, xmin + width, ymin, xmax, ymin + height);
      _draw_quadtree(picture, qtree->sons[2], color, xmin + width, ymin + height, xmax, ymax);
      _draw_quadtree(picture, qtree->sons[3], color, xmin, ymin + height, xmin + width, ymax);
   }
}
   
   
   
extern quadtree create_default_quadtree(int h){
   quadtree qtree;
   if(h < 0){
        return NULL;
    }
    qtree = create_quadtree();
    if(h == 0){
        return qtree;
    }
   
   
   

if(quad->sons[0]){
        init_quadtree(self, quad->sons[0], xmin, ymin, xmin + width, ymin + height);
        init_quadtree(self, quad->sons[1], xmin + width, ymin, xmax, ymin + height);
        init_quadtree(self, quad->sons[2], xmin + width, ymin + height, xmax, ymax);
        init_quadtree(self, quad->sons[3], xmin, ymin + height, xmin + width, ymax);

        for(i = 0; i < NB_CHILD; i++){
            quad->M0 += quad->sons[i]->M0;
            quad->M1[0] += quad->sons[i]->M1[0];
            quad->M2[0] += quad->sons[i]->M2[0];
        }
    }
}
