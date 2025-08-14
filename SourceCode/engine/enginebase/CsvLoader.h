#pragma once
#include <string>
#include <vector>

class CsvLoader {
public:
    CsvLoader(const std::string& filename);
    int getIntValue(const std::string& tag);
    float getFloatValue(const std::string& tag);
    std::string getStringValue(const std::string& tag);

private:
    std::vector<std::vector<std::string>> data;
};