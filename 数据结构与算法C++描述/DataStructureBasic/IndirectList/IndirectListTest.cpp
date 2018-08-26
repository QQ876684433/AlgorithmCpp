//
// Created by steve on 18-7-23.
//

#include <iostream>
#include "IndirectList.h"

int main(){
    IndirectList<int> list = IndirectList<int>(20);
    for (int i = 0; i < 20; ++i) {
        list.Insert(i,i+1);
    }
    return 0;
}