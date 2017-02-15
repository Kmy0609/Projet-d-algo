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


#include "image_util.h"

typedef struct quadtree* pQuadtree;

typedef struct quadtree
{
   pQuadtree sons[4];
   double M0, M1[3], M2[3];
} quadtree;

/**
 * A complete description of the function.
 * It creates a quad tree,empty for the moment.
 * @return qtree a quad tree cretaed by the function.
 */

extern quadtree create_quadtree(){
   int i;
   quadtree qtree;
   *(qtree.sons)=NULL;
   qtree.M0=0;
   for (i=0;i<3;i++){
      qtree.M1[i]=0;
      qtree.M2[i]=0;
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
   quadtree qtree;
   qtree=create_quadtree();
   double* m0, m1, m2;
   double var;
   give_moments(picture,xmin,ymin,xmax,ymax,m0,m1,m2);
   var=((*m2)-((*m1)*(*m1))/(*m0))/(*m0));
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
 * It draws the borders of the leaves of the quadtree on a chosen image.
 * @param picture an image on which the quadtree in drawn.
 * @param qtree the quadtree whose leaves are to be drawn.
 * @param color the color of the border of the leaves.
 */

extern void draw_quadtree(image picture,quadtree qtree,unsigned char* color){
   qtree=split_image(picture,sill,0,0,picture.largeur,picture.hauteur);
   
}


/**
 * A complete description of the function.
 * It creates a quadtree whose leaves are all the same height.
 * @param h the default height of the leaves.
 * @return qtree the default quadtree.
 */

extern quadtree create_default_quadtree(int h){
   
   return qtree
}


/**
 * A complete description of the function.
 * It claculates the momentums of all the nods of a quadtree from the momentums of the leaves.
 * @param qtree a quadtree.
 * @param picture an image.
 */

extern void init_quadtree(quadtree qtree,image picture){
   
}


/**
 * A complete description of the function.
 * It deletes every leaf whose variance is greater than the sill 
 * and every son of a nod whose variance is lower than the sill.
 * @param picture an image on which the quadtree in drawn.
 * @param qtree the quadtree whose leafs are to be drawn.
 * @param sill a limit number.
 */

extern void update_quadtree(quadtree qtree,image picture,double sill){
   
}



int main(){
   quadtree Q;
   Q=create_quadtree();
   quadtree_subdivide(Q);
   delete_quadtree(Q);
   return 0;
}
