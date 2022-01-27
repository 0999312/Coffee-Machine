/*
 * 请把经常需要调用的函数（除structs.h里面封装好的增删改查之外）写在这个头文件里。
 */
#ifndef INCLUDE_FUNCTIONS_H_
#define INCLUDE_FUNCTIONS_H_
/*
 * 头文件保护, IDE自带。
 * #ifndef表示如果未定义头文件则进行一次定义。
 * 这个写法来自于C，而且C++也需要使用这种方法。
 */
#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <list> //C++ STL实现 双向链表（我们甚至不需要自己写链表了，YES）
#include <fstream> //C++ 文件输入输出流
#include <sstream> //C++ 字符串流
#include <cstdlib> //C语言的stdlib，用C++调用时候建议使用<c***>（***代表原来的头文件名称）
#include <iterator>
#include <algorithm> // C++算法库
#include "structs.h" // 自己的结构体头文件
#include <ctime>// C语言 时间

//输出一个80字符的分隔线
//80字符的标准不过分吧？这可是最适合打印的长度标准！
void print_line() {
  for (int i = 0; i < 80; i++)
    std::cout << '-';
  std::cout << std::endl;
}
//这是给文件的版本
void print_line(std::fstream &outFile) {
  for (int i = 0; i < 80; i++)
    outFile << '-';
  outFile << std::endl;
}

/**
 * 来自网上的清屏代码，这里有一个分系统的写法。
 * 如果是Windows就直接cls，否则clear。
 * 某种意义来说好像本来就是很不安全的写法？
 */
void clear_screen() {
#ifdef _WIN32
  std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
  #endif
}

void press_any_button() {
  print_line();
  std::cout << "按任意键继续。" << std::endl;
  std::cin.clear();
  while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
    continue;
  std::cin.get();
}

