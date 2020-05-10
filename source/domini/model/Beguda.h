#pragma once
#include<set>
#include "Producte.h"

namespace domini
{
	namespace model
	{
		class Menu;

		class Beguda: public Producte
		{
		public:
			Beguda(std::string i_nom, float i_preu, bool i_alcoholica);

			bool ObteAlcoholica();
			void SetAlcoholica(bool i_alcoholica);

			bool EsMenuVegetaria() override;
			float ObteEstalvi() override;

		private:
			bool m_alcoholica;
		};
	}
}