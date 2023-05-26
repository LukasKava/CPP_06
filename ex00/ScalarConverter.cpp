/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:20 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/26 21:12:29 by lkavalia         ###   ########.fr       */
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

	if (str.length() == 1)
	{
		if (str[0] >= '0' && str[0] <= '9')
			return (INT);
		return	(CHAR);
	}
	if (str == "-inff" || str == "+inff" || str == "nanf" || \
		str == "-inf" || str == "+inf" || str == "nan")
		return (PSEUDO);
	if (str[0] == '-' || str[0] == '+')
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

void	output_message(int ii, char cc, float fy, double dz, bool possible)
{
	if (cc > 32 && cc < 127)
		std::cout << "char: 	" << cc << std::endl;
	else if (ii < 0 || ii > 127)
		std::cout << "char: 	impossible" << std::endl;
	else
		std::cout << "char: 	Non displayable" << std::endl;
	(void) possible;
	if (possible == false)
		std::cout << "int:	impossible" << std::endl;
	else
		std::cout << "int:	" << ii << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float:	" << fy << 'f' << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double:	" << dz << std::endl;
}

void	handle_float_and_double(float	y)
{
	char	c;
	if (y < 0 || y > 127)
		c = 128;
	else
		c = static_cast<char>(y);
	int		i = static_cast<int>(y);
	double	z = static_cast<double>(y);
	if (y < INT_MIN || y > INT_MAX)
		output_message(i, c, y, z, false);
	else
		output_message(i, c, y, z, true);
}

void	handle_pseaudo(std::string	str)
{
	float	y = static_cast<float>(atof(str.c_str()));
	double	z = static_cast<double>(atof(str.c_str()));
	int		i = static_cast<int>(y);
	output_message(i, 128, y, z, false);
}

void	handle_int(int	i)
{
	char	c = static_cast<char>(i);
	float	y = static_cast<float>(i);
	double	z = static_cast<double>(i);
	output_message(i, c, y, z, true);
}

void	handle_char(char c)
{
	int		i = static_cast<int>(c);
	float	y = static_cast<float>(c);
	double	z = static_cast<double>(c);
	output_message(i, c, y, z, true);
}

void	ScalarConverter::convert(std::string literal)
{
	int	type = checkType(literal);
	std::cout << GREEN "MY TYPE IS: " BLANK << type << std::endl;
	switch (type)
	{
		case (ERROR):
			std::cout << RED "ERROR: invalid input!" BLANK << std::endl;
			return;
		case (CHAR):
			handle_char(literal.at(0));
			break;
		case (INT):
		{
			char		*pend;
			long int	tmp_check = strtol(literal.c_str(), &pend, 10);
			if (literal == pend)
			{
				std::cout << RED "ERROR: input str failed to parse for int!" BLANK << std::endl;
				return ;
			}
			if (errno == ERANGE && (tmp_check == LONG_MAX || tmp_check == LONG_MIN))
			{
				std::cout << RED "ERROR: input str is out of the range for int!" BLANK << std::endl;
				return ;
			}
			if (tmp_check < INT_MIN || tmp_check > INT_MAX)
			{
				std::cout << RED "ERROR: input str is out of the range for int!" BLANK << std::endl;
				return ;
			}
			handle_int(tmp_check);
			break;
		}
		case (PSEUDO):
			handle_pseaudo(literal);
			break;
		case (FLOAT):
		{
			char		*pend;
			double		tmp_check = strtod(literal.c_str(), &pend);
			if (literal == pend)
			{
				std::cout << RED "ERROR: input str failed to parse for float!" BLANK << std::endl;
				return ;
			}
			if (errno == ERANGE && (tmp_check == HUGE_VAL))
			{
				std::cout << RED "ERROR1: input str is out of the range for float!" BLANK << std::endl;
				return ;
			}
			handle_float_and_double(tmp_check);
			break;
		}
		case (DOUBLE):
		{
			char		*pend;
			double		tmp_check = strtod(literal.c_str(), &pend);
			if (literal == pend)
			{
				std::cout << RED "ERROR: input str failed to parse for float!" BLANK << std::endl;
				return ;
			}
			if (errno == ERANGE && (tmp_check == HUGE_VAL))
			{
				std::cout << RED "ERROR1: input str is out of the range for float!" BLANK << std::endl;
				return ;
			}
			handle_float_and_double(tmp_check);
			break ;
		}
	}
}