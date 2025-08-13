//#include "ExcelLoader.h"
//#include <stdexcept>
//
//xlnt::workbook ExcelLoader::workbook;
//std::unordered_map<std::string, std::unordered_map<std::string, std::string>> ExcelLoader::tag_values;
//
//void ExcelLoader::LoadExcelFile(const std::string& file_path)
//{
//    workbook.load(file_path);
//
//    for (auto ws : workbook)
//    {
//        ParseSheet(ws);
//    }
//}
//
//void ExcelLoader::ParseSheet(const xlnt::worksheet& ws)
//{
//    if (ws == nullptr) {
//        std::cout << "Not Excel Data" << std::endl;
//        return;
//    }
//    std::string sheet_title = ws.title();
//
//    for (auto row : ws.rows())
//    {
//        if (row[1].has_value()) // B��̃Z�����`�F�b�N
//        {
//            std::string tag = row[1].to_string(); // B��̒l���^�O�Ƃ���
//            std::string int_value = row[2].to_string(); // C��̒l(int)
//            std::string float_value = row[3].to_string(); // D��̒l(float)
//            std::string string_value = row[4].to_string(); // E��̒l(float)
//
//            // �^�O�Ɋ�Â��Ēl���i�[
//            tag_values[sheet_title][tag + "_int"] = int_value;
//            tag_values[sheet_title][tag + "_float"] = float_value;
//            tag_values[sheet_title][tag + "_string"] = string_value;
//        }
//    }
//}
//
////�^�O����֘A�t����
//std::string ExcelLoader::GetStringValue(const std::string& sheet_name, const std::string& tag)
//{
//    if (tag_values.find(sheet_name) != tag_values.end() && tag_values[sheet_name].find(tag) != tag_values[sheet_name].end())
//    {
//        return tag_values[sheet_name][tag];
//    }
//    return "";
//}
//
////int�^
//int ExcelLoader::GetIntValue(const std::string& sheet_name, const std::string& tag)
//{
//    std::string value = GetStringValue(sheet_name, tag + "_int");
//    if (!value.empty())
//    {
//        return std::stoi(value);
//    }
//    throw std::runtime_error("Value not found or cannot be converted to int");
//}
//
////float�^
//float ExcelLoader::GetFloatValue(const std::string& sheet_name, const std::string& tag)
//{
//    std::string value = GetStringValue(sheet_name, tag + "_float");
//    if (!value.empty())
//    {
//        return std::stof(value);
//    }
//    throw std::runtime_error("Value not found or cannot be converted to float");
//}
//
////string�^
//std::string ExcelLoader::GetString(const std::string& sheet_name, const std::string& tag)
//{
//    return GetStringValue(sheet_name, tag + "_string");
//}
