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

#define PF_PLAYER_SPEED_WALK 100.0f
#define PF_PLAYER_SPEED_DASH 200.0f

class CPFPlayer : public CBasePlayer {
public:
	DECLARE_CLASS(CPFPlayer, CBasePlayer);

	virtual void Spawn(void);
	virtual void PreThink(void);

#ifdef GAME_DLL
	virtual void CreateViewModel(int viewmodelindex = 0);
#endif
private:
	bool m_bSprinting{false};
};
#endif /* PF_PLAYER_HXX */
