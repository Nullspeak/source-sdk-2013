/*
 *	Pagefault
 *	(c) sarah 2020
 */
#ifndef PF_PLAYER_HXX
#define PF_PLAYER_HXX
#include "cbase.h"

#ifdef CLIENT_DLL
#define CPFPlayer C_PFPlayer
#endif

class CPFPlayer : public CBasePlayer {
public:
	DECLARE_CLASS(CPFPlayer, CBasePlayer);

	virtual void Spawn();
};
#endif /* PF_PLAYER_HXX */
