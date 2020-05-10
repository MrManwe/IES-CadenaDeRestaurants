#include "BaseDeDades.h"
#include "Excepcions.h"

namespace dades
{
	std::unordered_set<std::shared_ptr<domini::model::Ingredient>> BaseDeDades::s_ingredients;
	std::unordered_set<std::shared_ptr<domini::model::Producte>> BaseDeDades::s_productes;
	std::unordered_set<std::shared_ptr<domini::model::Plat>> BaseDeDades::s_plats;
	std::unordered_set<std::shared_ptr<domini::model::PlatNormal>> BaseDeDades::s_platsNormals;
	std::unordered_set<std::shared_ptr<domini::model::Postre>> BaseDeDades::s_postres;
	std::unordered_set<std::shared_ptr<domini::model::Beguda>> BaseDeDades::s_begudes;
	std::unordered_set<std::shared_ptr<domini::model::Restaurant>> BaseDeDades::s_restaurants;
	std::unordered_set<std::shared_ptr<domini::model::Menu>> BaseDeDades::s_menus;
	
	bool BaseDeDades::s_dadesInicialitzades = false;

	template<typename Content>
	std::set<Content*> ObtenirLLista(const std::unordered_set<std::shared_ptr<Content>>& i_map)
	{
		std::set<Content*> result;
		for (const auto& it : i_map)
		{
			result.emplace(it.get());
		}
		return result;
	}

	template<typename Exception, typename Content>
	Content* CercaPerNom(const std::string& i_nom, const std::unordered_set<std::shared_ptr<Content>>& i_content)
	{
		auto it = std::find_if(i_content.begin(), i_content.end(), [i_nom](auto i_value){ return i_value->ObteNom() == i_nom;});
		if (it == i_content.end())
		{
			throw Exception();
		}
		else
		{
			return it->get();
		}
	}

	template<typename Content>
	bool Existeix(const std::string& i_nom, const std::unordered_set<std::shared_ptr<Content>>& i_content)
	{
		auto it = std::find_if(i_content.begin(), i_content.end(), [i_nom](auto i_value) { return i_value->ObteNom() == i_nom; });
		return it != i_content.end();
	}

