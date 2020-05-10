#include "PlatNormal.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
		PlatNormal::PlatNormal(std::string i_nom, float i_preu)
			: Plat(i_nom, i_preu)
		{
			dades::BaseDeDades::RegistraPlatNormal(this);
		}
	}
}
