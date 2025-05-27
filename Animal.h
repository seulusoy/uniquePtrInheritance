#ifndef __ANIMAL_H__
#define __ANIMAL_H__

	#include <iostream>
	#include <memory>

	class Animal{
		public:
			Animal();
			virtual ~Animal();
			virtual void speak() const;
			void query();
			static std::unique_ptr<Animal> create();
		private:
			int result;
	};

	class Cat:public Animal{
		public:
			Cat();
			void speak() const override;
			~Cat();
		private:
			int myConstant;
	};

	class Dog:public Animal{
		public:
			Dog();
			void speak() const override;
			~Dog();
		private:
			int myConstant;
	};

#endif