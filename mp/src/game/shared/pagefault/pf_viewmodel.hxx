/*
 *	Pagefault
 *	(c) sarah 2020
 */
#ifndef PF_VIEWMODEL_HXX
#define PF_VIEWMODEL_HXX
#include "baseviewmodel_shared.h"

#if defined( CLIENT_DLL )
#define CPFViewModel C_PFViewModel
#endif

class CPFViewModel : public CBaseViewModel {
	DECLARE_CLASS(CPFViewModel, CBaseViewModel);
public:
	DECLARE_NETWORKCLASS();
	CPFViewModel();
	virtual void CalcViewModelLag(Vector &origin, QAngle &angles, QAngle &original_angles);
	virtual bool ShouldReceiveProjectedTextures(int flags) { return true; }
};

#endif // PREDICTED_VIEWMODEL_H
