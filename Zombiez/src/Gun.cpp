#include "Gun.h"
#include "Level.h"

Gun::Gun(const std::string name, int fireFate, int bulletsPerShot, int bulletDamage,
         int maxBullets, float spread,  float bulletSpeed, int bulletLifetime) :
    _name(name),
    _fireRate(fireFate),
    _bulletsPerShot(bulletsPerShot),
    _spread(spread),
    _bulletDamage(bulletDamage),
    _bulletSpeed(bulletSpeed),
    _bulletLifetime(bulletLifetime),
    _frameCounter(0),
    _canFire(false),
    _maxBullets(maxBullets)
{

}

Gun::~Gun()
{

}



// this is called from player when mouse is down
void Gun::Fire(const glm::vec2& pos, const glm::vec2& direction)
{
    if (!_canFire)
        return;

    for (int i = 0; i < _bulletsPerShot; i++)
    {
        for (auto& bullet : _bullets)
        {
            if (bullet->IsAlive())
                continue;
            bullet->Activate(pos, direction, _bulletSpeed);
            break;
        }
    }
    _canFire = false;
}

void Gun::Update()
{
    if (!_canFire)
        _frameCounter++;

    if (_frameCounter >= _fireRate)
    {
        _canFire = true;
        _frameCounter = 0;
    }
}

void Gun::Init(Level* level)
{
    auto actors = level->GetActors();
    for (int i = 0; i < _maxBullets; i++)
    {
        Bullet* b = new Bullet(glm::vec2(0), glm::vec2(0), 0.0f, _bulletLifetime);
        actors->push_back(b);
        _bullets.push_back(b);
    }
}
