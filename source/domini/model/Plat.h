#pragma once
#include <set>
#include "Producte.h"

namespace domini
{
	namespace model
	{
		class Ingredient;
		
		class Plat: public Producte
		{
		protected:
			Plat(std::string i_nom, float i_preu);

		public:
			std::set<Ingredient*> ObteIngredients();
			void AfegirIngredient(Ingredient* i_ingredient);

			bool EsMenuVegetaria() override;
			float ObteEstalvi() override;

			bool EsVegetaria();

		private:
			std::set<Ingredient*> m_ingredients;
		};
	}
}