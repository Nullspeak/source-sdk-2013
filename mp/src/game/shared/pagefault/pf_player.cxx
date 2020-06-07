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
}

void CPFPlayer::PreThink(void) {
	BaseClass::PreThink();

	if(m_afButtonPressed & IN_SPEED)
		SetMaxSpeed(PF_PLAYER_SPEED_DASH);

	if(m_afButtonReleased & IN_SPEED)
		SetMaxSpeed(PF_PLAYER_SPEED_WALK);
}
