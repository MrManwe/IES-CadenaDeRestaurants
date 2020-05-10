#pragma once
#include "Plat.h"

namespace domini
{
	namespace model
	{
		class Menu;

		class Postre : public Plat
		{
		public:
			Postre(std::string i_nom, float i_preu);

			void AfegeixMenu(Menu* i_menu);
			std::set<Menu*> ObteMenus();
			int ObteNumMenus();

		private:
			std::set<Menu*> m_menus;
		};
	}
}