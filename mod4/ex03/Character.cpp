/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:06:11 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 14:04:59 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""), _floor(LinkedList())
{
    //std::cout <<  this->_name << " default constructor called" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name), _floor(LinkedList())
{
    //std::cout <<  this->_name << " constructor called" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = nullptr;
}

Character::~Character()
{
    std::cout <<  this->_name << " virtual deconstructor called" << std::endl;
    for (size_t i = 0; i < 4; ++i)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
    }
}

Character::Character(const Character& other) : _name(other._name),  _floor(LinkedList(other._floor))
{
    // std::cout <<  this->_name << " Copy constructor called " << std::endl;
    for (size_t i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
		    _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other)
{
    //std::cout <<  this->_name << " assignation called" << std::endl;
    if (this != &other)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = nullptr;
            }
        }
        for (size_t i = 0; i < 4; ++i)
        {
            if (other._inventory[i])
		        _inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}


std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (size_t i = 0; i < 4; ++i)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 4 || _inventory[idx] == NULL)
        return ;
    _floor.append(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 4 || _inventory[idx] == NULL)
        return ;
    _inventory[idx]->use(target);
}