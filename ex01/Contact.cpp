/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:38:40 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/18 16:53:37 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"


void Contact::setFirstName(const std::string& fname) {
    first_name = fname;
}

void Contact::setLastName(const std::string& lname) {
    last_name = lname;
}

void Contact::setNickname(const std::string& nname) {
    nickname = nname;
}
void Contact::setPhoneNumber(const std::string& pnumber) {
    phone_number = pnumber;
}
void Contact::setDarkestSecret(const std::string& secret) {
    darkest_secret = secret;
}

std::string Contact::getFirstName() const {
    return first_name;
}
std::string Contact::getLastName() const {
    return last_name;
}
std::string Contact::getNickname() const {
    return nickname;
}
std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}

Contact::Contact() {
}
Contact::~Contact() {
}

