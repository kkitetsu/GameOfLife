//
//  engine.cpp
//  lifeOfGame
//
//  Created by Kaku, Kitetsu on 2020/07/01.
//

#include "engine.hpp"

using namespace cinder;

Engine::Engine(int w, int h) {
    width = w;
    height = h;
}

void Engine::InitializeBoard() {
    SetBoardToAllDead();
    MakeRandomBoard();
}

void Engine::Update() {
    for (size_t r = 0; r < 100; r++) {
        for (size_t c = 0; c < 100; c++) {
            if (board[r][c] == 0 && GetAliveNumNearby(r, c) == 3) {
                new_board[r][c] = 1;
            } else if (board[r][c] == 1 && (GetAliveNumNearby(r, c) == 3 || GetAliveNumNearby(r, c) == 4)) {
                new_board[r][c] = 1;
            } else if (board[r][c] == 1 && (GetAliveNumNearby(r, c) <= 2 || GetAliveNumNearby(r, c) >= 5)) {
                new_board[r][c] = 0;
            }
        }
    }
}

void Engine::Draw() {
    cinder::gl::color(Color(1, 1, 1));
    for (size_t r = 0; r < 100; r++) {
        for (size_t c = 0; c < 100; c++) {
            if (new_board[r][c] == 1) {
                gl::drawSolidRect(Rectf(r * 10, c * 10, r * 10 + 10, c * 10 + 10));
            }
        }
    }
}

int Engine::GetAliveNumNearby(int x, int y) {
    int live_count = 0;
    for (int r = x - 1; r <= x + 1; r++) {
        for (int c = y - 1; c <= y + 1; c++) {
            if (board[r][c] == 1) {
                live_count++;
            }
        }
    }
    return live_count;
}

void Engine::BoardReset() {
    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
            board[r][c] = new_board[r][c];
            new_board[r][c] = 0;
        }
    }
}

void Engine::SetBoardToAllDead() {
    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
            board[r][c] = 0;
        }
    }
}

void Engine::MakeRandomBoard() {
    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
            int temp = rand();
            if (temp < 200000000) {
                board[r][c] = 1;
            }
        }
    }
}

void Engine::MakeFrog() {
    board[15][15] = 1;
    board[15][16] = 1;
    board[15][17] = 1;
    board[16][16] = 1;
    board[16][17] = 1;
    board[16][18] = 1;
}

void Engine::MakeBlinker() {
    board[10][20] = 1;
    board[10][21] = 1;
    board[10][22] = 1;
}

void Engine::MakeGlider() {
    board[10][10] = 1;
    board[11][10] = 1;
    board[12][10] = 1;
    board[10][11] = 1;
    board[11][12] = 1;
}

void Engine::MakeStillLife() {
    
}

void Engine::MakeOscillators() {
    MakeFrog();
    MakeBlinker();
}

void Engine::MakeSpaceShips() {
    MakeGlider();
}
