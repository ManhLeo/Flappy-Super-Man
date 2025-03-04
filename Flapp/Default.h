#pragma once

#include <iostream>
#include <vector>
#include <time.h>



const int SCREEN_WIDTH = 1159; 
const int SCREEN_HEIGHT = 652; 
const float GRAVITY = 0.5f;
const float JUMP_HEIGHT = -10.0f;
const int numPipes = 100; // Số lượng ống


const float PIPE_WIDTH = 64.0f;  
const float PIPE_HEIGHT = 412.0f; 
const float PIPE_GAP = 200.0f ; 
const float LAND_HEIGHT = 40.0f;

//pipegap = screenheight - pipeheight - landheight

constexpr auto BIRD = "Resource/sup.png";
constexpr auto PIPE = "Resource/Pipe.jpg";
constexpr auto LAND = "Resource/ground2.png";
constexpr auto BACKGROUND = "Resource/background.png";
constexpr auto FONT = "Resource/ARCADE.ttf";
constexpr auto FileHighscore = "Resource/highscore.txt";
constexpr auto MenuBackground = "Resource/Menubackground.png";