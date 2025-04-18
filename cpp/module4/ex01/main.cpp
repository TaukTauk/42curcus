#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <sstream>

int main()
{
    std::string count;
    int number;
    std::cout << "Enter the count of animals : ";
    std::getline(std::cin, count);
    std::stringstream(count) >> number;
    if (number <= 0 || number > 100) {
        std::cout << "Please enter a number between 0 and 100" << std::endl;
        return 0;
    }
    
    Dog dog("Rex");
    Cat cat("Whiskers");
    
    std::cout << "Dog's idea: " << dog.getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << cat.getIdea(0) << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    i->makeSound();
    j->makeSound();
    delete j;
    delete i;
    
    std::cout << "############################" << std::endl;
    std::cout << "####### Start of test ######" <<std::endl;
    std::cout << "############################" << std::endl << std::endl;
    
    Animal* animals[number];
    for (int k = 0 ; k < number ; k++) {
        if (k % 2 == 0) {
            animals[k] = new Cat();
        } else {
            animals[k] = new Dog();
        }
    }
    
    for (int l = 0; l < number ; l++) {
        delete animals[l];
    }
    
    return 0;
}