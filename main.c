#include "model.h"

int main() {
    Model* model = model_loader("/home/kevia/Desktop/renderizado/c_rendering/triangle.obj");
    model_unload(model);
    return 0;
}
