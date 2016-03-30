//
//  load-mesh.h
//  PA3
//
//

#ifndef load_mesh_h
#define load_mesh_h
#include <string>
#include <vector>
#include <OpenGL/gl.h>

struct Vector3
{
    float			x, y, z;
};

struct Triangle
{
    unsigned int 	indices[3];
};

class Mesh {
public:
    std::vector<Vector3>	gPositions;
    std::vector<Vector3>	gNormals;
    std::vector<Triangle>	gTriangles;
    GLfloat                 *gPositionList;
    GLfloat                 *gNormalsList;
    GLuint                  *gIndicesList;
    int                     posSize;
    int                     normSize;
    int                     indexSize;
    Mesh(std::string);
    void load_mesh(std::string fileName);
    void initialize();
private:
    void tokenize(char*, std::vector<std::string>&, const char*);
    int face_index(const char*);
};


#endif /* load_mesh_h */
