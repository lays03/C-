#include "player.h"

Player::Player(int index, string name, double score)
{
    this->m_Index = index;
    this->m_Name = name;
    this->m_Score = score;
}

Player::~Player()
{

}