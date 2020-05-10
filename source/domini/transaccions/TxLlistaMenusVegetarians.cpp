#include "TxLlistaMenusVegetarians.h"
#include "domini/Excepcions.h"
#include "dades/BaseDeDades.h"

namespace domini
{

	TxLlistaMenusVegetarians::TxLlistaMenusVegetarians(const std::string& i_adreca)
	{
		m_adreca = i_adreca;
	}

	void TxLlistaMenusVegetarians::Executar()
	{
		model::Restaurant* restaurant = dades::BaseDeDades::ObteRestaurant(m_adreca);
		m_result = restaurant->LlistaMenusVegetarians();
		
	}
	std::set<DadesMenu> TxLlistaMenusVegetarians::ObteResultat()
	{
		return m_result;
	}
}

