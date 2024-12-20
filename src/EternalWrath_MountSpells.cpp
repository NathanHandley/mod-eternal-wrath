// Author: Nathan Handley (<https://github.com/NathanHandley> | nathanhandley@protonmail.com)
// Copyright (c) 2024 Nathan Handley
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

#include "EternalWrath_MountSpells.h"

// This code was taken from SpellScript.h and spell_generic.cpp from the AzerothCore
// project (azerothcore.org)
SpellGenMount::SpellGenMount(uint32 mount0, uint32 mount60, uint32 mount100, uint32 mount150, uint32 mount280, uint32 mount310) : SpellScript(),
        _mount0(mount0), _mount60(mount60), _mount100(mount100), _mount150(mount150), _mount280(mount280), _mount310(mount310)
{

}


bool SpellGenMount::Validate(SpellInfo const* /*spellInfo*/)
{
    if (_mount0 && !sSpellMgr->GetSpellInfo(_mount0))
        return false;
    if (_mount60 && !sSpellMgr->GetSpellInfo(_mount60))
        return false;
    if (_mount100 && !sSpellMgr->GetSpellInfo(_mount100))
        return false;
    if (_mount150 && !sSpellMgr->GetSpellInfo(_mount150))
        return false;
    if (_mount280 && !sSpellMgr->GetSpellInfo(_mount280))
        return false;
    if (_mount310 && !sSpellMgr->GetSpellInfo(_mount310))
        return false;
    return true;
}

void SpellGenMount::HandleMount(SpellEffIndex effIndex)
{
    PreventHitDefaultEffect(effIndex);

    if (Player* target = GetHitPlayer())
    {
        uint32 petNumber = target->GetTemporaryUnsummonedPetNumber();
        target->SetTemporaryUnsummonedPetNumber(0);

        // Prevent stacking of mounts and client crashes upon dismounting
        target->RemoveAurasByType(SPELL_AURA_MOUNTED, ObjectGuid::Empty, GetHitAura());

        // Triggered spell id dependent on riding skill and zone
        bool canFly = false;
        uint32 map = GetVirtualMapForMapAndZone(target->GetMapId(), target->GetZoneId());
        if (map == 530 || (map == 571 && target->HasSpell(SPELL_COLD_WEATHER_FLYING)))
            canFly = true;

        AreaTableEntry const* area = sAreaTableStore.LookupEntry(target->GetAreaId());
        // Xinef: add battlefield check
        Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(target->GetZoneId());
        if ((area && canFly && (area->flags & AREA_FLAG_NO_FLY_ZONE)) || (Bf && !Bf->CanFlyIn()))
            canFly = false;

        uint32 mount = 0;
        switch (target->GetBaseSkillValue(SKILL_RIDING))
        {
        case 0:
            mount = _mount0;
            break;
        case 75:
            mount = _mount60;
            break;
        case 150:
            mount = _mount100;
            break;
        case 225:
            if (canFly)
                mount = _mount150;
            else
                mount = _mount100;
            break;
        case 300:
            if (canFly)
            {
                if (_mount310 && target->Has310Flyer(false))
                    mount = _mount310;
                else
                    mount = _mount280;
            }
            else
                mount = _mount100;
            break;
        default:
            break;
        }

        if (mount)
        {
            PreventHitAura();
            target->CastSpell(target, mount, true);
        }

        if (petNumber)
            target->SetTemporaryUnsummonedPetNumber(petNumber);
    }
}

void SpellGenMount::Register()
{
    OnEffectHitTarget += SpellEffectFn(SpellGenMount::HandleMount, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
}
