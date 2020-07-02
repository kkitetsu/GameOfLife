#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "engine.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class lifeOfGameApp : public App {
  public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void keyDown( KeyEvent event ) override;
    void update() override;
    void draw() override;
  private:
    Engine engine{1000, 1000};
    float rate = 5.0f;
};

void lifeOfGameApp::setup()
{
    setFrameRate(rate);
    setWindowSize(1000, 1000);
    engine.InitializeBoard();
}

void lifeOfGameApp::mouseDown( MouseEvent event )
{
}

void lifeOfGameApp::update()
{
    engine.Update();
}

void lifeOfGameApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    engine.Draw();
    engine.BoardReset();
}

void lifeOfGameApp::keyDown( KeyEvent event )
{
    if (event.getChar() == 'q') {
        rate++;
        setFrameRate(rate);
    }
    if (event.getChar() == 'a') {
        rate--;
        setFrameRate(rate);
    }
    if (event.getChar() == 'r') {
        engine.InitializeBoard();
    }
    if (event.getChar() == '1') {
        engine.BoardReset();
        engine.MakeOscillators();
    }
    if (event.getChar() == '2') {
        engine.BoardReset();
        engine.MakeStillLife();
    }
    if (event.getChar() == '3') {
        engine.BoardReset();
        engine.MakeSpaceShips();
    }
    if (event.getChar() == '9') {
        engine.BoardReset();
        engine.MakeOscillators();
        engine.MakeSpaceShips();
    }
    if (event.getChar() == 'g') {
        engine.BoardReset();
        engine.MakeGalaxy();
    }
    if (event.getChar() == 'b') {
        engine.BoardReset();
        engine.MakeAcorn();
    }
}

CINDER_APP( lifeOfGameApp, RendererGl )
