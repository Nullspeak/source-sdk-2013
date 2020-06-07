/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "tier0/vprof.h"
#include "pf_player.hxx"

extern bool	g_fGameOver;

const char *GetGameDescription() {
	return "Pagefault";
}

void InstallGameRules() {
	CreateGameRulesObject("CPFRules");
}

void ClientGamePrecache() {
	CBaseEntity::PrecacheModel("models/player.mdl");
	CBaseEntity::PrecacheScriptSound("Player.JumpFoley");
	CBaseEntity::PrecacheScriptSound("Player.LandFoley");
}

void GameStartFrame() {
	VPROF("GameStartFrame");

	if(g_pGameRules)
		g_pGameRules->Think();

	if(g_fGameOver)
		return;
}

void ClientPutInServer(edict_t *pEdict, const char *playername) {
	CBasePlayer *pPlayer = CPFPlayer::CreatePlayer("player", pEdict);
	pPlayer->SetPlayerName(playername);
}

void FinishClientPutInServer(CBasePlayer *pPlayer) {
	pPlayer->InitialSpawn();
	pPlayer->SetModel("models/player.mdl");
	pPlayer->Spawn();
}

void ClientActive(edict_t *pEdict, bool bLoadGame) {
	CBasePlayer *pPlayer = ToBasePlayer(CBaseEntity::Instance(pEdict));
	FinishClientPutInServer(pPlayer);
}

// called by ClientKill and DeadThink
void respawn(CBaseEntity *pEdict, bool fCopyCorpse) {
	engine->ServerCommand("reload\n");
}
