#pragma once
#include <string>
#include "Transaccio.h"
namespace domini
{
	class TxCrearMenu: public Transaccio
	{
	public:
		TxCrearMenu(
			std::string i_adreca,
			std::string i_nomMenu,
			float i_preu,
			std::string i_nomPlat,
			std::string i_nomPostre,
			std::string i_nomBeguda,
			bool i_infantil);


		void Executar() override;
	private:
		std::string m_adreca;
		std::string m_nomMenu;
		float m_preu;
		std::string m_nomPlat;
		std::string m_nomPostre;
		std::string m_nomBeguda;
		bool m_infantil;
	};
}