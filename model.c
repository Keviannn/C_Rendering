//
// Created by kevia on 28/02/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "model.h"

//Creates a model struct based on a .obj file
Model* model_loader(const char* filename) {
    FILE* file = fopen(filename, "r");
    int num_vertices = 0;
    int num_faces = 0;

    if (!file) {
        fprintf(stderr, "Error: specified file does not exist.\n");
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (line[0] == 'v' && line[1] == ' ')
            num_vertices++;
        else if (line[0] == 'f' && line[1] == ' ')
            num_faces++;
    }

    Vertex* vertices = (Vertex*) malloc(num_vertices * sizeof(Vertex));
    Face* faces = (Face*) malloc(num_faces * sizeof(Face));

    if (!vertices || !faces) {
        fprintf(stderr, "Error allocating memory for vertices and faces\n");
        free(vertices);
        free(faces);
        return NULL;
    }

    rewind(file);

    int vertex_index = 0;
    int face_index = 0;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (line[0] == 'v' && line[1] == ' ') {
            sscanf(line, "v %f %f %f", &vertices[vertex_index].c1, &vertices[vertex_index].c2, &vertices[vertex_index].c3);
            vertex_index++;
        }
        else if (line[0] == 'f' && line[1] == ' ')
        {
            sscanf(line, "f %d %d %d", &faces[face_index].v1, &faces[face_index].v2, &faces[face_index].v3);
            face_index++;
        }
    }

    Model* model = (Model*) malloc(sizeof(Model));
    model->vertices = vertices;
    model->faces = faces;
    model->num_vertices = num_vertices;
    model->num_faces = num_faces;

    fclose(file);
    return model;
}

//Frees all the memory related to the model
void model_unload(Model* model) {
    if (model) {
        free(model->vertices);
        free(model->faces);
        free(model);
    }
}