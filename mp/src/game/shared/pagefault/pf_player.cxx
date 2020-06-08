/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "in_buttons.h"
#include "pf_player.hxx"

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
		SetMaxSpeed(PF_PLAYER_SPEED_DASH);

	if(m_afButtonReleased & IN_SPEED)
		SetMaxSpeed(PF_PLAYER_SPEED_WALK);
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
