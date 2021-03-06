
#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "player.h"
#include "gamerules.h"
#include "training_gamerules.h"
#include "hltv.h"
#include "game.h"
#include "trains.h"
#include "vehicle.h"
#include "globals.h"

#include "bot_include.h"

namespace sv {

void EscapeFromBombState::OnEnter(CCSBot *me)
{
	me->StandUp();
	me->Run();
	me->DestroyPath();
	me->EquipKnife();
}

// Escape from the bomb

void EscapeFromBombState::OnUpdate(CCSBot *me)
{
	const Vector *bombPos = me->GetGameState()->GetBombPosition();

	// if we don't know where the bomb is, we shouldn't be in this state
	if (bombPos == NULL)
	{
		me->Idle();
		return;
	}

	// grab our knife to move quickly
	me->EquipKnife();

	// look around
	me->UpdateLookAround();

	if (me->UpdatePathMovement() != CCSBot::PROGRESSING)
	{
		// we have no path, or reached the end of one - create a new path far away from the bomb
		FarAwayFromPositionFunctor func(bombPos);
		CNavArea *goalArea = FindMinimumCostArea(me->GetLastKnownArea(), func);

		// if this fails, we'll try again next time
		me->ComputePath(goalArea, NULL, FASTEST_ROUTE);
	}
}

void EscapeFromBombState::OnExit(CCSBot *me)
{
	me->EquipBestWeapon();
}

}
