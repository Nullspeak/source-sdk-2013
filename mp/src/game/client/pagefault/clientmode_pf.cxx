/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "clientmode_shared.h"
#include "ivmodemanager.h"
#include "c_weapon__stubs.h"

/* TODO: figure out why the engine resets this to 75 and then ignores it */
ConVar default_fov("default_fov", "90", FCVAR_CHEAT);

STUB_WEAPON_CLASS(cycler_weapon, WeaponCycler, C_BaseCombatWeapon);
STUB_WEAPON_CLASS(weapon_cubemap, WeaponCubemap, C_BaseCombatWeapon);

class CPFViewport : public CBaseViewport {
	DECLARE_CLASS_SIMPLE(CPFViewport, CBaseViewport);
public:
	/* for some reason, CBaseViewport spawns multiplayer things like the scoreboard and spectator menu by default */
	void CreateDefaultPanels(void) { }
};

class ClientModePF : public ClientModeShared {
	DECLARE_CLASS(ClientModePF, ClientModeShared);
public:
	void InitViewport() {
		m_pViewport = new CPFViewport;
		m_pViewport->Start(gameuifuncs, gameeventmanager);
		m_pViewport->SetPaintBackgroundEnabled(false);
		m_pViewport->SetName("Viewport");
		m_pViewport->SetBounds(0, 0, ScreenWidth(), ScreenHeight());
	}
};

IClientMode *g_pClientMode = new ClientModePF;
IClientMode *GetClientModeNormal() { return g_pClientMode; }

class PFModeManager : public IVModeManager {
	void	Init() {}
	void	SwitchMode(bool commander, bool force) {}
	void	LevelInit(const char *newmap) {}
	void	LevelShutdown() { g_pClientMode->LevelShutdown(); }
};

IVModeManager *modemanager = (IVModeManager *)new PFModeManager;
