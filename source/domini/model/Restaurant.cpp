#include "Restaurant.h"
#include "dades/BaseDeDades.h"
#include "domini/Excepcions.h"
namespace domini
{
	namespace model
	{
		Restaurant::Restaurant(std::string i_adreca)
		{
			m_adreca = i_adreca;
			dades::BaseDeDades::RegistraRestaurant(this);
		}

		std::string Restaurant::ObteAdreca() const
		{
			return m_adreca;
		}

		void Restaurant::SetAdreca(std::string i_adreca)
		{
			m_adreca = i_adreca;
		}
		std::set<Producte*> Restaurant::ObteProductes()
		{
			return m_productes;
		}
		void Restaurant::AfegeixProducte(Producte* i_producte)
		{
			m_productes.insert(i_producte);
		}
		std::set<Ingredient*> Restaurant::ObteIngredients()
		{
			return m_ingredients;
		}
		void Restaurant::AfegeixIngredient(Ingredient* i_ingredient)
		{
			m_ingredients.insert(i_ingredient);
		}

		std::set<DadesMenu> Restaurant::LlistaMenusVegetarians()
		{
			std::set<DadesMenu> result;
			for (Producte* p : m_productes)
			{
				bool socMenuVegetaria = p->EsMenuVegetaria();
				if (socMenuVegetaria)
				{
					std::string nom = p->ObteNom();
					float preu = p->ObtePreu();
					float estalvi = p->ObteEstalvi();
					DadesMenu dadesRestaurant;
					dadesRestaurant.nom = nom;
					dadesRestaurant.preu = preu;
					dadesRestaurant.estalvi = estalvi;
					result.insert(dadesRestaurant);
				}
			}
			return result;
		}
		void Restaurant::CrearMenu(std::string i_nomMenu, PlatNormal* i_platNormal, Postre* i_postre, Beguda* i_beguda, bool i_infantil, float i_preu)
		{
			if (m_productes.size() >= 40)
			{
				throw MassaProductes();
			}

			if (i_postre->ObteNumMenus() >= 10)
			{
				throw PostreEnMassaMenus();
			}

			bool alcoholica = i_beguda->ObteAlcoholica();
			if (i_infantil && alcoholica)
			{
				throw MenuInfantilIncorrecte();
			}

			if (m_productes.find(i_beguda) == m_productes.end())
			{
				throw RestaurantNoOfereixBeguda();
			}

			float preuBeguda = i_beguda->ObtePreu();
			float preuPlatNormal = i_platNormal->ObtePreu();
			float preuPostre = i_postre->ObtePreu();

			if (preuBeguda + preuPlatNormal + preuPostre < i_preu)
			{
				throw PreuIncorrecte();
			}

			Menu* menu = new Menu(i_nomMenu, i_preu, i_infantil);
			menu->AfegeixPlatInclos(i_platNormal);
			menu->SetPostre(i_postre);
			menu->SetBeguda(i_beguda);

			m_productes.insert(menu);

			std::set<Ingredient*> ingredientsPlat = i_platNormal->ObteIngredients();
			m_ingredients.insert(ingredientsPlat.begin(), ingredientsPlat.end());

			i_postre->AfegeixMenu(menu);
		}
	}
}