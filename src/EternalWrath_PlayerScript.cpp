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

#include "Object.h"
#include "Player.h"
#include "ScriptMgr.h"

class EternalWrath_PlayerScript : public PlayerScript
{
public:
    EternalWrath_PlayerScript() : PlayerScript("EternalWrath_PlayerScript") {}

    void OnLogin(Player* player)
    {
        // Restrict rest_bonus to level 80 experience amount
        float expBase = 1670800.0f;
        float rest_bonus_max = expBase * 1.5f / 2;
        if (player->GetRestBonus() > rest_bonus_max)
            player->SetRestBonus(rest_bonus_max);
    }    
};

void AddEternalWrathPlayerScript()
{
    new EternalWrath_PlayerScript();
}
