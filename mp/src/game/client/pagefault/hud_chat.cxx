/*
 *	Pagefault
 *	(c) sarah 2020
 */
#include "cbase.h"
#include "hud_chat.hxx"
#include "hud_macros.h"
#include "text_message.h"
#include "vguicenterprint.h"
#include "vgui/ILocalize.h"
#include "c_team.h"
#include "c_playerresource.h"
#include "ihudlcd.h"

/*
 *	The point of this file is to prevent an assert the engine makes
 *	when it can't find a chat hud element
 */
DECLARE_HUDELEMENT(CHudChat);

DECLARE_HUD_MESSAGE(CHudChat, SayText);
DECLARE_HUD_MESSAGE(CHudChat, SayText2);
DECLARE_HUD_MESSAGE(CHudChat, TextMsg);

//=====================
//CHudChatLine
//=====================

void CHudChatLine::ApplySchemeSettings(vgui::IScheme *pScheme) {
	BaseClass::ApplySchemeSettings(pScheme);
}

//=====================
//CHudChatInputLine
//=====================

void CHudChatInputLine::ApplySchemeSettings(vgui::IScheme *pScheme) {
	BaseClass::ApplySchemeSettings(pScheme);
}

//=====================
//CHudChat
//=====================

CHudChat::CHudChat(const char *pElementName) : BaseClass(pElementName) {

}

void CHudChat::CreateChatInputLine(void) {
	m_pChatInput = new CHudChatInputLine(this, "ChatInputLine");
	m_pChatInput->SetVisible(false);
}

void CHudChat::CreateChatLines(void) {
	m_ChatLine = new CHudChatLine(this, "ChatLine1");
	m_ChatLine->SetVisible(false);
}

void CHudChat::ApplySchemeSettings(vgui::IScheme *pScheme) {
	BaseClass::ApplySchemeSettings(pScheme);
}


void CHudChat::Init(void) {
	BaseClass::Init();

	HOOK_HUD_MESSAGE(CHudChat, SayText);
	HOOK_HUD_MESSAGE(CHudChat, SayText2);
	HOOK_HUD_MESSAGE(CHudChat, TextMsg);
}

//-----------------------------------------------------------------------------
// Purpose: Overrides base reset to not cancel chat at round restart
//-----------------------------------------------------------------------------
void CHudChat::Reset(void) {
}

int CHudChat::GetChatInputOffset(void) {
	if(m_pChatInput->IsVisible()) {
		return m_iFontHeight;
	} else
		return 0;
}

Color CHudChat::GetClientColor(int clientIndex) {
	return g_ColorGrey;
}