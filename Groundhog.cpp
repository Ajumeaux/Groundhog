/*
** EPITECH PROJECT, 2022
** Groundhog
** File description:
** Groundhog
*/

#include "Groundhog.hpp"

Groundhog::Groundhog(char *day)
{
    _dataLentgh = 0;
    _days = atoi(day);
    _lastEvol = 0;
    _switchnb = 0;
}


bool isFloat(std::string arg) {
    std::istringstream iss(arg);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

bool Groundhog::waitValue() {
    std::string line;
    std::getline(std::cin, line);
    if (!isFloat(line) && line != "STOP")
        exit(84);
    if (line != "STOP") {
        this->compute(atof(line.c_str()));
        return true;
    } else {
        std::cout << "Global Tendency switched " << _switchnb << " times\n";
        if (!_weirdest.empty()) {
            int j = 0;
            std::cout << _switchnb << " weirdest values are [";
            for (std::list<double>::iterator i = _weirdest.begin(); j <= _switchnb; std::advance(i, 1), j++) {
                if (j == _switchnb) {
                    std::cout << *i << "]\n";
                }
                else std::cout << *i << ", ";
            }
        }
        return false;
    }
}

bool Groundhog::checkForSwitch(double evolution, double value) {
    int currEvol = evolution < 0 ? -1 : 1;
    if (evolution == 0)
        return false;
    if (currEvol != _lastEvol && _lastEvol != 0) {
        _lastEvol = currEvol;
        _weirdest.push_back(value);
        _switchnb++;
        return true;
    }
    if (_lastEvol == 0)
        _lastEvol = currEvol;
    return false;
}

void Groundhog::compute(double value) {
    _data.push_back(value);
    ++_dataLentgh;
    std::cout << std::fixed << std::setprecision(2);
    if (_dataLentgh < _days) {
        std::cout << "g=nan" << "       " << "r=nan%" << "       " << "s=nan\n";
    } else if (_dataLentgh == _days) {
        std::cout << "g=nan" << "       " << "r=nan%" << "       " << "s=" << this->deviation() << "\n";
    } else if (_dataLentgh > _days) {
        if (this->checkForSwitch(this->evolution(value), value)) {
            std::cout << "g=" << std::fixed << std::setprecision(2) << this->IncAverage() << "       " << "r=" << std::fixed << std::setprecision(0) << std::round(this->evolution(value)) << "%" << "       " << "s=" << std::fixed << std::setprecision(2) << this->deviation() << "       a switch occurs\n";
        } else
            std::cout << "g=" << std::fixed << std::setprecision(2) << this->IncAverage() << "       " << "r=" << std::fixed << std::setprecision(0) << std::round(this->evolution(value)) << "%" << "       " << "s=" << std::fixed << std::setprecision(2) << this->deviation() << "\n";
    }
}

double Groundhog::evolution(double value) {
    std::list<double>::iterator i = _data.begin();
    std::advance(i, _dataLentgh - _days - 1);
    double result = (*i == 0) ? 2 : value / *i;
    return (result - 1) * 100;
}

//3.3 + 1.7 + 2 + 1.2 + 1.5 + 0.8 + 1.3 = 11.8
//1.7 + 2 + 1.2 + 1.5 + 0.8 + 1.3 + 0.8 = 9.3

double Groundhog::IncAverage() {
    double result = 0;
    int j = (_dataLentgh - _days) < 0 ? 0 : _dataLentgh - _days;
    std::list<double>::iterator i = _data.begin();
    std::advance(i, _dataLentgh - _days - 1);
    double lastTemp = *i;

    std::advance(i, 1);
    for (; j != _dataLentgh; std::advance(i, 1), j++) {
        if (*i > lastTemp) {
            result += (j != 0) ? (*i - lastTemp) : 0;
            lastTemp = *i;
        }
    }
    return (_days > 0) ? result / _days : 0;
}

void Groundhog::print()
{
    for (std::list<double>::iterator i = _data.begin(); i != _data.end(); ++i) {
        std::cout << *i << "\n";
    }
    std::cout << "Size : " << _dataLentgh << "\n";
    std::cout << "Last value : " << _data.back() << "\n";
}

double Groundhog::average() {
    double total = 0;

    std::list<double>::iterator i = _data.begin();
    std::advance(i, _dataLentgh - _days);
    for (; i != _data.end(); ++i) {
        total += *i;
    }
    return (total / (_days));
}

double Groundhog::median() {
    std::list<double> copy = _data;
    copy.sort();
    if (_dataLentgh % 2 == 0) {
        double tmp = 0;
        std::list<double>::iterator i = copy.begin();
        std::advance(i, _dataLentgh % 2);
        tmp = *i;
        ++i;
        return (tmp + *i) / 2;
    } else {
        std::list<double>::iterator i = copy.begin();
        std::advance(i, _dataLentgh % 2);
        return *i;
    }
}

double Groundhog::deviation() {
    double result = 0;
    double average = this->average();
    std::list<double>::iterator i = _data.begin();
    std::advance(i, _dataLentgh - _days);

    for (; i != _data.end(); ++i) {
        result += (*i - average) * (*i - average);
    }
    result = result / _days;
    return sqrt(result);
}

Groundhog::~Groundhog()
{
}

int printHelp() {
    std::cout << "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod the number of days defining a period\n";
    return 0;
}

int main(int ac, char **av) {
    if (ac != 2) {
        return 84;
    }
    std::string arg(av[1]);
    if (arg == "-h") {
        return printHelp();
    }
    if (isFloat(arg)) {
        Groundhog test(av[1]);
        for (;test.waitValue(););
        test.print();
        std::cout << "Average : " << test.average() << "\n";
        std::cout << "Median : " << test.median() << "\n";
        return 0;
    }
    return 84;
}