//系统状态输出函数
void system_status() {
  clear_screen();
  std::time_t now = std::time(nullptr);
  std::tm *ltm = std::localtime(&now);
  std::printf("咖啡机模拟系统 当前版本:v1.0 当前时间:  ");
  std::printf("%04d年%02d月%02d日  ", ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);
  std::printf("%02d时%02d分%02d秒\n", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  print_line();
}

//输入用函数
void input_value(int &value) {
  while (!(std::cin >> value)) {
    std::cout << "输入错误，请重新输入。" << std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
}
//输入bool用函数
bool input_bool() {
  bool value;
  std::cout << "请输入true或者false。" << std::endl;
  while (!(std::cin >> std::boolalpha >> value)) {
    std::cout << "输入错误，请重新输入。" << std::endl;
    std::cout << "请输入true或者false。" << std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
  return value;
}

void setting_additives(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = false;
  print_line();
  do {
    std::cout << "请输入您想要添加的奶制品名称。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的库存量。" << std::endl;
    input_value(amount);
    new_additives.add_milk(name, amount);
    std::cout << "您还需要继续添加奶制品吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  do {
    std::cout << "请输入您想要添加的糖浆名称。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的库存量。" << std::endl;
    input_value(amount);
    new_additives.add_syrup(name, amount);
    std::cout << "您还需要继续添加糖浆吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  do {
    std::cout << "请输入您想要添加的甜味剂名称。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的库存量。" << std::endl;
    input_value(amount);
    new_additives.add_sweeter(name, amount);
    std::cout << "您还需要继续添加甜味剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  do {
    std::cout << "请输入您想要添加的酒类名称。" << std::endl;
    std::cin >> name;
    std::cout << "请输入当前库存量。" << std::endl;
    input_value(amount);
    new_additives.add_alcohol(name, amount);
    std::cout << "您还需要继续添加酒吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  do {
    std::cout << "请输入您想要添加的其他添加剂。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的库存量。" << std::endl;
    input_value(amount);
    new_additives.add_other_ingredient(name, amount);
    std::cout << "您还需要继续添加其他添加剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  std::cout << "添加剂设置完成" << std::endl;
}

coffee_additives create_new_coffee_additives() {
  coffee_additives new_additives;
  setting_additives(new_additives);
  return new_additives;
}

void write_map(std::map<std::string, int> &map,
	      std::ofstream &ingredientsFile) {
  std::map<std::string, int>::iterator iter = map.begin();
  size_t size= (iter->first).size();
  while (iter != map.end()) {
    ingredientsFile.write((char*) (&size), sizeof(size));
    ingredientsFile.write((char*) (iter->first.c_str()), size);
    ingredientsFile.write((char*) (&iter->second), sizeof(int));
    iter++;
  }
}

//创建新的原料
void create_new_ingredients() {
  std::ofstream ingredientsFile;
  ingredientsFile.open("ingredients.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  bool flag = false;
  do {
    clear_screen();
    print_line();
    std::cout << "进行咖啡机原料初始化工作。" << std::endl;
    std::cout << "请根据操作提示进行初始化。" << std::endl;
    press_any_button();
    print_line();
    std::cout << "请注意，所有的数据均按照质量计算。" << std::endl;
    std::cout << "数值对应为原料的克数，即当前有多少克原料。" << std::endl;
    print_line();
    std::cout << "请输入咖啡机内当前的水量。" << std::endl;
    input_value(machine_ingredients.water);
    std::cout << "请输入咖啡机内当前的咖啡豆数量。" << std::endl;
    input_value(machine_ingredients.coffeeBean);
    print_line();
    std::cout << "开始输入咖啡机内其余的添加剂内容物。" << std::endl;
    press_any_button();
    machine_ingredients.additives = create_new_coffee_additives();
    std::cout << "您需要重新设置咖啡机吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  ingredientsFile.write((char*)&machine_ingredients.water,sizeof(int));
  ingredientsFile.write((char*)&machine_ingredients.coffeeBean,sizeof(int));
  ingredientsFile.close();
  ingredientsFile.open("additives_milk.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  write_map(machine_ingredients.additives.milk, ingredientsFile);
  ingredientsFile.close();
  ingredientsFile.open("additives_syrup.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  write_map(machine_ingredients.additives.syrup, ingredientsFile);
  ingredientsFile.close();
  ingredientsFile.open("additives_sweeter.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  write_map(machine_ingredients.additives.sweeter, ingredientsFile);
  ingredientsFile.close();
  ingredientsFile.open("additives_alcohol.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  write_map(machine_ingredients.additives.alcohol, ingredientsFile);
  ingredientsFile.close();
  ingredientsFile.open("additives_others.dat",
		       std::ios::binary | std::ios::out | std::ios::trunc);
  write_map(machine_ingredients.additives.others, ingredientsFile);
  ingredientsFile.close();
  std::cout << "咖啡机原料初始化完成。" << std::endl;
}

//是否有原料，如果没有原料则理应执行新建原料流程。
bool read_ingredients() {
  std::ifstream ingredientsFile;
  ingredientsFile.open("ingredients.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  ingredientsFile.read((char*)&machine_ingredients.water,sizeof(int));
  ingredientsFile.read((char*)&machine_ingredients.coffeeBean,sizeof(int));
  ingredientsFile.close();
  std::string name; int count;
  size_t size;
  ingredientsFile.open("additives_milk.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  while (!ingredientsFile.eof()) {
    ingredientsFile.read((char*)&size, sizeof(size_t));
    name.resize(size);
    ingredientsFile.read((char*)&name[0],size);
    ingredientsFile.read((char*)&count,sizeof(int));
    machine_ingredients.additives.set_milk(name, count);
  }
  ingredientsFile.close();
  ingredientsFile.open("additives_syrup.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  while (!ingredientsFile.eof()) {
    ingredientsFile.read((char*)&size, sizeof(size_t));
    name.resize(size);
    ingredientsFile.read((char*)&name[0],size);
    ingredientsFile.read((char*)&count,sizeof(int));
    machine_ingredients.additives.set_syrup(name, count);
  }
  ingredientsFile.close();
  ingredientsFile.open("additives_sweeter.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  while (!ingredientsFile.eof()) {
    ingredientsFile.read((char*)&size, sizeof(size_t));
    name.resize(size);
    ingredientsFile.read((char*)&name[0],size);
    ingredientsFile.read((char*)&count,sizeof(int));
    machine_ingredients.additives.set_sweeter(name, count);
  }
  ingredientsFile.close();
  ingredientsFile.open("additives_alcohol.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  while (!ingredientsFile.eof()) {
    ingredientsFile.read((char*)&size, sizeof(size_t));
    name.resize(size);
    ingredientsFile.read((char*)&name[0],size);
    ingredientsFile.read((char*)&count,sizeof(int));
    machine_ingredients.additives.set_alcohol(name, count);
  }
  ingredientsFile.close();
  ingredientsFile.open("additives_others.dat", std::ios::binary | std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  while (!ingredientsFile.eof()) {
    ingredientsFile.read((char*)&size, sizeof(size_t));
    name.resize(size);
    ingredientsFile.read((char*)&name[0],size);
    ingredientsFile.read((char*)&count,sizeof(int));
    machine_ingredients.additives.set_other_ingredient(name, count);
  }
  ingredientsFile.close();
  return true;
}

void print_machine_ingredients(std::fstream &ingredientsFile) {
  print_line(ingredientsFile);
  ingredientsFile << "水量：" << machine_ingredients.water << std::endl;
  ingredientsFile << "咖啡豆：" << machine_ingredients.coffeeBean << std::endl;
  std::map<std::string, int>::iterator it;		//定义map迭代器，用于遍历map。
  print_line(ingredientsFile);
  ingredientsFile << "咖啡添加剂：" << std::endl;
  ingredientsFile << "\t奶制品：" << std::endl;
  for (it = machine_ingredients.additives.milk.begin();
      it != machine_ingredients.additives.milk.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t糖浆：" << std::endl;
  for (it = machine_ingredients.additives.syrup.begin();
      it != machine_ingredients.additives.syrup.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t甜味剂：" << std::endl;
  for (it = machine_ingredients.additives.sweeter.begin();
      it != machine_ingredients.additives.sweeter.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t酒类：" << std::endl;
  for (it = machine_ingredients.additives.alcohol.begin();
      it != machine_ingredients.additives.alcohol.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t其他添加剂：" << std::endl;
  for (it = machine_ingredients.additives.others.begin();
      it != machine_ingredients.additives.others.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  print_line(ingredientsFile);
}

#endif /* INCLUDE_FUNCTIONS_H_ */
