/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace state{
 
    ElementChars& State::getChars() {
        return chars;
    }

    int State::getGrid() {
        return grid;
    }

    void State::setGrid (int g){
        grid = g ;
    }

    State::State() {
        this->grid=1;
    }

    
}