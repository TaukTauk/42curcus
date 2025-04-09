#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
		void announce (void);
	public:
		Zombie(std::string);
		~Zombie();
		Zombie* newZombie(std::string name);
		void randomChump(std::string name);
};

#endif