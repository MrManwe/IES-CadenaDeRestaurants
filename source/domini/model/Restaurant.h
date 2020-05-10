#pragma once
#include <string>
#include <set>
#include "domini/Defs.h"

namespace domini
{
	namespace model
	{
		class Producte;
		class Ingredient;
		class PlatNormal;
		class Postre;
		class Beguda;

		class Restaurant
		{
		public:
			Restaurant(std::string i_adreca);

			std::string ObteAdreca() const;
			void SetAdreca(std::string i_adreca);

			std::set<Producte*> ObteProductes();
			void AfegeixProducte(Producte* i_producte);

			std::set<Ingredient*> ObteIngredients();
			void AfegeixIngredient(Ingredient* i_ingredient);

			std::set<DadesMenu> LlistaMenusVegetarians();

			void CrearMenu(std::string i_nomMenu, PlatNormal* i_platNormal, Postre* i_postre, Beguda* i_beguda, bool i_infantil, float i_preu);


		private:
			std::string m_adreca;
			std::set<Producte*> m_productes;
			std::set<Ingredient*> m_ingredients;
		};
	}
}