	std::set<domini::model::Ingredient*> BaseDeDades::LlistaIngredients()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_ingredients);
	}

	bool BaseDeDades::ExisteixIngredient(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_ingredients);
	}

	domini::model::Ingredient* BaseDeDades::ObteIngredient(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<IngredientNoExisteix>(i_nom, s_ingredients);
	}

	std::set<domini::model::Producte*> BaseDeDades::LlistaProductes()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_productes);
	}

	bool BaseDeDades::ExisteixProducte(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_productes);
	}

	domini::model::Producte* BaseDeDades::ObteProducte(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<ProducteNoExisteix>(i_nom, s_productes);
	}

	std::set<domini::model::Plat*> BaseDeDades::LlistaPlats()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_plats);
	}

	bool BaseDeDades::ExisteixPlat(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_plats);
	}

	domini::model::Plat* BaseDeDades::ObtePlat(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<PlatNoExisteix>(i_nom, s_plats);
	}

	std::set<domini::model::PlatNormal*> BaseDeDades::LlistaPlatsNormal()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_platsNormals);
	}

	bool BaseDeDades::ExisteixPlatNormal(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_platsNormals);

	}

	domini::model::PlatNormal* BaseDeDades::ObtePlatNormal(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<PlatNormalNoExisteix>(i_nom, s_platsNormals);
	}

	std::set<domini::model::Postre*> BaseDeDades::LlistaPostres()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_postres);
	}

	bool BaseDeDades::ExisteixPostre(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_postres);
	}

	domini::model::Postre* BaseDeDades::ObtePostre(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<PostrelNoExisteix>(i_nom, s_postres);
	}

	std::set<domini::model::Beguda*> BaseDeDades::LlistaBegudes()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_begudes);
	}

	bool BaseDeDades::ExisteixBeguda(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_begudes);
	}

	domini::model::Beguda* BaseDeDades::ObteBeguda(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<BegudaNoExisteix>(i_nom, s_begudes);
	}

	std::set<domini::model::Menu*> BaseDeDades::LlistaMenus()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_menus);
	}

	bool BaseDeDades::ExisteixMenu(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return Existeix(i_nom, s_menus);
	}

	domini::model::Menu* BaseDeDades::ObteMenu(std::string i_nom)
	{
		InicialitzaDadesFalses();
		return CercaPerNom<MenuNoExisteix>(i_nom, s_menus);
	}

	std::set<domini::model::Restaurant*> BaseDeDades::LlistaRestaurants()
	{
		InicialitzaDadesFalses();
		return ObtenirLLista(s_restaurants);
	}

	bool BaseDeDades::ExisteixRestaurant(std::string i_adreca)
	{
		InicialitzaDadesFalses();
		auto it = std::find_if(s_restaurants.begin(), s_restaurants.end(), [i_adreca](auto i_value) { return i_value->ObteAdreca() == i_adreca; });
		return it != s_restaurants.end();
	}

	domini::model::Restaurant* BaseDeDades::ObteRestaurant(std::string i_adreca)
	{
		InicialitzaDadesFalses();
		auto it = std::find_if(s_restaurants.begin(), s_restaurants.end(), [i_adreca](auto i_value) { return i_value->ObteAdreca() == i_adreca; });
		if (it == s_restaurants.end())
		{
			throw RestaurantNoExisteix();
		}
		else
		{
			return it->get();
		}
	}

	void BaseDeDades::RegistraIngredient(domini::model::Ingredient* i_nouRegistre)
	{
		s_ingredients.emplace(std::shared_ptr<domini::model::Ingredient>(i_nouRegistre));
	}

	void BaseDeDades::RegistraProducte(domini::model::Producte* i_nouRegistre)
	{
		s_productes.emplace(std::shared_ptr<domini::model::Producte>(i_nouRegistre));
	}

	void BaseDeDades::RegistraPlat(domini::model::Plat* i_nouRegistre)
	{
		s_plats.emplace(std::shared_ptr<domini::model::Plat>(i_nouRegistre));
	}

	void BaseDeDades::RegistraPlatNormal(domini::model::PlatNormal* i_nouRegistre)
	{
		s_platsNormals.emplace(std::shared_ptr<domini::model::PlatNormal>(i_nouRegistre));
	}

	void BaseDeDades::RegistraPostre(domini::model::Postre* i_nouRegistre)
	{
		s_postres.emplace(std::shared_ptr<domini::model::Postre>(i_nouRegistre));
	}

	void BaseDeDades::RegistraBeguda(domini::model::Beguda* i_nouRegistre)
	{
		s_begudes.emplace(std::shared_ptr<domini::model::Beguda>(i_nouRegistre));
	}

	void BaseDeDades::RegistraRestaurant(domini::model::Restaurant* i_nouRegistre)
	{
		s_restaurants.emplace(std::shared_ptr<domini::model::Restaurant>(i_nouRegistre));
	}

	void BaseDeDades::RegistraMenu(domini::model::Menu* i_nouRegistre)
	{
		s_menus.emplace(std::shared_ptr<domini::model::Menu>(i_nouRegistre));
	}

	void BaseDeDades::InicialitzaDadesFalses()
	{
		if (s_dadesInicialitzades == true)
		{
			return;
		}
		else
		{
			s_dadesInicialitzades = true;
			//Ingredients de mostra
			domini::model::Ingredient* ingredient1 = new domini::model::Ingredient("Tomaquet", false);
			domini::model::Ingredient* ingredient2 = new domini::model::Ingredient("Carn Picada", true);
			domini::model::Ingredient* ingredient3 = new domini::model::Ingredient("Massa de Pizza", false);
			domini::model::Ingredient* ingredient4 = new domini::model::Ingredient("Gelat de Vainilla", false);
			domini::model::Ingredient* ingredient5 = new domini::model::Ingredient("Espaguetis", false);
			

			//Plats Normals de mostra
			domini::model::PlatNormal* plat1 = new domini::model::PlatNormal("Espaguetis Bolonyesa", 10.0f);
			plat1->AfegirIngredient(ingredient1);
			plat1->AfegirIngredient(ingredient2);
			plat1->AfegirIngredient(ingredient5);
			

			domini::model::PlatNormal* plat2 = new domini::model::PlatNormal("Pizza Barbacoa", 12.0f);
			plat2->AfegirIngredient(ingredient1);
			plat2->AfegirIngredient(ingredient3);
			plat2->AfegirIngredient(ingredient2);

			

			domini::model::PlatNormal* plat3 = new domini::model::PlatNormal("Salmorejo", 7.0f);
			plat3->AfegirIngredient(ingredient1);

			domini::model::PlatNormal* plat4 = new domini::model::PlatNormal("Amanida Caprese", 7.0f);
			plat4->AfegirIngredient(ingredient1);
			

			//Postres de mostra
			domini::model::Postre* postre1 = new domini::model::Postre("Bola de Vainilla", 4.0f);
			postre1->AfegirIngredient(ingredient4);

			//Begudes de mostra
			domini::model::Beguda* beguda1 = new domini::model::Beguda("Vi rosat", 5.0f, true);
			domini::model::Beguda* beguda2 = new domini::model::Beguda("Aigua", 1.0f, false);

			//Menus de mostra
			domini::model::Menu* menu1 = new domini::model::Menu("Menu Pasta", 20.0f, false);
			menu1->AfegeixPlatInclos(plat3);
			menu1->AfegeixPlatInclos(plat1);
			menu1->SetPostre(postre1);
			menu1->SetBeguda(beguda1);
			postre1->AfegeixMenu(menu1);

			domini::model::Menu* menu2 = new domini::model::Menu("Menu Pizza", 20.0f, false);
			menu2->AfegeixPlatInclos(plat3);
			menu2->AfegeixPlatInclos(plat2);
			menu2->SetPostre(postre1);
			menu2->SetBeguda(beguda1);
			postre1->AfegeixMenu(menu2);

			domini::model::Menu* menu3 = new domini::model::Menu("Menu Veggie", 15.0f, false);
			menu3->AfegeixPlatInclos(plat3);
			menu3->AfegeixPlatInclos(plat4);
			menu3->SetPostre(postre1);
			menu3->SetBeguda(beguda1);
			postre1->AfegeixMenu(menu3);
			
			//Resturants de Mostra
			domini::model::Restaurant* restaurant1 = new domini::model::Restaurant("Carrer1");

			auto afegeixPlat = [](domini::model::Restaurant* i_restaurant, domini::model::Plat* i_plat)
			{
				i_restaurant->AfegeixProducte(i_plat);
				for (domini::model::Ingredient* ingredient : i_plat->ObteIngredients())
				{
					i_restaurant->AfegeixIngredient(ingredient);
				}
			};

			afegeixPlat(restaurant1, plat1);
			afegeixPlat(restaurant1, plat2);
			afegeixPlat(restaurant1, plat3);
			afegeixPlat(restaurant1, plat4);
			afegeixPlat(restaurant1, postre1);
			restaurant1->AfegeixProducte(beguda1);
			restaurant1->AfegeixProducte(menu1);
			restaurant1->AfegeixProducte(menu2);
			restaurant1->AfegeixProducte(menu3);
		}
	}

	

}