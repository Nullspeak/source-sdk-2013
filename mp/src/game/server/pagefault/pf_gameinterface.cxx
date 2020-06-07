/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "gameinterface.h"

void CServerGameClients::GetPlayerLimits(int &minplayers, int &maxplayers, int &defaultMaxPlayers) const {
	/* force singleplayer */
	minplayers = 1;
	maxplayers = 1;
	defaultMaxPlayers = 1;
}

void CServerGameDLL::LevelInit_ParseAllEntities(const char *pMapEntities) {
}
