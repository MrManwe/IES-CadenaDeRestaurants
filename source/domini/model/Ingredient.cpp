#include "Ingredient.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
		Ingredient::Ingredient(std::string i_nom, bool i_animal)
		{
			m_nom = i_nom;
			m_animal = i_animal;
			dades::BaseDeDades::RegistraIngredient(this);
		}
		std::string Ingredient::ObteNom()
		{
			return m_nom;
		}
		void Ingredient::SetNom(std::string i_nom)
		{
			m_nom = i_nom;
		}
		bool Ingredient::ObteAnimal()
		{
			return m_animal;
		}
		void Ingredient::SetAnimal(bool i_animal)
		{
			m_animal = i_animal;
		}
	}
}