/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:17:21 by jberay            #+#    #+#             */
/*   Updated: 2024/04/11 09:04:18 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        j = -1;
        while (argv[i][++j])
            std::cout << (char)toupper(argv[i][j]);
        i++;
        if (i < argc)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
