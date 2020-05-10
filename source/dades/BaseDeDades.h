#pragma once
#include <string>
#include <memory>
#include <unordered_set>
#include "domini/model/Ingredient.h"
#include "domini/model/Restaurant.h"
#include "domini/model/Producte.h"
#include "domini/model/Plat.h"
#include "domini/model/PlatNormal.h"
#include "domini/model/Postre.h"
#include "domini/model/Beguda.h"
#include "domini/model/Restaurant.h"
#include "domini/model/Menu.h"


namespace dades
{

	class BaseDeDades
	{
	public:

		static std::set<domini::model::Ingredient*> LlistaIngredients();
		static bool ExisteixIngredient(std::string i_nom);
		static domini::model::Ingredient* ObteIngredient(std::string i_nom);

		static std::set<domini::model::Producte*> LlistaProductes();
		static bool ExisteixProducte(std::string i_nom);
		static domini::model::Producte* ObteProducte(std::string i_nom);

		static std::set<domini::model::Plat*> LlistaPlats();
		static bool ExisteixPlat(std::string i_nom);
		static domini::model::Plat* ObtePlat(std::string i_nom);

		static std::set<domini::model::PlatNormal*> LlistaPlatsNormal();
		static bool ExisteixPlatNormal(std::string i_nom);
		static domini::model::PlatNormal* ObtePlatNormal(std::string i_nom);

		static std::set<domini::model::Postre*> LlistaPostres();
		static bool ExisteixPostre(std::string i_nom);
		static domini::model::Postre* ObtePostre(std::string i_nom);

		static std::set<domini::model::Beguda*> LlistaBegudes();
		static bool ExisteixBeguda(std::string i_nom);
		static domini::model::Beguda* ObteBeguda(std::string i_nom);

		static std::set<domini::model::Menu*> LlistaMenus();
		static bool ExisteixMenu(std::string i_nom);
		static domini::model::Menu* ObteMenu(std::string i_nom);

		static std::set<domini::model::Restaurant*> LlistaRestaurants();
		static bool ExisteixRestaurant(std::string i_adreca);
		static domini::model::Restaurant* ObteRestaurant(std::string i_adreca);

		//////////////////////////////////////////
		//Aquesta part no és un afegit per tal de simplificar la creació d'objectes dins de l'entorn descrit a IES
		//////////////////////////////////////////
		static void RegistraIngredient(domini::model::Ingredient* i_nouRegistre);
		static void RegistraProducte(domini::model::Producte* i_nouRegistre);
		static void RegistraPlat(domini::model::Plat* i_nouRegistre);
		static void RegistraPlatNormal(domini::model::PlatNormal* i_nouRegistre);
		static void RegistraPostre(domini::model::Postre* i_nouRegistre);
		static void RegistraBeguda(domini::model::Beguda* i_nouRegistre);
		static void RegistraRestaurant(domini::model::Restaurant* i_nouRegistre);
		static void RegistraMenu(domini::model::Menu* i_nouRegistre);


	private:
		static void InicialitzaDadesFalses();

		static bool s_dadesInicialitzades;
		static std::unordered_set<std::shared_ptr<domini::model::Ingredient>> s_ingredients;
		static std::unordered_set<std::shared_ptr<domini::model::Producte>> s_productes;
		static std::unordered_set<std::shared_ptr<domini::model::Plat>> s_plats;
		static std::unordered_set<std::shared_ptr<domini::model::PlatNormal>> s_platsNormals;
		static std::unordered_set<std::shared_ptr<domini::model::Postre>> s_postres;
		static std::unordered_set<std::shared_ptr<domini::model::Beguda>> s_begudes;
		static std::unordered_set<std::shared_ptr<domini::model::Restaurant>> s_restaurants;
		static std::unordered_set<std::shared_ptr<domini::model::Menu>> s_menus;
	};
}