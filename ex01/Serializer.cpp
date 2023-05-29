/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:07:06 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/28 20:23:49 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//Canonical form	----------------------------------------------------------->
Serializer::Serializer(void){ std::cout << GREEN "Default constructor" BLANK << std::endl;}

Serializer::~Serializer(void){ std::cout << GREEN "Default destructor" BLANK << std::endl;}

Serializer::Serializer(const Serializer& other)
{
	std::cout << GREEN "Default copy constructor" BLANK << std::endl;
	*this = other;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	std::cout << GREEN "Assigment overload" BLANK << std::endl;
	(void)other;
	return (*this);
}

//Member functions	----------------------------------------------------------->
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}