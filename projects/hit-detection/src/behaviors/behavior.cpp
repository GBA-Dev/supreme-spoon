#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Behavior
{
public:
    virtual ~Behavior() = default;
    virtual void update() = 0;
};

#endif // BEHAVIOR_H
