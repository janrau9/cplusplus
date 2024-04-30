/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:02:50 by janraub           #+#    #+#             */
/*   Updated: 2024/04/26 13:28:20 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include "Node.hpp"

class LinkedList
{
		private:
				Node* head;
		public:
				LinkedList();
				~LinkedList();
				LinkedList(const LinkedList& other);
				LinkedList& operator=(const LinkedList& other);
				void append(void *content);
			//  Node *getHead() const;
};

#endif