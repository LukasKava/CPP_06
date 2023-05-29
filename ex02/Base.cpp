/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:03:06 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/29 18:45:12 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	std::cout << RED "Virtual destructor has been called!" BLANK << std::endl;
}

Base*	generate(void)
{
	Base*	result = NULL;

	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			result = new A(); 
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
			break;
	}
	return (result);
}

void	indentify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << GREEN "It is A" BLANK << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << GREEN "It is B" BLANK << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << GREEN "It is C" BLANK << std::endl;
	else
		std::cout << RED "It is neighter A, B or C" BLANK << std::endl;
}

void	indentify(Base& p)
{
	try{	A&	 check_A = dynamic_cast<A&>(p);	(void)check_A;}
	catch (std::exception& bad_cast)
	{
		std::cout << RED "It is not class A!" BLANK << std::endl;

		try{	B&	check_B = dynamic_cast<B&>(p);	(void)check_B;}
		catch (std::exception& bad_cast)
		{
			std::cout << RED "It is not class B!" BLANK << std::endl;

			try {	C&	check_C = dynamic_cast<C&>(p);	(void)check_C;}
			catch (std::exception& bad_cast)
			{
				std::cout << RED "It is also not class C!" BLANK << std::endl;
				return ;
			}
			std::cout << GREEN "It is class C!" BLANK << std::endl;
			return ; 
		}
		std::cout << GREEN "It is class B!" BLANK << std::endl;
		return ;
	}
	std::cout << GREEN "It is class A!" BLANK << std::endl;
}
