/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:06:00 by snovakov          #+#    #+#             */
/*   Updated: 2024/02/29 16:06:02 by snovakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;

a.setRawBits(10);
b.setRawBits(20);
c.setRawBits(30);
c = b;

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
c.setRawBits(42);
std::cout << c.getRawBits() << std::endl;
return 0;
}
