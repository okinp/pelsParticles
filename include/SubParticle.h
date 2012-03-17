#pragma once
#include "ParticleBase.h"
#include "cinder/Vector.h"
class SubParticle : public ParticleBase
{
public:
    SubParticle();
    SubParticle( ci::Vec2f& pos, ci::Vec2f& acc );
    ~SubParticle();
};

