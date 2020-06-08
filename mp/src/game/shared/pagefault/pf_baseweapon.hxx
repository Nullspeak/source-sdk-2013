/*
 *	Pagefault
 *	(c) sarah 2020
 */
#ifndef PF_BASEWEAPON_HXX
#define PF_BASEWEAPON_HXX
#include "basecombatweapon_shared.h"

class CPFBaseWeapon : public CBaseCombatWeapon {
	DECLARE_CLASS(CPFBaseWeapon, CBaseCombatWeapon);
public:
	virtual void AddViewmodelBob(CBaseViewModel *viewmodel, Vector &origin, QAngle &angles);
};

#endif /* PF_BASEWEAPON_HXX */
