/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "pf_player.hxx"
#include "pf_baseweapon.hxx"

static float g_verticalBob = 0.0f;
static float g_lateralBob = 0.0f;

void CPFBaseWeapon::AddViewmodelBob(CBaseViewModel *viewmodel, Vector &origin, QAngle &angles) {
	Vector forward, right, up;
	AngleVectors(angles, &forward, &right, &up);

	CBasePlayer *pPlayer = ToBasePlayer(GetOwner());
	if(!pPlayer)
		return;

	float speedbob = RemapValClamped(pPlayer->GetAbsVelocity().Length2D(), PF_PLAYER_SPEED_WALK, PF_PLAYER_SPEED_DASH, 0.0f, 1.0f);
	float speedmul = RemapValClamped(pPlayer->GetAbsVelocity().Length2D(), 0, PF_PLAYER_SPEED_DASH, 0.0f, 1.5f);

	/* don't do the expensive calculations if we're standing still */
	if(speedmul < FLT_EPSILON)
		return;

	/* this is probably really really expensive */
	float slowsin = sin(gpGlobals->curtime * 7.0f);
	float slowcos = cos(gpGlobals->curtime * 7.0f);
	float fastsin = sin(gpGlobals->curtime * 9.0f);
	float fastcos = cos(gpGlobals->curtime * 9.0f);

	g_verticalBob = Lerp(speedbob, slowsin, fastsin);
	g_lateralBob = Lerp(speedbob, slowcos, fastcos);

	angles[ROLL] += g_verticalBob * -0.5f * speedmul;
	angles[YAW] += g_verticalBob * 0.5f * speedmul;
	angles[PITCH] += abs(g_lateralBob * 0.5f) * speedmul;

	VectorMA(origin, abs(g_verticalBob * 0.2f) * speedmul, up, origin);
	VectorMA(origin, g_lateralBob * 0.3f * speedmul, right, origin);
}
