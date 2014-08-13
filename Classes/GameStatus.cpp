#include "GameStatus.h"

void GameStatus::gameReady()
{
    _gameStatusEnum = GAME_STATUS_READY;
}

bool GameStatus::isReady()
{
    return _gameStatusEnum == GAME_STATUS_READY;
}

void GameStatus::gameShooting()
{
    _gameStatusEnum = GAME_STATUS_SHOOTING;

}

bool GameStatus::isShooting()
{
    return _gameStatusEnum == GAME_STATUS_SHOOTING;
}

void GameStatus::gameGoal()
{
    _gameStatusEnum = GAME_STATUS_GOAL;
}

bool GameStatus::isGoal()
{
    return _gameStatusEnum == GAME_STATUS_GOAL;
}

void GameStatus::gameOver()
{
    _gameStatusEnum = GAME_STATUS_OVER;
}

bool GameStatus::isOver()
{
    return _gameStatusEnum == GAME_STATUS_OVER;
}
