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
#include <sstream> //C++ 字符串流
#include <cstdlib> //C语言的stdlib，用C++调用时候建议使用<c***>（***代表原来的头文件名称）
#include <iterator>// C++迭代器库
#include <vector> // C++ Vector（可变数组）库
#include <algorithm> // C++算法库
#include <ctime>// C语言 时间
#include "structs.h" // 自己的结构体头文件
#include "json_util.h" // 自己的Json工具头文件
#include "map_util.h" // 自己的Map工具头文件
int coffee_count = 0;

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
  /*
   #ifdef _WIN32
   std::system("cls");
   #else
   // Assume POSIX
   std::system("clear");
   #endif
   */
}

//因为没有了清屏函数，这一步就显得没有必要，注释以提升操作流畅度
void press_any_button() {
  /*
  print_line();
  std::cout << "按确定键(Enter)继续。" << std::endl;
  std::cin.clear();
  while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
    continue;
  */
}

//前面那个按任意键函数在菜单界面会跳过按键继续，这个加了一个获取字符
void press_any_button_1() {
  /*
  print_line();
  std::cout << "按确定键(Enter)继续。" << std::endl;
  std::cin.clear();
  std::cin.get();
  while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
    continue;
  */
}

std::string time_string_now() {
  std::time_t now = std::time(nullptr);
  std::tm *ltm = std::localtime(&now);

  return std::to_string(ltm->tm_year + 1900) + '_'
      + std::to_string(ltm->tm_mon + 1) + '_' + std::to_string(ltm->tm_mday)
      + '_' + std::to_string(ltm->tm_hour) + '_' + std::to_string(ltm->tm_min)
      + '_' + std::to_string(ltm->tm_sec);
}

