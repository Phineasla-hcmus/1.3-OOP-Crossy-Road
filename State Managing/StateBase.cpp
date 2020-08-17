#include "StateBase.h"
#include"Game.h"
StateBase::StateBase(Game& game)
    : m_pGame(&game)
{}