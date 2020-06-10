/*
 *	Pagefault
 *	(c) sarah 2020
 */
#ifndef PF_PROP_ITEM_HXX
#define PF_PROP_ITEM_HXX
#include "cbase.h"

class CPFPropItem : public CBaseAnimating {
public:
	DECLARE_CLASS(CPFPropItem, CBaseAnimating);

	virtual void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
};
#endif /* PF_PROP_ITEM_HXX */
