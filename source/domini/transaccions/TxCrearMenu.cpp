#include "TxCrearMenu.h"
#include "dades/BaseDeDades.h"
#include "domini/model/Restaurant.h"
#include "domini/Excepcions.h"

namespace domini
{
	TxCrearMenu::TxCrearMenu(std::string i_adreca, std::string i_nomMenu, float i_preu, std::string i_nomPlat, std::string i_nomPostre, std::string i_nomBeguda, bool i_infantil)
	{
		m_adreca = i_adreca;
		m_nomMenu = i_nomMenu;
		m_preu = i_preu;
		m_nomPlat = i_nomPlat;
		m_nomPostre = i_nomPostre;
		m_nomBeguda = i_nomBeguda;
		m_infantil = i_infantil;
	}

	void TxCrearMenu::Executar()
	{
		domini::model::Restaurant* restaurant = dades::BaseDeDades::ObteRestaurant(m_adreca);
		domini::model::PlatNormal* platNormal = dades::BaseDeDades::ObtePlatNormal(m_nomPlat);
		domini::model::Postre* postre = dades::BaseDeDades::ObtePostre(m_nomPostre);
		domini::model::Beguda* beguda = dades::BaseDeDades::ObteBeguda(m_nomBeguda);
		bool existeix = dades::BaseDeDades::ExisteixProducte(m_nomMenu);
		if (existeix)
		{
			throw JaExisteixProducte();
		}

		
		restaurant->CrearMenu(m_nomMenu, platNormal, postre, beguda, m_infantil, m_preu);
		
	}
}