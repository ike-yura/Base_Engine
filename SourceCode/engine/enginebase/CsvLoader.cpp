#include "csvLoader.h"
#include <fstream>
#include <sstream>

CsvLoader::CsvLoader(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
}

int CsvLoader::getIntValue(const std::string& tag) {
    for (auto& row : data) {
        if (row.size() >= 3 && row[1] == tag && !row[2].empty()) {
            return std::stoi(row[2]);
        }
    }
    return 0; // Œ©‚Â‚©‚ç‚È‚©‚Á‚½ê‡
}

float CsvLoader::getFloatValue(const std::string& tag) {
    for (auto& row : data) {
        if (row.size() >= 4 && row[1] == tag && !row[3].empty()) {
            return std::stof(row[3]);
        }
    }
    return 0.0f;
}

std::string CsvLoader::getStringValue(const std::string& tag) {
    for (auto& row : data) {
        if (row.size() >= 5 && row[1] == tag && !row[4].empty()) {
            return row[4];
        }
    }
    return "";
}
