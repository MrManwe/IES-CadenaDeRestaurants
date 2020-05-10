#include "Menu.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
		Menu::Menu(std::string i_nom, float i_preu, bool i_infantil)
			: Producte(i_nom, i_preu)
		{
			m_infantil = i_infantil;
			dades::BaseDeDades::RegistraMenu(this);
		}
		bool Menu::ObteInfantil()
		{
			return m_infantil;
		}
		void Menu::SetInfantil(bool i_infantil)
		{
			m_infantil = i_infantil;
		}
		Postre* Menu::ObtePostre()
		{
			return m_postre;
		}
		void Menu::SetPostre(Postre* i_postre)
		{
			m_postre = i_postre;
		}
		Beguda* Menu::ObteBeguda()
		{
			return m_beguda;
		}
		void Menu::SetBeguda(Beguda* i_beguda)
		{
			m_beguda = i_beguda;
		}
		std::set<PlatNormal*> Menu::ObtePlatsInclosos()
		{
			return m_platsInclosos;
		}
		void Menu::AfegeixPlatInclos(PlatNormal* i_platNormal)
		{
			m_platsInclosos.insert(i_platNormal);
		}
		bool Menu::EsMenuVegetaria()
		{
			bool esVegetaria = true;
			for(PlatNormal* plat : m_platsInclosos)
			{
				bool platVegetaria = plat->EsVegetaria();
				esVegetaria = esVegetaria && platVegetaria;
			}
			if (m_postre != nullptr)
			{
				bool postreVegetaria = m_postre->EsVegetaria();
				esVegetaria = esVegetaria && postreVegetaria;
			}

			return esVegetaria;
		}
		
		float Menu::ObteEstalvi()
		{
			float preuTotal = 0.0f;
			for (PlatNormal* plat : m_platsInclosos)
			{
				float preuPlat = plat->ObtePreu();
				preuTotal += preuPlat;
			}
			if (m_postre != nullptr)
			{
				float preuPostre = m_postre->ObtePreu();
				preuTotal += preuPostre;
			}

			float preu = ObtePreu();

			float estalvi = preuTotal - preu;

			return estalvi;
		}
	}
}