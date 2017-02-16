#ifndef QUADTREE_H
#define QUADTREE_H


#include <stdio.h> 
#include <math.h>
#include "point.h"
#include "image.h"
#include "classe.h"
#include "move_type.h"
#include "objet.h"
#include "type_obj.h"
#include "exit_if.h"
#include "image_util.h"


typedef struct quadtree* pQuadtree;

typedef struct quadtree
{
   pQuadtree sons[4];
   double* m0;
   double m1[3], m2[3];
} quadtree;



/**
 * It creates a quad tree,empty for the moment.
 * @return qtree a quad tree created by the function.
 */
extern quadtree create_quadtree();



/**
 * It divides a quad tree in four sons.
 * @param qtree a quad tree
 */
extern void quadtree_subdivide(quadtree qtree);




/**
 * It removes all a quad tree.
 * @param qtree a quad tree
 */
extern void delete_quadtree(quadtree qtree);



/**
 * It creates a quad tree. It cuts nodes, in order to var<sill.
 * @param picture an image that the user wants to divide.
 * @param sill the sill that var has to be under.
 * @param xmin | 
 * @param ymin | -> the coordinates of a square in the picture
 * @param xmax |
 * @param ymax |
 * @return qtree a quad tree of the picture.
 */
extern quadtree split_image(image picture,double sill,int xmin,int ymin,int xmax,int ymax);



/**
 * It draws the borders of the leaves of the quadtree in a chosen image.
 * @param picture an image in which the quadtree is drawn.
 * @param qtree the quadtree whose leaves have to be drawn.
 * @param color the color of the border of the leaves.
 * @param xmin | 
 * @param ymin | -> the coordinates of a square in the picture
 * @param xmax |
 * @param ymax |
 */
extern void draw_quadtree(image picture,quadtree qtree,unsigned char* color, int xmin, int ymin, int xmax, int ymax);




/**
 * It creates a quadtree, with all his leaves having a height of h.
 * @param h height of every leaf.  
 * @return qtree a quadtree created by this function
 */
extern quadtree create_default_quadtree(int h);




/**
 * A complete description of the function.
 * It calculates the momenta of all the nodes of a quadtree from the momenta of the leaves.
 * @param qtree a quadtree.
 * @param picture an image.
 */
extern void init_quadtree(quadtree qtree,image picture);



/**
 * A complete description of the function.
 * It deletes every leaf whose variance is greater than the sill 
 * and every son of a node whose variance is lower than the sill.
 * @param picture an image on which the quadtree in drawn.
 * @param qtree the quadtree whose leafs are to be drawn.
 * @param sill a limit number.
 */
extern void update_quadtree(quadtree qtree,image picture,double sill);


#endif /* QUADTREE_H */

