/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "pf_baseweapon.hxx"

#ifdef CLIENT_DLL
#define CPFTestWeapon C_PFTestWeapon
#endif

class CPFTestWeapon : public CPFBaseWeapon {
	DECLARE_CLASS(CPFTestWeapon, CPFBaseWeapon);
public:
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CPFTestWeapon(void);
	void	PrimaryAttack(void);

#ifndef CLIENT_DLL
	DECLARE_ACTTABLE();
#endif

private:
	CPFTestWeapon(const CPFTestWeapon &);
};

IMPLEMENT_NETWORKCLASS_ALIASED(PFTestWeapon, DT_PFTestWeapon)

BEGIN_NETWORK_TABLE(CPFTestWeapon, DT_PFTestWeapon)
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA(CPFTestWeapon)
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS(weapon_test, CPFTestWeapon);
PRECACHE_WEAPON_REGISTER(weapon_test);

#ifndef CLIENT_DLL
acttable_t CPFTestWeapon::m_acttable[] =
{
	{ ACT_HL2MP_IDLE,					ACT_HL2MP_IDLE_PISTOL,					false },
	{ ACT_HL2MP_RUN,					ACT_HL2MP_RUN_PISTOL,					false },
	{ ACT_HL2MP_IDLE_CROUCH,			ACT_HL2MP_IDLE_CROUCH_PISTOL,			false },
	{ ACT_HL2MP_WALK_CROUCH,			ACT_HL2MP_WALK_CROUCH_PISTOL,			false },
	{ ACT_HL2MP_GESTURE_RANGE_ATTACK,	ACT_HL2MP_GESTURE_RANGE_ATTACK_PISTOL,	false },
	{ ACT_HL2MP_GESTURE_RELOAD,			ACT_HL2MP_GESTURE_RELOAD_PISTOL,		false },
	{ ACT_HL2MP_JUMP,					ACT_HL2MP_JUMP_PISTOL,					false },
	{ ACT_RANGE_ATTACK1,				ACT_RANGE_ATTACK_PISTOL,				false },
};

IMPLEMENT_ACTTABLE(CPFTestWeapon);
#endif

CPFTestWeapon::CPFTestWeapon(void) {
	m_bReloadsSingly = false;
	m_bFiresUnderwater = true;
}

void CPFTestWeapon::PrimaryAttack(void) {
	// Only the player fires this way so we can cast
	CBasePlayer *pPlayer = ToBasePlayer(GetOwner());

	if(!pPlayer)
		return;

	if(m_iClip1 <= 0) {
		if(!m_bFireOnEmpty) {
			Reload();
		} else {
			WeaponSound(EMPTY);
			m_flNextPrimaryAttack = 0.15;
		}

		return;
	}

	WeaponSound(SINGLE);
	pPlayer->DoMuzzleFlash();

	SendWeaponAnim(ACT_VM_PRIMARYATTACK);
	pPlayer->SetAnimation(PLAYER_ATTACK1);

	m_flNextPrimaryAttack = gpGlobals->curtime + 0.25;

	m_iClip1--;

	Vector vecSrc = pPlayer->Weapon_ShootPosition();
	Vector vecAiming = pPlayer->GetAutoaimVector(AUTOAIM_5DEGREES);

	FireBulletsInfo_t info(1, vecSrc, vecAiming, vec3_origin, MAX_TRACE_LENGTH, m_iPrimaryAmmoType);
	info.m_pAttacker = pPlayer;

	// Fire the bullets, and force the first shot to be perfectly accuracy
	pPlayer->FireBullets(info);
}
