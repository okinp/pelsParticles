#pragma once
#include "Particle.h"
class Affector
{
public:
    Affector(void);
    virtual ~Affector(void);
    void applyForce( Particle& p );
private:
    float m_Gravity;
    float m_minRedius;
    float m_maxRedius;
    bool m_IsRepeller;
};

