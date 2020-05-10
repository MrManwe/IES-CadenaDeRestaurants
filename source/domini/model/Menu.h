#pragma once
#include <set>
#include "Producte.h"

namespace domini
{
	namespace model
	{
		class PlatNormal;
		class Postre;
		class Beguda;

		class Menu: public Producte
		{
		public:
			Menu(std::string i_nom, float i_preu, bool i_infantil);

			bool ObteInfantil();
			void SetInfantil(bool i_infantil);

			Postre* ObtePostre();
			void SetPostre(Postre* i_postre);

			Beguda* ObteBeguda();
			void SetBeguda(Beguda* i_beguda);

			std::set<PlatNormal*> ObtePlatsInclosos();
			void AfegeixPlatInclos(PlatNormal* i_platNormal);

			bool EsMenuVegetaria() override;
			float ObteEstalvi() override;
		
		private:
			bool m_infantil;
			std::set<PlatNormal*> m_platsInclosos;
			Postre* m_postre;
			Beguda* m_beguda;

		};
	}
}