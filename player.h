
#include <SDL2/SDL.h>
#ifndef PLAYER_H
#define PLAYER_H

// Player 類別定義
class Player {
private:
    int x, y;           // 主角的位置
    int width, height;  // 主角的尺寸
    int speed;          // 主角的移動速度
    SDL_Color color;    // 主角的顏色

public:
    // 建構函式
    Player(int startX, int startY, int w, int h, int moveSpeed, SDL_Color c);

    // 處理移動邏輯
    void move(const Uint8* keyState, int screenWidth, int screenHeight);

    // 渲染主角
    void render(SDL_Renderer* renderer) const;
};

#endif // PLAYER_H