//系统状态输出函数
void system_status() {
  clear_screen();
  std::time_t now = std::time(nullptr);
  std::tm *ltm = std::localtime(&now);
  std::printf("咖啡机模拟系统 当前版本:v1.1 当前时间:  ");
  std::printf("%04d年%02d月%02d日  ", ltm->tm_year + 1900, ltm->tm_mon + 1,
	      ltm->tm_mday);
  std::printf("%02d时%02d分%02d秒\n", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  print_line();
}

//输入用函数
void input_value(int &value) {
  while (!(std::cin >> value)) {
    std::cout << "\033[31m输入错误,请重新输入：\033[0m" << std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
}

//输入用函数
int input_int_value() {
  int value;
  while (!(std::cin >> value)) {
    std::cout << "\033[31m输入错误,请重新输入：\033[0m" << std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
  return value;
}

//输入bool用函数
bool input_bool() {
  char value;
  std::cout << "是(Y) / 否(N)" << std::endl;
  while (!(std::cin >> value)
      || (value != 'Y' && value != 'N' && value != 'y' && value != 'n')) {
    std::cout << "\033[31m输入错误,请重新输入一个有效的字符。\033[0m" << std::endl;
    std::cout << "是(Y) / 否(N)" << std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
  return value == 'Y' || value == 'y' ? true : false;
}

//输入奶制品
void input_milk(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = true;
  do {
    print_map_keys(new_additives.milk);
    print_line();
    std::cout << "请命名您想要添加的奶制品。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的数量（注意：数量单位为克）。" << std::endl;
    input_value(amount);
    std::cout << "您确定添加这个奶制品吗？" << std::endl;
    if(!input_bool()) continue;
    new_additives.add_milk(name, amount);
    std::cout << "您还需要继续添加其他奶制品吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//输入糖浆
void input_syrup(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = true;
  do {
    print_map_keys(new_additives.syrup);
    print_line();
    std::cout << "请命名您想要添加的糖浆。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的数量（注意：数量单位为克）。" << std::endl;
    input_value(amount);
    std::cout << "您确定添加这个糖浆吗？" << std::endl;
    if(!input_bool()) continue;
    new_additives.add_syrup(name, amount);
    std::cout << "您还需要继续添加其他糖浆吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//输入甜味剂
void input_sweeter(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = true;
  do {
    print_map_keys(new_additives.sweeter);
    print_line();
    std::cout << "请命名您想要添加的甜味剂。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的数量（注意：数量单位为克）。" << std::endl;
    input_value(amount);
    std::cout << "您确定添加这个甜味剂吗？" << std::endl;
    if(!input_bool()) continue;
    new_additives.add_sweeter(name, amount);
    std::cout << "您还需要继续添加其他甜味剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//输入酒类
void input_alcohol(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = true;
  do {
    print_map_keys(new_additives.alcohol);
    print_line();
    std::cout << "请命名您想要添加的酒类名称。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的数量（注意：数量单位为克）。" << std::endl;
    input_value(amount);
    std::cout << "您确定添加这个酒类吗？" << std::endl;
    if(!input_bool()) continue;
    new_additives.add_alcohol(name, amount);
    std::cout << "您还需要继续添加其他酒类吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//输入其他添加剂
void input_other_ingredient(coffee_additives &new_additives) {
  std::string name;
  int amount;
  bool flag = true;
  do {
    print_map_keys(new_additives.others);
    print_line();
    std::cout << "请命名您想要添加的其他类型的添加剂。" << std::endl;
    std::cin >> name;
    std::cout << "请输入您想要添加的数量（注意：数量单位为克）。" << std::endl;
    input_value(amount);
    std::cout << "您确定添加这个添加剂吗？" << std::endl;
    if(!input_bool()) continue;
    new_additives.add_other_ingredient(name, amount);
    std::cout << "您还需要继续添加其他添加剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

bool delete_menu(std::string &menu_name) {
  for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
    if (i->name == menu_name) {
      machine_menus.erase(i);
      return true;
    }
  }
  std::string num = menu_name;
  std::stringstream ss(num);
  unsigned int n = 0;
  ss >> n;
  if (n != 0 && n <= machine_menus.size()) {
    auto menu = machine_menus.begin();
    std::advance(menu, (n - 1));
    machine_menus.erase(menu);
    return true;
  }
  return false;
}

coffee_menu& find_menu(std::string &menu_name) {
  for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
    if (i->name == menu_name)
      return *i;
  }
  std::string num = menu_name;
  std::stringstream ss(num);
  unsigned int n = 0;
  ss >> n;
  if (n != 0 && n <= machine_menus.size()) {
    auto menu = machine_menus.begin();
    std::advance(menu, (n - 1));
    return *(menu);
  }
  return null_menu;
}

//删除奶制品
void delete_milk(coffee_additives &new_additives) {
  std::string name;
  bool flag = false;
  do {
    print_map_keys(new_additives.milk);
    print_line();
    std::cout << "请输入您想要删除的奶制品名称（请注意大小写）。" << std::endl;
    std::cin >> name;
    if (!new_additives.delete_milk(name))
      std::cout << "\033[31m移除失败，不存在该奶制品。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他奶制品吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//删除糖浆
void delete_syrup(coffee_additives &new_additives) {
  std::string name;
  bool flag = false;
  do {
    print_map_keys(new_additives.syrup);
    print_line();
    std::cout << "请输入您想要删除的糖浆名称（请注意大小写）。" << std::endl;
    std::cin >> name;
    if (!new_additives.delete_syrup(name))
      std::cout << "\033[31m移除失败，不存在该糖浆。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他糖浆吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//删除甜味剂
void delete_sweeter(coffee_additives &new_additives) {
  std::string name;
  bool flag = false;
  do {
    print_map_keys(new_additives.sweeter);
    print_line();
    std::cout << "请输入您想要删除的甜味剂名称（请注意大小写）。" << std::endl;
    std::cin >> name;
    if (!new_additives.delete_sweeter(name))
      std::cout << "\033[31m移除失败，不存在该甜味剂。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他甜味剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//删除酒类
void delete_alcohol(coffee_additives &new_additives) {
  std::string name;
  bool flag = false;
  do {
    print_map_keys(new_additives.alcohol);
    print_line();
    std::cout << "请输入您想要删除的酒类名称（请注意大小写）。" << std::endl;
    std::cin >> name;
    if (!new_additives.delete_alcohol(name))
      std::cout << "\033[31m移除失败，不存在该酒类。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他酒类吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//删除其他添加剂
void delete_other_ingredient(coffee_additives &new_additives) {
  std::string name;
  bool flag = false;
  do {
    print_map_keys(new_additives.others);
    print_line();
    std::cout << "请输入您想要删除的添加剂名称（请注意大小写）。" << std::endl;
    std::cin >> name;
    if (!new_additives.delete_other_ingredient(name))
      std::cout << "\033[31m移除失败，不存在该添加剂。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他添加剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

void setting_additives(coffee_additives &new_additives) {
  int button;
  while (true) {
    print_line();
    std::cout << "-------------------设置咖啡添加剂-------------------" << std::endl;
    std::printf("    [ 1] - 奶制品\n    [ 2] - 糖浆\n    [ 3] - 甜味剂\n    [ 4] - 酒\n    [ 5] - 其他原料\n    [ 9] - 结束设置\n");
    //添加了单位的说明，避免单位不清楚，将原本的“质量”改成了“重量”，避免歧义，原来的质量有品质的歧义
    std::cout << "温馨提示：所有的数据均以重量（单位：克）来进行计算。" << std::endl;
    std::cout << "数值对应为原料的重量，即当前有多少克原料。" << std::endl;
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
      input_milk(new_additives);
      break;
      case 2:
      input_syrup(new_additives);
      break;
      case 3:
      input_sweeter(new_additives);
      break;
      case 4:
      input_alcohol(new_additives);
      break;
      case 5:
      input_other_ingredient(new_additives);
      break;
      default:
      std::printf("\033[31m输入错误,请重新输入选项对应的数字：\n\033[0m");
      break;
    }
    press_any_button_1();
  }
}

coffee_additives create_new_coffee_additives() {
  coffee_additives new_additives;
  setting_additives(new_additives);
  return new_additives;
}

//创建新的原料
void create_new_ingredients() {
  bool flag = false;
  do {
    clear_screen();
    print_line();
    std::cout << "开始进行咖啡机原料的初始化工作。" << std::endl;
    std::cout << "请根据操作提示进行初始化。" << std::endl;
    press_any_button();
    print_line();
    std::cout << "温馨提示：所有的数据均按照重量（单位：克）来进行计算。" << std::endl;
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
  std::cout << "咖啡机原料初始化完成。" << std::endl;
}

//是否有原料，如果没有原料则理应执行新建原料流程。
bool read_ingredients() {
  std::ifstream ingredientsFile;
  ingredientsFile.open("ingredients.json", std::ios::in);
  if (!ingredientsFile.is_open())
    return false;
  bool flag = read_ingredient_json(ingredientsFile);
  ingredientsFile.close();
  return flag;
}

//是否有预设菜单，如果没有则不执行任何行为。
bool read_machine_menus() {
  std::ifstream menusFile;
  menusFile.open("drinks_menu.json", std::ios::in);
  if (!menusFile.is_open())
    return false;
  bool flag = read_machine_menu(menusFile);
  menusFile.close();
  return flag;
}
//未排序的Map输出。
void print_coffee_additives(coffee_additives &additives) {
  print_line();
  std::cout << "咖啡添加剂：" << std::endl;
  std::cout << "\t奶制品：" << std::endl;
  print_map(additives.milk);
  std::cout << "\t糖浆：" << std::endl;
  print_map(additives.syrup);
  std::cout << "\t甜味剂：" << std::endl;
  print_map(additives.sweeter);
  std::cout << "\t酒类：" << std::endl;
  print_map(additives.alcohol);
  std::cout << "\t其他添加剂：" << std::endl;
  print_map(additives.others);
  print_line();
}
//按照数值排序的输出。
void print_sorted_coffee_additives(coffee_additives &additives) {
  print_line();
  std::cout << "咖啡添加剂：" << std::endl;
  std::cout << "\t奶制品：" << std::endl;
  print_sorted_map(additives.milk);
  std::cout << "\t糖浆：" << std::endl;
  print_sorted_map(additives.syrup);
  std::cout << "\t甜味剂：" << std::endl;
  print_sorted_map(additives.sweeter);
  std::cout << "\t酒类：" << std::endl;
  print_sorted_map(additives.alcohol);
  std::cout << "\t其他添加剂：" << std::endl;
  print_sorted_map(additives.others);
  print_line();
}

//制作咖啡，消耗原料。
bool brew_coffee(coffee_menu &menu) {
  bool flag_base, flag_additives;
  if (menu.type) {
    flag_base = machine_ingredients.use_water(menu.amount * 40)
	&& machine_ingredients.use_coffee_bean(menu.amount * 40);
  }
  else {
    flag_base = machine_ingredients.use_water(menu.amount * 15)
	&& machine_ingredients.use_coffee_bean(menu.amount);
  }
  if (!flag_base)
    std::cout << "\033[33m制作咖啡基底时出现材料短缺错误！\033[0m" << std::endl;
  flag_additives = machine_ingredients.additives.use_additives(menu.additives);
  if (!flag_base)
    std::cout << "\033[33m添加添加剂时出现材料短缺错误！\033[0m" << std::endl;
  return flag_base && flag_additives;
}

//输出原料信息到终端
void print_machine_ingredients() {
  print_line();
  std::cout << "水量：" << machine_ingredients.water << std::endl;
  std::cout << "咖啡豆：" << machine_ingredients.coffeeBean << std::endl;
  print_coffee_additives(machine_ingredients.additives);
}

//输出原料信息到终端
void print_coffee_menu(coffee_menu &menu) {
  std::cout << "咖啡名：" << menu.name << std::endl;
  std::cout << "咖啡基底：" << (menu.type ? "意式浓缩" : "美式滴滤") << std::endl;
  std::cout << "咖啡量：" << menu.amount << std::endl;
  print_coffee_additives(menu.additives);
}

//输出统计到终端
void print_machine_stats() {
  print_line();
  std::cout << "使用咖啡基底的情况：" << std::endl;
  std::cout << "\t美式滴滤基底：" << machine_stat.drip << std::endl;
  std::cout << "\t意式浓缩基底：" << machine_stat.espresso << std::endl;
  print_sorted_coffee_additives(machine_stat.additives);
}

void print_coffee_additives_files(std::fstream &ingredientsFile,
				  coffee_additives &additives) {
  std::map<std::string, int>::iterator it; //定义map迭代器，用于遍历map。
  print_line(ingredientsFile);
  ingredientsFile << "咖啡添加剂：" << std::endl;
  ingredientsFile << "\t奶制品：" << std::endl;
  for (it = additives.milk.begin(); it != additives.milk.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t糖浆：" << std::endl;
  for (it = additives.syrup.begin(); it != additives.syrup.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t甜味剂：" << std::endl;
  for (it = additives.sweeter.begin(); it != additives.sweeter.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t酒类：" << std::endl;
  for (it = additives.alcohol.begin(); it != additives.alcohol.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  ingredientsFile << "\t其他添加剂：" << std::endl;
  for (it = additives.others.begin(); it != additives.others.end(); it++) {
    ingredientsFile << "\t\t名称：" << it->first << "，含量：" << it->second
	<< std::endl;
  }
  print_line(ingredientsFile);
}

coffee_menu setting_coffee_menu(coffee_menu &new_menu) {
  std::cout << "请选择基底咖啡的类型。" << std::endl << "注意：0为美式滴滤，1为意式浓缩。" << std::endl;
  new_menu.type = (input_int_value() == 1) ? true : false;
  std::cout << (new_menu.type ? "请输入浓缩咖啡的份量。" : "请输入美式滴滤的咖啡使用量。") << std::endl;
  input_value(new_menu.amount);
  std::cout << "您需要其他的添加剂吗？" << std::endl;
  bool flag = input_bool();
  if (flag) {
    setting_additives(new_menu.additives);
  }
  return new_menu;
}

void add_new_coffee_menu() {
  coffee_menu new_menu;
  bool flag;
  do {
    std::cout << "请输入新菜单的名字。" << std::endl;
    std::cin >> new_menu.name;
    setting_coffee_menu(new_menu);
    std::cout << "您确定使用这个菜单了吗？" << std::endl;
    flag = input_bool();
  }
  while (!flag);
  machine_menus.push_back(new_menu);
}

void finish_coffee_order(coffee_menu &order) {
  coffee_count++;
  if (order.type)
    machine_stat.espresso++;
  else
    machine_stat.drip++;

  std::map<std::string, int>::iterator it; //定义map迭代器，用于遍历map。
  for (it = order.additives.milk.begin(); it != order.additives.milk.end();
      it++) {
    machine_stat.additives.add_milk(it->first, it->second);
  }
  for (it = order.additives.syrup.begin(); it != order.additives.syrup.end();
      it++) {
    machine_stat.additives.add_syrup(it->first, it->second);
  }
  for (it = order.additives.sweeter.begin();
      it != order.additives.sweeter.end(); it++) {
    machine_stat.additives.add_sweeter(it->first, it->second);
  }
  for (it = order.additives.alcohol.begin();
      it != order.additives.alcohol.end(); it++) {
    machine_stat.additives.add_alcohol(it->first, it->second);
  }
  for (it = order.additives.others.begin(); it != order.additives.others.end();
      it++) {
    machine_stat.additives.add_other_ingredient(it->first, it->second);
  }
}

void add_custom_order() {
  coffee_menu custom_menu;
  bool flag;
  do {
    custom_menu.name = "CustomOrder:" + time_string_now();
    setting_coffee_menu(custom_menu);
    std::cout << "您确定使用这个菜单了吗？" << std::endl;
    flag = input_bool();
  }
  while (!flag);
  if (brew_coffee(custom_menu)) {
    completed_menus.push_back(custom_menu);
    std::cout << "订单完成！\n请等待咖啡制作完成后再取出咖啡杯 \n欢迎下次光临!" << std::endl;
    finish_coffee_order(custom_menu);
  }
  else {
    std::cout << "\033[33m很抱歉，订单制作失败! \n请等材料补充完毕后再进行购买。\033[0m" << std::endl;
  }
}

void add_preset_order() {
  int num = 1;
  std::string menu_name;
  for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
    std::cout << num << '.' << i->name << std::endl;
    num++;
  }
  bool flag;
  coffee_menu order_menu;
  do {
    std::cout << "请输入您想要购买的菜单名。" << std::endl;
    std::cin >> menu_name;
    order_menu = find_menu(menu_name);
    if (order_menu == null_menu) {
        std::cout << "\033[31m不存在该菜单，返回上一级。\033[0m" << std::endl;
        return ;
    }
    std::cout << "您确定使用这个菜单了吗？" << std::endl;
    flag = input_bool();
  }
  while (!flag);
  order_menu.name = order_menu.name + ':' + time_string_now();
  if (brew_coffee(order_menu)) {
    completed_menus.push_back(order_menu);
    std::cout << "订单完成！\n请等待咖啡制作完成后再取出咖啡杯 \n欢迎下次光临!" << std::endl;
    finish_coffee_order(order_menu);
  }
  else {
    std::cout << "\033[33m很抱歉，订单制作失败! \n请等材料补充完毕后再进行购买。\033[0m" << std::endl;
  }
}

#endif /* INCLUDE_FUNCTIONS_H_ */
