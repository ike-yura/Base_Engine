#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class CsvLoader {
public:
    CsvLoader(const std::string& filename);

    bool load();       // ����ǂݍ���
    bool reload();     // �ēǂݍ���

    int getIntValue(const std::string& tag, int defaultValue = 0) const;
    float getFloatValue(const std::string& tag, float defaultValue = 0.0f) const;
    std::string getStringValue(const std::string& tag, const std::string& defaultValue = "") const;

private:
    std::string filePath;  // �ēǂݍ��ݗp�ɕۑ�
    std::vector<std::vector<std::string>> data;
    std::unordered_map<std::string, size_t> tagIndexMap; // �^�O�̃L���b�V��
};
