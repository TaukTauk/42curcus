#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string);
		~Dog();
		Dog(const Dog &other);
		using Animal::operator=;
		void makeSound(void) const;
		std::string getIdea(int Index) {return this->brain->getIdea(Index);}
};

#endif