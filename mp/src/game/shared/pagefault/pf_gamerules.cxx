/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "singleplay_gamerules.h"
#include "ammodef.h"

#ifdef GAME_DLL
#include "voice_gamemgr.h"
#endif

#ifdef CLIENT_DLL
#define CPFRules C_PFRules

static ConVar fov_desired("fov_desired", "90", FCVAR_ARCHIVE | FCVAR_USERINFO, "Sets the player's desired FOV.");
#endif

class CPFRules : public CSingleplayRules {
	DECLARE_CLASS(CPFRules, CSingleplayRules);
public:
	virtual void PlayerThink(CBasePlayer *pPlayer) {}
};

REGISTER_GAMERULES_CLASS(CPFRules);

void InitBodyQue() {}

CAmmoDef *GetAmmoDef() {
	static CAmmoDef ammo;

	static bool bInitialising = true;
	if(bInitialising) {
		ammo.AddAmmoType("pistol", DMG_BULLET, TRACER_RAIL, 200, 200, 180, 30, 0);
		bInitialising = false;
	}

	return &ammo;
}

#ifdef GAME_DLL

// This being required here is a bug. It should be in shared\BaseGrenade_shared.cpp
ConVar sk_plr_dmg_grenade("sk_plr_dmg_grenade", "0");

class CVoiceGameMgrHelper : public IVoiceGameMgrHelper {
public:
	virtual bool	CanPlayerHearPlayer(CBasePlayer *pListener, CBasePlayer *pTalker, bool &bProximity) { return true; }
};

CVoiceGameMgrHelper g_VoiceGameMgrHelper;
IVoiceGameMgrHelper *g_pVoiceGameMgrHelper = &g_VoiceGameMgrHelper;

#endif // #ifdef GAME_DLL
