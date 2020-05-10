#pragma once
#include <string>
#include <set>
#include "Transaccio.h"
#include "domini/Defs.h"

namespace domini
{
	class TxLlistaMenusVegetarians : public Transaccio
	{
	public:

	
		TxLlistaMenusVegetarians(const std::string& i_adreca);
		void Executar() override;
		std::set<DadesMenu> ObteResultat();

	private:
		std::string m_adreca;
		std::set<DadesMenu> m_result;
	};
}