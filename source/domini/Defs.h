#pragma once
#include <string>

namespace domini
{
	struct DadesMenu
	{
		std::string nom;
		float preu;
		float estalvi;
		
		//Aquesta funció la exigeix el C++ per a poder tenir un set de estructures (tots els objectes dels que volem fer sets han de tenir una operació com aqeusta)
		inline bool operator< (const domini::DadesMenu& i_right) const
		{
			return nom < i_right.nom;
		}
	};

}