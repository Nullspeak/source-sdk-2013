/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "pf_player.hxx"

LINK_ENTITY_TO_CLASS(player, CPFPlayer);

void CPFPlayer::Spawn() {
	// Dying without a player model crashes the client
	SetModel("models/player.mdl");

	BaseClass::Spawn();
}
