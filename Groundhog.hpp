/*
** EPITECH PROJECT, 2022
** Groundhog
** File description:
** Groundhog
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>
#include <tgmath.h>
#include <iomanip>

class Groundhog {
    public:
        Groundhog(char *);
        ~Groundhog();
        void print();
        bool waitValue();
        double average();
        double median();
        double deviation();
        double evolution(double);
        double IncAverage();
        bool checkForSwitch(double, double);
        void compute(double);
    protected:
    private:
        std::string _fileContent;
        std::list<double> _data;
        std::list<double> _weirdest;
        int _switchnb;
        int _dataLentgh;
        int _days;
        int _lastEvol;
};

#define raise(msg)                                              \
do {                                                            \
    std::cerr << msg;                                           \
    exit(84);                                                    \
} while (0)
