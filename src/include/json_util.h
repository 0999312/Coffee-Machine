/*
 * json_util.h
 *
 *  Created on: 2022年1月27日
 *      Author: 政
 */

#ifndef INCLUDE_JSON_UTIL_H_
#define INCLUDE_JSON_UTIL_H_

#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include "rapidjson/prettywriter.h" // RapidJson Json格式化输出
#include "rapidjson/stringbuffer.h" // RapidJson 字符串Buffer
#include "rapidjson/document.h" // RapidJson DOM支持
#include "rapidjson/istreamwrapper.h" // RapidJson 封装流
#include "structs.h" // 自己的结构体头文件

void write_map_to_writer(
    rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer,
    std::map<std::string, int> &map) {
  std::map<std::string, int>::iterator iter = map.begin();
  while (iter != map.end()) {
    writer.Key(iter->first.c_str());
    writer.Int(iter->second);
    iter++;
  }
}

bool read_map_from_json(rapidjson::Value &object,
			std::map<std::string, int> &map) {
  if (!object.IsObject())
    return false;
  for (rapidjson::Value::ConstMemberIterator it = object.MemberBegin();
      it != object.MemberEnd(); it++) {
    map.insert(std::make_pair(it->name.GetString(), it->value.GetInt()));
  }
  return true;
}

void gen_additives_to_writer(
    rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer,
    coffee_additives &adds) {
  writer.Key("coffee_additives");
  writer.StartObject();
  writer.Key("milk");
  writer.StartObject();
  write_map_to_writer(writer, adds.milk);
  writer.EndObject();
  writer.Key("syrup");
  writer.StartObject();
  write_map_to_writer(writer, adds.syrup);
  writer.EndObject();
  writer.Key("sweeter");
  writer.StartObject();
  write_map_to_writer(writer, adds.sweeter);
  writer.EndObject();
  writer.Key("alcohol");
  writer.StartObject();
  write_map_to_writer(writer, adds.alcohol);
  writer.EndObject();
  writer.Key("others");
  writer.StartObject();
  write_map_to_writer(writer, adds.others);
  writer.EndObject();
  writer.EndObject();
}

bool read_additives_from_json(rapidjson::Value &object, coffee_additives &adds) {
  if (!object.IsObject())
    return false;
  read_map_from_json(object["milk"], adds.milk);
  read_map_from_json(object["syrup"], adds.syrup);
  read_map_from_json(object["sweeter"], adds.sweeter);
  read_map_from_json(object["alcohol"], adds.alcohol);
  read_map_from_json(object["others"], adds.others);
  return true;
}

std::string gen_ingredient_string() {
  rapidjson::StringBuffer s;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
  writer.StartObject();
  writer.Key("water");
  writer.Int(machine_ingredients.water);
  writer.Key("coffee_bean");
  writer.Int(machine_ingredients.coffeeBean);
  gen_additives_to_writer(writer, machine_ingredients.additives);
  writer.EndObject();
  return s.GetString();
}

bool read_ingredient_json(std::ifstream &file) {
  rapidjson::Document doc;
  rapidjson::IStreamWrapper isw { file };
  doc.ParseStream(isw);
  if (doc.HasParseError()) {
    std::cout << "JSON Error  : " << doc.GetParseError() << std::endl << "Offset : " << doc.GetErrorOffset() << std::endl;
    return false;
  }
  rapidjson::Value::ConstMemberIterator iter = doc.FindMember("water");
  if(iter!=doc.MemberEnd()&&iter->value.IsInt())
    machine_ingredients.water = iter->value.GetInt();
  else{
    std::cout << "JSON Error in reading water;";
    return false;
  }
  iter = doc.FindMember("coffee_bean");
  if(iter!=doc.MemberEnd()&&iter->value.IsInt())
    machine_ingredients.coffeeBean = doc["coffee_bean"].GetInt();
  else{
    std::cout << "JSON Error in reading coffee bean;";
    return false;
  }
  read_additives_from_json(doc["coffee_additives"], machine_ingredients.additives);
  return true;
}

#endif /* INCLUDE_JSON_UTIL_H_ */
