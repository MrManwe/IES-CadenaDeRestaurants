#pragma once
#include <exception>

namespace dades
{
	class IngredientNoExisteix : public std::exception {};
	class ProducteNoExisteix : public std::exception {};
	class PlatNoExisteix : public std::exception {};
	class PlatNormalNoExisteix : public std::exception {};
	class PostrelNoExisteix : public std::exception {};
	class BegudaNoExisteix : public std::exception {};
	class MenuNoExisteix : public std::exception {};
	class RestaurantNoExisteix : public std::exception {};
}