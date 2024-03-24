//
// Created by kevia on 28/02/24.
//

// This heather defines the functions related to the creation and
// treatment of the 3d model structs

#ifndef C_RENDERING_MODEL_H
#define C_RENDERING_MODEL_H

#define MAX_LINE_SIZE 256

typedef struct {
    float c1, c2, c3;
} Vertex;

typedef struct {
    int v1, v2, v3;
} Face;

typedef struct {
    Vertex* vertices;
    Face* faces;
    int num_vertices;
    int num_faces;
} Model;

Model* model_loader(const char* filename);
void model_unload(Model* model);

#endif //C_RENDERING_MODEL_H
