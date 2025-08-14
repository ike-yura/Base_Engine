#include "CsvLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CsvLoader::CsvLoader(const std::string& filename)
    : filePath(filename) {
    load();
}

bool CsvLoader::load() {
    data.clear();
    tagIndexMap.clear();

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "CSVファイルを開けませんでした: " << filePath << "\n";
        return false;
    }

    std::string line;
    size_t rowIndex = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() >= 2) {
            // 2列目（タグ名）をキャッシュ
            tagIndexMap[row[1]] = rowIndex;
        }

        data.push_back(row);
        rowIndex++;
    }

    return true;
}

bool CsvLoader::reload() {
    return load();
}

int CsvLoader::getIntValue(const std::string& tag, int defaultValue) const {
    auto it = tagIndexMap.find(tag);
    if (it != tagIndexMap.end()) {
        auto& row = data[it->second];
        if (row.size() >= 3 && !row[2].empty()) {
            return std::stoi(row[2]);
        }
    }
    return defaultValue;
}

float CsvLoader::getFloatValue(const std::string& tag, float defaultValue) const {
    auto it = tagIndexMap.find(tag);
    if (it != tagIndexMap.end()) {
        auto& row = data[it->second];
        if (row.size() >= 4 && !row[3].empty()) {
            return std::stof(row[3]);
        }
    }
    return defaultValue;
}

std::string CsvLoader::getStringValue(const std::string& tag, const std::string& defaultValue) const {
    auto it = tagIndexMap.find(tag);
    if (it != tagIndexMap.end()) {
        auto& row = data[it->second];
        if (row.size() >= 5 && !row[4].empty()) {
            return row[4];
        }
    }
    return defaultValue;
}
