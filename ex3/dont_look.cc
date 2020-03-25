#include "cyber.h"

int no_itsumim = 1;
int cyber_count = 0;

void cyber1(int i) {
    ++cyber_count;
    if (i == 6) {
        no_itsumim = 0;
    }
}

void cyber2(int i) {
    ++cyber_count;
    if (i == 3) {
        no_itsumim = 0;
    }
}

void more_cyber1() {
    ++cyber_count;
}

void more_cyber2() {
    ++cyber_count;
}

void more_cyber3() {
    ++cyber_count;
}

void more_cyber4() {
    ++cyber_count;
}

void more_cyber5() {
    ++cyber_count;
}

void more_cyber6() {
    ++cyber_count;
}

void more_cyber7() {
    ++cyber_count;
    no_itsumim = 0; 
}

void more_cyber8() {
    ++cyber_count;
}

void more_cyber9() {
    ++cyber_count;
}

void more_cyber10() {
    ++cyber_count;
}

