#pragma once
#include <string>

namespace domini
{
	namespace model
	{
		class Producte
		{
		protected:
			Producte(std::string i_nom, float i_preu);

		public:
			std::string ObteNom();
			void SetNom(std::string i_nom);

			float ObtePreu();
			void SetPreu(float i_preu);

			virtual bool EsMenuVegetaria() = 0;
			virtual float ObteEstalvi() = 0;

		private:
			std::string m_nom;
			float m_preu;
		};
	}
}