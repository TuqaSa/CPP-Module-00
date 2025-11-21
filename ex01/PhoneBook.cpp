/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:39:25 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/15 21:53:55 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0){}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    do {
        std::cout << "First name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty!" << std::endl;
        }
    } while (input.empty());
    newContact.setFirstName(input);

    do {
        std::cout << "Last name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty!" << std::endl;
        }
    } while (input.empty());
    newContact.setLastName(input);

    do {
        std::cout << "Nickname: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty!" << std::endl;
        }
    } while (input.empty());
    newContact.setNickname(input);

    do {
        std::cout << "Phone number: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty!" << std::endl;
        }
    } while (input.empty());
    newContact.setPhoneNumber(input);

    do {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty!" << std::endl;
        }
    } while (input.empty());
    newContact.setDarkestSecret(input);

    contacts[oldestIndex] = newContact;
    oldestIndex = (oldestIndex + 1) % 8;

    if (contactCount < 8) {
        contactCount++;
    }

    std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::truncate(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::displayContact(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << truncate(contacts[index].getFirstName());
    std::cout << "|" << std::setw(10) << truncate(contacts[index].getLastName());
    std::cout << "|" << std::setw(10) << truncate(contacts[index].getNickname());
    std::cout << "|" << std::endl;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "|" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        displayContact(i);
    }

    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cin.ignore(10000, '\n');

    if (index < 0 || index >= contactCount) {
        std::cout << "Index out of range!" << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}
