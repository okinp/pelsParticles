#include "Particle.h"


Particle::Particle(void)
    :ParticleBase(),
     m_numChildren(0)
{
    setupChildren();
}

Particle::Particle( const int &nChildren, ci::Vec2f &pos, ci::Vec2f &acc )
    :ParticleBase( pos, acc ),
     m_numChildren( nChildren )
{
    setupChildren();
}

Particle::~Particle(void)
{

}

void Particle::setup()
{

}
void Particle::update()
{
    if ( m_hasStarted )
    {
        //Update parent
        ParticleBase::update();
        //update arrays

        //Update Children
        for ( m_Iter = mChildren.begin(); m_Iter!= mChildren.end(); ++m_Iter )
        {
            m_Iter->update();
        }
    }
}
void Particle::setupChildren()
{
   
}
bool Particle::isOutside()
{
    return false;
}

