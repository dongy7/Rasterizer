//
//  load-mesh.h
//  PA3
//
//  Created by Dong Yeop Lee on 29/03/2016.
//  Copyright © 2016 Dong Yeop Lee. All rights reserved.
//

#ifndef load_mesh_h
#define load_mesh_h

struct Vector3
{
    float			x, y, z;
};

struct Triangle
{
    unsigned int 	indices[3];
};

void load_mesh(std::string fileName);

#endif /* load_mesh_h */
