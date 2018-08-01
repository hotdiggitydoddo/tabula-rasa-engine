#pragma once

#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include "Bullet.h"

class Level;

class Gun
{
public:
    Gun(const std::string name, int fireFate, int bulletsPerShot, int bulletDamage, int maxBullets, float spread,  float bulletSpeed,  int bulletLifetime = 500);
    ~Gun();

    void Init(Level* level);
    void Update();
    void Fire(const glm::vec2& pos, const glm::vec2& direction);

private:
    std::string _name;
    int _fireRate;
    int _bulletsPerShot;
    int _maxBullets;
    float _spread;

    // bullet info
    std::vector<Bullet*> _bullets;
    int _bulletDamage;
    float _bulletSpeed;
    int _bulletLifetime;

    int _frameCounter;
    bool _canFire;
};
