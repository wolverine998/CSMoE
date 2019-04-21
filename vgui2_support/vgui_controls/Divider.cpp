//========= Copyright ?1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#include <vgui/IScheme.h>

#include "Divider.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

using namespace vgui2;

DECLARE_BUILD_FACTORY( Divider );

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
Divider::Divider(Panel *parent, const char *name) : Panel(parent, name)
{
	SetSize(128, 2);
}

//-----------------------------------------------------------------------------
// Purpose: Destructor
//-----------------------------------------------------------------------------
Divider::~Divider()
{
}

//-----------------------------------------------------------------------------
// Purpose: sets up the border as the line to draw as a divider
//-----------------------------------------------------------------------------
void Divider::ApplySchemeSettings(IScheme *pScheme)
{
	SetBorder(pScheme->GetBorder("ButtonDepressedBorder"));
	BaseClass::ApplySchemeSettings(pScheme);
}