#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class CsvLoader {
public:
    CsvLoader(const std::string& filename);

    bool load();       // 初回読み込み
    bool reload();     // 再読み込み

    int getIntValue(const std::string& tag, int defaultValue = 0) const;
    float getFloatValue(const std::string& tag, float defaultValue = 0.0f) const;
    std::string getStringValue(const std::string& tag, const std::string& defaultValue = "") const;

private:
    std::string filePath;  // 再読み込み用に保存
    std::vector<std::vector<std::string>> data;
    std::unordered_map<std::string, size_t> tagIndexMap; // タグのキャッシュ
};
