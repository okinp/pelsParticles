#include "ParticleBase.h"


ParticleBase::ParticleBase(void)
    :m_Pos( ci::Vec2f::zero() ),
     m_Vel( ci::Vec2f::zero() ),
     m_Acc( ci::Vec2f::zero() ),
     m_hasStarted( false )
{

}

ParticleBase::ParticleBase( ci::Vec2f &pos, ci::Vec2f &acc )
    :m_Pos( pos ),
     m_Vel( ci::Vec2f::zero() ),
     m_Acc( acc ),
     m_hasStarted(false)
{

}

ParticleBase::~ParticleBase(void)
{

}
void ParticleBase::setArrayIndex(const int &idx )
{
    m_ArrayIndex = idx;
}
void ParticleBase::setPositionArrayReference( float* const posVbo )
{
    m_positionsVBO = posVbo;
}

void ParticleBase::startMoving()
{
    m_hasStarted = true;
}

void ParticleBase::update()
{
  if ( m_hasStarted )
  {
      m_Vel += m_Acc;
      m_Pos += m_Vel;
      m_Acc*= 0;
  }
}

void ParticleBase::addAcceleration( const ci::Vec2f& accel )
{
    m_Acc+=accel;
}

ci::Vec2f& ParticleBase::getPos()
{
    return m_Pos;
}

void ParticleBase::resetParticle( ci::Vec2f& pos, ci::Vec2f& acc )
{
    m_Pos = pos;
    m_Acc = acc;
    m_hasStarted = false;
}

void ParticleBase::setPositionArrayAtParticleIndex( int &pIdx, const ci::Vec2f &pos)
{ 
        int halfWidth = 20;
        m_positionsVBO[ pIdx*8 + 0 ] = pos.x - halfWidth;
        m_positionsVBO[ pIdx*8 + 1 ] = pos.y - halfWidth;

        m_positionsVBO[ pIdx*8 + 2 ] = pos.x + halfWidth;
        m_positionsVBO[ pIdx*8 + 3 ] = pos.y - halfWidth;

        m_positionsVBO[ pIdx*8 + 4 ] = pos.x + halfWidth;
        m_positionsVBO[ pIdx*8 + 5 ] = pos.y + halfWidth;

        m_positionsVBO[ pIdx*8 + 6 ] = pos.x - halfWidth;
        m_positionsVBO[ pIdx*8 + 7 ] = pos.y + halfWidth;
}