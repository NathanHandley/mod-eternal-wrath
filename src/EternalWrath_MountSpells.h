// Author: Nathan Handley (<https://github.com/NathanHandley> | nathanhandley@protonmail.com)
// Copyright (c) 2024 Nathan Handley
// Much of this code was taken from SpellScript.h and spell_generic.cpp from the AzerothCore
// project (azerothcore.org)
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU Affero General Public License as published by the
// Free Software Foundation; either version 3 of the License, or (at your
// option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along
// with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef EW_MOUNT_SPELLS_CLASS_H
#define EW_MOUNT_SPELLS_CLASS_H

#include "Player.h"
#include "ScriptMgr.h"
#include "BattlefieldMgr.h"
#include "SpellScript.h"
#include "SpellMgr.h"

enum EWMounts
{
    SPELL_COLD_WEATHER_FLYING = 54197,

    // Celestial Cat 82009
    SPELL_CELESTIAL_CAT_60 = 82010,
    SPELL_CELESTIAL_CAT_100 = 82011,
    SPELL_CELESTIAL_CAT_150 = 82012,
    SPELL_CELESTIAL_CAT_280 = 82013,
    SPELL_CELESTIAL_CAT_310 = 82014
};

class SpellGenMount : public SpellScript
{
    PrepareSpellScript(SpellGenMount);

public:
    SpellGenMount(uint32 mount0, uint32 mount60, uint32 mount100, uint32 mount150, uint32 mount280, uint32 mount310);
    bool Validate(SpellInfo const* /*spellInfo*/) override;
    void HandleMount(SpellEffIndex effIndex);
    void Register() override;

private:
    uint32 _mount0;
    uint32 _mount60;
    uint32 _mount100;
    uint32 _mount150;
    uint32 _mount280;
    uint32 _mount310;
};

#endif //MASTER_CLASS_H