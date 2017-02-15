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

extern void delete_quadtree(quadtree qtree){ // Pas de condition d'arret ?
   int i;
   for (i=0;i<4;i++){
      if(*((*(qtree.sons[i])).sons)!=NULL){
         delete_quadtree(*(qtree.sons[i]));
         *((*(qtree.sons[i])).sons)=NULL;
      }
   }
}





/**
 * A complete description of the function.
 * It creates a quad tree. It cuts nodes, in order to var<sill.
 * @param picture an image that the user wants to divide.
 * @param sill the sill that var has to be under.
 * @return qtree a quad tree of the picture.
 */

extern quadtree split_image(image picture, double sill){ // J'arrive plus a me procurer le pdf... Tu pourrais le mettre sur le GitHub stp
   var=(1/
}




int main(){
   quadtree Q;
   Q=create_quadtree();
   quadtree_subdivide(Q);
   delete_quadtree(Q);
   return 0;
}
