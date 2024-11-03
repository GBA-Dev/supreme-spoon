#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    Scene();
    virtual ~Scene();

    virtual void update();
    virtual void draw();
};

#endif // SCENE_H
