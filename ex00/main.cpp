/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:40 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/25 14:52:17 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "ERROR: incorrect amount of arguments! Please input 2 arguments!" BLANK << std::endl;
		return (1);
	}
	if (argv[1] == NULL)
	{
		std::cout << RED "ERROR: Second argument cannot be NULL!" BLANK << std::endl;
		return (1);
	}
	std::string	str(argv[1]);
	ScalarConverter::convert(str);
	return (0);
}