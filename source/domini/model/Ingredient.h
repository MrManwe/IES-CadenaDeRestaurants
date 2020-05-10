#pragma once
#include <string>

namespace domini
{
	namespace model
	{
		class Ingredient
		{
		public:
			Ingredient(std::string i_nom, bool i_animal);

			std::string ObteNom();
			void SetNom(std::string i_nom);

			bool ObteAnimal();
			void SetAnimal(bool i_animal);

		private:
			std::string m_nom;
			bool m_animal;
		};
	}
}