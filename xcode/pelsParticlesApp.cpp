#include "cinder/app/AppBasic.h"
#include "ParticleManager.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class pelsParticlesAppApp : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    ParticleManager* particleSystem;
};

void pelsParticlesAppApp::setup()
{
    particleSystem = new ParticleManager();
    particleSystem->setup();
}
void pelsParticlesAppApp::update()
{
    particleSystem->update();
}
void pelsParticlesAppApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
    particleSystem->draw();
}
void pelsParticlesAppApp::mouseDown( MouseEvent event )
{
    
}

CINDER_APP_BASIC( pelsParticlesAppApp, RendererGl )