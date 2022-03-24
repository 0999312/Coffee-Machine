/*
 * map_util.h
 * Map的函数工具类
 *  Created on: 2022年3月23日
 *      Author: mr099
 */

#ifndef INCLUDE_MAP_UTIL_H_
#define INCLUDE_MAP_UTIL_H_

#include <vector> // C++ Vector（可变数组）库
#include <string> // C++ 字符串库
#include <map> // C++ Map数据类型库
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <algorithm> // C++算法库

#include "structs.h" // 自己的结构体头文件
#include "json_util.h" // 自己的Json工具头文件

std::vector<std::pair<std::string, int>> sortedMap(std::map<std::string, int> &map){
  std::vector<std::pair<std::string, int>> arr;
  for (const auto &item : map)
      arr.emplace_back(item);
  std::sort(arr.begin(), arr.end(), [] (const auto &x, const auto &y) {return x.second < y.second;});
  return arr;
}

//std::cout << "\t\t名称：" << it->first << "，含量：" << it->second << std::endl;
void print_map(std::map<std::string, int> &map){
  if(map.size()<=0){
      std::cout << "\t\t空空如也。" << std::endl;
      return ;
  }
  std::map<std::string, int>::iterator it;
  for (it = map.begin(); it != map.end(); it++) {
      std::cout << "\t\t名称：" << it->first << "，含量：" << it->second <<" g"<< std::endl;
  }
}

void print_map_keys(std::map<std::string, int> &map){
  if(map.size()<=0){
      std::cout << "空空如也。" << std::endl;
      return ;
  }
  std::map<std::string, int>::iterator it;
  for (it = map.begin(); it != map.end(); it++) {
      std::cout << it->first<< std::endl;
  }
}

void print_sorted_map(std::map<std::string, int> &map){
  if(map.size()<=0){
        std::cout << "\t\t空空如也。" << std::endl;
        return ;
  }
  std::vector<std::pair<std::string, int>> sorted_map = sortedMap(map);
  for (const auto i : sorted_map) {
      std::cout << "\t\t名称：" << i.first << "，含量：" << i.second <<" g"<< std::endl;
  }
}

#endif /* INCLUDE_MAP_UTIL_H_ */
