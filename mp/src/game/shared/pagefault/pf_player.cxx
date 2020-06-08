/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "in_buttons.h"
#include "pf_player.hxx"

static ConVar sv_dash_accelerate("sv_dash_accelerate", "1", FCVAR_CHEAT, "How fast the player will transition between walking and sprinting");

LINK_ENTITY_TO_CLASS(player, CPFPlayer);

void CPFPlayer::Spawn(void) {
	BaseClass::Spawn();
	SetMaxSpeed(PF_PLAYER_SPEED_WALK);
#ifdef GAME_DLL
	GiveNamedItem("weapon_test");
#endif
}

void CPFPlayer::PreThink(void) {
	BaseClass::PreThink();

	if(m_afButtonPressed & IN_SPEED)
		m_bSprinting = true;

	if(m_afButtonReleased & IN_SPEED)
		m_bSprinting = false;

	float curspeed = GetPlayerMaxSpeed();
	float newspeed = 0.0f;
	if(m_bSprinting)
		newspeed = Lerp(gpGlobals->frametime * sv_dash_accelerate.GetFloat(), curspeed, PF_PLAYER_SPEED_DASH);
	else
		newspeed = Lerp(gpGlobals->frametime * sv_dash_accelerate.GetFloat() * 2.0f, curspeed, PF_PLAYER_SPEED_WALK);

	SetMaxSpeed(newspeed);
}

#ifdef GAME_DLL
#include "pf_viewmodel.hxx"

void CPFPlayer::CreateViewModel(int index) {
	Assert(index >= 0 && index < MAX_VIEWMODELS);

	if(GetViewModel(index))
		return;

	CPFViewModel *vm = (CPFViewModel *)CreateEntityByName("pf_viewmodel");
	if(vm) {
		vm->SetAbsOrigin(GetAbsOrigin());
		vm->SetOwner(this);
		vm->SetIndex(index);
		DispatchSpawn(vm);
		vm->FollowEntity(this);
		m_hViewModel.Set(index, vm);
	}
}
#endif
