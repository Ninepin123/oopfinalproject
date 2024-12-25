#include "Player.h"
#include <SDL2/SDL.h>
// 建構函式
Player::Player(int startX, int startY, int w, int h, int moveSpeed, SDL_Color c)
    : x(startX), y(startY), width(w), height(h), speed(moveSpeed), color(c) {}

// 移動主角
void Player::move(const Uint8* keyState, int screenWidth, int screenHeight) {
    if (keyState[SDL_SCANCODE_UP]) y -= speed;
    if (keyState[SDL_SCANCODE_DOWN]) y += speed;
    if (keyState[SDL_SCANCODE_LEFT]) x -= speed;
    if (keyState[SDL_SCANCODE_RIGHT]) x += speed;

    // 邊界檢查
    if (x < 0) x = 0;
    if (x + width > screenWidth) x = screenWidth - width;
    if (y < 0) y = 0;
    if (y + height > screenHeight) y = screenHeight - height;
}

// 渲染主角
void Player::render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255); // 設定顏色
    SDL_Rect rect = {x, y, width, height}; // 主角的位置和尺寸
    SDL_RenderFillRect(renderer, &rect); // 繪製矩形
}
