/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:06:52 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/28 20:57:24 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	uintptr_t	location;
	Data		data_holder;
	Data		*deserialized;
	
	data_holder.random_nbr = 10;
	data_holder.random_str = "42 Wolfsburg";
	std::cout << "Check before doing anything data_holder:" << std::endl;
	std::cout << "Address:	" << &data_holder << std::endl;
	std::cout << "Random nbr:	" << data_holder.random_nbr << std::endl;
	std::cout << "Random str:	" << data_holder.random_str << std::endl;
	
	location = Serializer::serialize(&data_holder);
	std::cout << "\nCheck serialize:" << std::endl;
	std::cout << "Address:	" << location << std::endl;
	
	deserialized = Serializer::deserialize(location);
	std::cout << "\nCheck deserialized:" << std::endl;
	std::cout << "Address:	" << deserialized << std::endl;
	std::cout << "Random nbr:	" << deserialized->random_nbr << std::endl;
	std::cout << "Random str:	" << deserialized->random_str << std::endl;
	return (0);
}