/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "gamemovement.h"

class CPFGameMovement : public CGameMovement {
	DECLARE_CLASS(CPFGameMovement, CGameMovement);
public:
	virtual void OnJump(float fImpulse) {
		player->EmitSound("Player.JumpFoley");
		player->ViewPunch(QAngle(1, 0, 0));
	}

	virtual void OnLand(float fVelocity) {
		player->EmitSound("Player.LandFoley");
		player->ViewPunch(QAngle(1, 0, 0));
	}
};

static CPFGameMovement g_GameMovement;
IGameMovement *g_pGameMovement = (IGameMovement *)&g_GameMovement;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CPFGameMovement, IGameMovement, INTERFACENAME_GAMEMOVEMENT, g_GameMovement);
