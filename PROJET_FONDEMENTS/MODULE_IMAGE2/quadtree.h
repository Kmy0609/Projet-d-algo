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

extern quadtree create_quadtree();


extern void quadtree_subdivide(quadtree qtree);


extern void delete_quadtree(quadtree qtree);


extern quadtree split_image(image picture,double sill,int xmin,int ymin,int xmax,int ymax);



#endif /* QUADTREE_H */

