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
#include <cstdlib> //C语言的stdlib，用C++调用时候建议使用<c***>（***代表原来的头文件名称）
#include "structs.h" // 自己的结构体头文件

//输出一个80字符的分隔线
//80字符的标准不过分吧？这可是最适合打印的长度标准！
void print_line(){
  for(int i = 0; i<80; i++)
    std::cout<<'-';
  std::cout<<std::endl;
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

void press_any_button(){
  print_line();
  std::cout<<"按任意键继续。"<<std::endl;
  while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
    continue;
}

//输入用函数
void input_value(int &value){
  while(!(std::cin >> value)){
    std::cout<<"输入错误，请重新输入。"<<std::endl;
    std::cin.clear();
    while (std::cin.get() != '\n')		//这里清空之前cin缓冲区的数据
      continue;
  }
}
//输入bool用函数
bool input_bool(){
  bool value;
  std::cout<<"请输入true或者false。"<<std::endl;
  while(!(std::cin >>std::boolalpha >> value)){
    std::cout<<"输入错误，请重新输入。"<<std::endl;
    std::cout<<"请输入true或者false。"<<std::endl;
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
    new_additives.add_alcohol(name, amount);
    std::cout << "您还需要继续添加其他添加剂吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
  print_line();
  std::cout << "添加剂设置完成" << std::endl;
}

coffee_additives create_new_coffee_additives(){
  coffee_additives new_additives;
  setting_additives(new_additives);
  return new_additives;
}

//创建新的原料
void create_new_ingredients() {
  std::fstream ingredientsFile;
  ingredientsFile.open("ingredients.dat", std::ios::binary | std::ios::out);
  coffee_ingredients new_ingredients;
  bool flag = false;
  do {
    clear_screen();
    print_line();
    std::cout<<"进行咖啡机原料初始化工作。"<<std::endl;
    std::cout<<"请根据操作提示进行初始化。"<<std::endl;
    press_any_button();
    print_line();
    std::cout<<"请注意，所有的数据均按照质量计算。"<<std::endl;
    std::cout<<"数值对应为原料的克数，即当前有多少克原料。"<<std::endl;
    print_line();
    std::cout<<"请输入咖啡机内当前的水量。"<<std::endl;
    input_value(new_ingredients.water);
    std::cout<<"请输入咖啡机内当前的咖啡豆数量。"<<std::endl;
    input_value(new_ingredients.coffeeBean);
    print_line();
    std::cout<<"开始输入咖啡机内其余的添加剂内容物。"<<std::endl;
    press_any_button();
    create_new_coffee_additives();
    std::cout << "您需要重新设置咖啡机吗？" << std::endl;
    flag = input_bool();
  } while (flag);
  ingredientsFile<<new_ingredients.water<<new_ingredients.coffeeBean;
  std::map<std::string, int>::iterator it;//定义map迭代器，用于遍历map。
  for(it=new_ingredients.additives.milk.begin();it!=new_ingredients.additives.milk.end();it++){
    ingredientsFile << it->first << it->second;
  }
  for(it=new_ingredients.additives.syrup.begin();it!=new_ingredients.additives.syrup.end();it++){
    ingredientsFile << it->first << it->second;
  }
  for(it=new_ingredients.additives.sweeter.begin();it!=new_ingredients.additives.sweeter.end();it++){
    ingredientsFile << it->first << it->second;
  }
  for(it=new_ingredients.additives.alcohol.begin();it!=new_ingredients.additives.alcohol.end();it++){
    ingredientsFile << it->first << it->second;
  }
  for(it=new_ingredients.additives.others.begin();it!=new_ingredients.additives.others.end();it++){
    ingredientsFile << it->first << it->second;
  }
  ingredientsFile.close();
  std::cout << "咖啡机原料初始化完成。" << std::endl;
}

//是否有原料，如果没有原料则理应执行新建原料流程。
bool has_ingredients() {
  std::fstream ingredientsFile;
  ingredientsFile.open("ingredients.dat", std::ios::binary | std::ios::in );
  return ingredientsFile.is_open();
}





#endif /* INCLUDE_FUNCTIONS_H_ */
