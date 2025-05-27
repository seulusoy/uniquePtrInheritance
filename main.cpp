#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
#include "Animal.h"

using namespace std;

vector<unique_ptr<Cat>> animalCats;
vector<unique_ptr<Dog>> animalDogs;

void addAnimals(){
	for(int i=0; i<5; ++i){
		std::unique_ptr<Animal> myAnimal = Animal::create();
		if(myAnimal){
			if (Cat* c = dynamic_cast<Cat*>(myAnimal.get())) {
				animalCats.push_back(std::unique_ptr<Cat>(c));
				myAnimal.release();
			} else if (Dog* d = dynamic_cast<Dog*>(myAnimal.get())) {
				animalDogs.push_back(std::unique_ptr<Dog>(d));
				myAnimal.release();
			}
		}
	}
}

int main(){
	addAnimals();
	for(const auto& c: animalCats){
		c->speak();
	}
	for(const auto& d: animalDogs){
		d->speak();
	}
	
	return 0;
}
	