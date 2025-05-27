#include <iostream>
#include <memory>
#include "Animal.h"

using namespace std;

Animal::Animal(){
	cout << "Animal is being created" << endl;
}

std::unique_ptr<Animal> Animal::create(){
	Animal temp;
	temp.query();
	if (temp.result==0){
		return std::make_unique<Cat>();
	}
	else if (temp.result==1){
		return std::make_unique<Dog>();
	}
	return nullptr;
}

void Animal::query(){
	cout << "Press 0 for cat, 1 for dog" << endl;
	cin >> this->result;
}
	

Animal::~Animal(){
	cout << "Animal is being killed" << endl;
}

void Animal::speak() const{
	cout << "Animal speaks" << endl;
}

Cat::Cat(){
	cout << "Cat is being created" << endl;
	this->myConstant = 50;
}
	

void Cat::speak() const{
	std::cout << "Cat meows" << endl;
	std::cout << "My constant is " << this->myConstant << endl;
}

Cat::~Cat(){
	cout << "Cat is being killed" << endl;
}

Dog::Dog(){
	cout << "Dog is being created" << endl;
	this->myConstant = 100;
}
	

void Dog::speak() const{
	std::cout << "Dog barks" << endl;
	std::cout << "My constant is " << this->myConstant << endl;
}

Dog::~Dog(){
	cout << "Dog is being killed" << endl;
}


