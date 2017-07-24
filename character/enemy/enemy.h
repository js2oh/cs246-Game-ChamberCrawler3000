#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    public:
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif /* ENEMY_H */
