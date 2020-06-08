/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "pf_viewmodel.hxx"
#include "tier0/memdbgon.h"

LINK_ENTITY_TO_CLASS(pf_viewmodel, CPFViewModel);

IMPLEMENT_NETWORKCLASS_ALIASED(PFViewModel, DT_PFViewModel)

BEGIN_NETWORK_TABLE(CPFViewModel, DT_PFViewModel)
END_NETWORK_TABLE()

CPFViewModel::CPFViewModel() {}

void CPFViewModel::CalcViewModelLag(Vector &origin, QAngle &angles, QAngle &original_angles) {
#ifdef CLIENT_DLL
	Vector modpos = origin;

	BaseClass::CalcViewModelLag(modpos, angles, original_angles);

	/* flips the lag into lead-in
	 * we do it slightly inefficiently because doing it the lazy way
	 * and flipping values in CalcViewModelLag screws up some of the offsets
	 */
	Vector delta = modpos - origin;
	origin += (delta * -0.5f);
#endif
}
