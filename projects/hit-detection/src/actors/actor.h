#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
public:
    Actor();
    virtual ~Actor();

    virtual void update();
    virtual void draw();
};

#endif // ACTOR_H
