#pragma once
#include <vector>
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "ParticleBase.h"
#include "SubParticle.h"

class Particle : public ParticleBase
{
public:
    Particle();
    Particle( const int &nChildren, ci::Vec2f &pos, ci::Vec2f &acc );
    virtual ~Particle(void);
    virtual void setup();
    virtual void update();
    void setPosition( ci::Vec2f pos );
    void setVelocity( ci::Vec2f vel );
    bool isOutside();
    std::vector< SubParticle > mChildren;
    std::vector< SubParticle >::iterator m_Iter;
private:
    int m_numChildren;
    void setupChildren();
};

