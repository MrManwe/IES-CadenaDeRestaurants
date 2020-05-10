#include "Plat.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
		Plat::Plat(std::string i_nom, float i_preu)
			: Producte(i_nom, i_preu)
		{
			dades::BaseDeDades::RegistraPlat(this);
		}
		std::set<Ingredient*> Plat::ObteIngredients()
		{
			return m_ingredients;
		}
		void Plat::AfegirIngredient(Ingredient* i_ingredient)
		{
			m_ingredients.insert(i_ingredient);
		}

		bool Plat::EsMenuVegetaria()
		{
			return false;
		}
		float Plat::ObteEstalvi()
		{
			return 0.0f;
		}

		bool Plat::EsVegetaria()
		{
			bool esVegetaria = true;
			for(Ingredient* ingredient: m_ingredients)
			{
				bool animal = ingredient->ObteAnimal();
				esVegetaria = esVegetaria && !animal;
			}
			return esVegetaria;
		}
	}
}