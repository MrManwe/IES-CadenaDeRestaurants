#include "Producte.h"
#include "dades/BaseDeDades.h"

namespace domini
{
	namespace model
	{
		Producte::Producte(std::string i_nom, float i_preu)
		{
			m_nom = i_nom;
			m_preu = i_preu;
			dades::BaseDeDades::RegistraProducte(this);
		}
		std::string Producte::ObteNom()
		{
			return m_nom;
		}

		void Producte::SetNom(std::string i_nom)
		{
			m_nom = i_nom;
		}
		float Producte::ObtePreu()
		{
			return m_preu;
		}
		void Producte::SetPreu(float i_preu)
		{
			m_preu = i_preu;
		}
	}
}