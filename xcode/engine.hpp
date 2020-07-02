//
//  engine.hpp
//  lifeOfGame
//
//  Created by Kaku, Kitetsu on 2020/07/01.
//

#ifndef engine_hpp
#define engine_hpp

#include <stdio.h>

using namespace cinder::app;

class Engine {
public:
    Engine(int w, int h);
    void InitializeBoard();
    void Update();
    void Draw();
    void SetBoardToAllDead();
    void MakeGlider();
    void MakeBlinker();
    void MakeFrog();
    void MakeRandomBoard();
    void MakeStillLife();
    void MakeOscillators();
    void MakeSpaceShips();
    void MakeBlock();
    void MakeGalaxy();
    void MakeAcorn();
    int GetAliveNumNearby(int x, int y);
    void BoardReset();
private:
    int width;
    int height;
    int board[100][100];
    int new_board[100][100];
    int x = 0;
    int y = 0;
    const cinder::vec2 center = getWindowCenter();
};

#endif /* engine_hpp */
