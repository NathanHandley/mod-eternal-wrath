//  Author: Nathan Handley (<https://github.com/NathanHandley> | nathanhandley@protonmail.com)
//  Copyright (c) 2024 Nathan Handley
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

#include "ScriptMgr.h"
#include "Configuration/Config.h"
#include "World.h"
#include "Chat.h"
#include "Opcodes.h"

class EternalWrath_WorldScript : public WorldScript
{
public:
    EternalWrath_WorldScript() : WorldScript("eternalWrath") {}

    void OnAfterConfigLoad(bool /*reload*/) override
    {

    }
};

void AddEternalWrathScripts()
{
	new EternalWrath_WorldScript();
}
