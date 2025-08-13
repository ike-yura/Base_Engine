//#pragma once
//
//#include <xlnt.hpp>
//#include <string>
//#include <unordered_map>
//
//class ExcelLoader {
//public:
//    static void LoadExcelFile(const std::string& file_path);
//    static std::string GetStringValue(const std::string& sheet_name, const std::string& tag);
//    static int GetIntValue(const std::string& sheet_name, const std::string& tag);
//    static float GetFloatValue(const std::string& sheet_name, const std::string& tag);
//    static std::string GetString(const std::string& sheet_name, const std::string& tag);
//private:
//    static xlnt::workbook workbook;
//    static std::unordered_map<std::string, std::unordered_map<std::string, std::string>> tag_values;
//
//    static void ParseSheet(const xlnt::worksheet& ws);
//};
