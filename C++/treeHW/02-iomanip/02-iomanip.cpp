#include <iostream>
#include <iomanip>
#include "spdlog/spdlog.h"
#include <sstream>
#include <string>

using namespace std;

int main()
{

    int a = 555;
    // std::setw
    ostringstream fmtstr;
    fmtstr << "|12345|\n";
    string line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::setw(2) << a << "|"<< std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::setw(3) << a << "|"<< std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::setw(4) << a << "|"<< std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::setw(5) << a << "|"<< std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << a << "|" << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "-----\n";
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();

    // left or right align
    fmtstr << "|12345|\n";
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    char prev = fmtstr.fill('0');
    fmtstr << "|" << std::right << std::setw(4) << a << "|" << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::left  << std::setw(4) << a << "|" << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "|" << std::setw(4) << a << "|" << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr.fill(prev);
    fmtstr << "|" << std::setw(4) << a << "|" << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << "-----\n";
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();

    // setprecision
    double b = 15.12;
    fmtstr << std::setprecision(3) << b << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << std::setprecision(4) << b << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << std::setprecision(5) << b << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << std::scientific << b << std::endl;
    line = fmtstr.str();
    spdlog::info(line);
    fmtstr.clear();
    fmtstr << std::fixed << b << std::endl;
    line = fmtstr.str();
    spdlog::info(line); 
    return 0;

}