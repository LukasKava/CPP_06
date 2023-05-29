/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:23:13 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/28 20:34:20 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
# define	SERIALIZER_HPP

# include <cstdint>
# include <stdint.h>
# include <string>
# include <iostream>

typedef	struct s_data
{
	int			random_nbr;
	std::string	random_str;
}Data;


class	Serializer
{
	public:
		//Member functions	---------->
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		//Canonical form	---------->
		Serializer(void);
		~Serializer(void);
		
		Serializer(const Serializer& other);
		
		Serializer&	operator=(const Serializer& other);
};

# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif