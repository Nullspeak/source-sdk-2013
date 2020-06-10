/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "pf_player.hxx"
#include "pf_prop_item.hxx"

void CPFPropItem::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value) {
	BaseClass::Use(pActivator, pCaller, useType, value);

	//CPFPlayer *pPlayer = (CPFPlayer *)ToBasePlayer(pActivator);
	//pPlayer->SetInventoryItem(this);
}
