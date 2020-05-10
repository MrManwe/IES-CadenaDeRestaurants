#include "Beguda.h"
#include "dades/BaseDeDades.h"
namespace domini
{
	namespace model
	{
		Beguda::Beguda(std::string i_nom, float i_preu, bool i_alcoholica)
			: Producte(i_nom, i_preu)
		{
			m_alcoholica = i_alcoholica;
			dades::BaseDeDades::RegistraBeguda(this);
		}
		bool Beguda::ObteAlcoholica()
		{
			return m_alcoholica;
		}
		void Beguda::SetAlcoholica(bool i_alcoholica)
		{
			m_alcoholica = i_alcoholica;
		}
		bool Beguda::EsMenuVegetaria()
		{
			return false;
		}
		float Beguda::ObteEstalvi()
		{
			return 0.0f;
		}
		
	}
}