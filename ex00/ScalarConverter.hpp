/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:23 by lkavalia          #+#    #+#             */
/*   Updated: 2023/05/26 21:09:37 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

# include	<stdlib.h>
# include	<cctype>
# include	<cstdlib>
# include	<math.h>
# include	<cfloat>
# include	<climits>
# include	<iomanip>
# include	<cerrno>
# include	<iostream>
# include	<string>
#include	<locale> 

class	ScalarConverter
{
	public:
		//Member functions	---------->
		static void	convert(std::string literal);
	private:
		//Canonical form	---------->
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);

		ScalarConverter&	operator=(const ScalarConverter& other);
};

# define	CHAR	1
# define	INT		2
# define	FLOAT	3
# define	DOUBLE	4
# define	PSEUDO	5
# define	ERROR	-2

# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif