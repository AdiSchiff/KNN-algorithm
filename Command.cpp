//
// Created by adi on 1/15/23.
//

#include "Command.h"

string Command::getDescription() const {
    return this->description;
}
DefaultIO Command::getDio() const {
    return this->dio;
}

Command::~Command() {

}
