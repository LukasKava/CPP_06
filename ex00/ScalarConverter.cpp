/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:20 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/25 19:34:43 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//	Canonical Form	----------------------------------------------------------->
ScalarConverter::ScalarConverter(void) {	std::cout << "Constructor!" << std::endl;}

ScalarConverter::~ScalarConverter(void) {	std::cout << "Destructor!" << std::endl;}

ScalarConverter::ScalarConverter(const ScalarConverter&	other) { (void)other; std::cout << "Copy constructor" << std::endl;}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) { (void)other; std::cout << "Equal operator overload" << std::endl; return (*this);}

//	Member function	----------------------------------------------------------->
int	checkType(std::string&	str)
{
	int	i;
	int	str_lenght = str.length();

	if (str.length() == 1 && isdigit(str[0]))
		return	(CHAR);
	if (str == "-inff" || str == "+inff" || str == "nanf" || \
		str == "-inf" || str == "+inf" || str == "nan")
		return (PSEUDO);
	if (str[0] != '-' || str[0] != '+')
	{
		if (isdigit(str[1]) == 0)
			return (ERROR);
	}
	for (i = 1; i < str_lenght; i++)
	{
		if (isdigit(str[i]) == 0)
			break ;
	}
	if (str[i] == '\0')
		return (INT);
	if (str[i] == '.')
	{
		int	x;
		for (x = i + 1; x < str_lenght; x++)
		{
			if (isdigit(str[x]) == 0)
				break ;
		}
		if (str[x] == '\0')
			return (DOUBLE);
		if (str[x] == 'f' && str[x + 1] == '\0')
			return (FLOAT);
	}
	return (ERROR);
}

void	ScalarConverter::convert(std::string literal)
{
	int	type = checkType(literal);
	std::cout << GREEN "MY TYPE IS: " BLANK << type << std::endl;

	if (type == CHAR)
	{
		if (!std::isprint(literal[0]))
			std::cout << RED "char: Non displayable" BLANK << std::endl;
		std::cout << GREEN "char: " + literal << BLANK << std::endl;
	}
}