#include "Postre.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
	Postre::Postre(std::string i_nom, float i_preu)
		: Plat(i_nom, i_preu)
		{
			dades::BaseDeDades::RegistraPostre(this);
		}
	int Postre::ObteNumMenus()
	{
		return m_menus.size();
	}
	void Postre::AfegeixMenu(Menu* i_menu)
	{
		m_menus.insert(i_menu);
	}
	std::set<Menu*> Postre::ObteMenus()
	{
		return m_menus;
	}
	}
}
