#pragma once
#include <exception>

namespace domini
{
	class JaExisteixProducte : public std::exception {};
	class MassaProductes : public std::exception {};
	class PostreEnMassaMenus : public std::exception {};
	class MenuInfantilIncorrecte : public std::exception {};
	class RestaurantNoOfereixBeguda : public std::exception {};
	class PreuIncorrecte : public std::exception {};
}