#pragma once
#define NUM_PARTICLES 10000
#define NUM_SUB_PARTICLES 5
#include <list>
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "Affector.h"

class ParticleManager
{
 public:
    ParticleManager(void);
    ~ParticleManager(void);

    void setup();
    void update();
    void draw();

    void addAffector(ci::Vec2f pos, float minRadius, float maxRadius, float mass, bool isRepeller );
 private:
     void initializeVbos();
     void initializeData();
     GLuint m_ParticleVboIds[3];

     float mVboPositions[ NUM_PARTICLES*( NUM_SUB_PARTICLES + 1)*4*2 ];
     float mVboColors[ NUM_PARTICLES*( NUM_SUB_PARTICLES + 1 )*4*4 ];
     float mVboTextureCoords[ NUM_PARTICLES*( NUM_SUB_PARTICLES + 1 )*4*2 ];

     std::list< Affector > m_Affectors; 
     std::list< Particle > m_Particles;
     std::list< Particle >::iterator m_Iter;

     int  m_TotalParticles;

     ci::Vec2f m_EmitterPos;
     ci::Vec2f m_EmitterAcc;
     int m_EmissionRate; // per Frame  ( maybe per second? ) 
};

