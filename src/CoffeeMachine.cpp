#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <list> //C++ STL实现 双向链表（我们甚至不需要自己写链表了，YES）
#include "include/structs.h" // 自己的结构体头文件

int main() {
  // 咖啡机内菜单
  std::list<coffee_menu> machine_menus;
  // 测试程序，输出两个牛奶的量。
  // 咖啡机内原料"include/structs.h"里面了。

  machine_ingredients.additives.add_milk("milk", 1000);
  std::cout << "milk:" << machine_ingredients.additives.get_milk("milk") << std::endl;
  std::cout << "soymilk:" << machine_ingredients.additives.get_milk("soymilk") << std::endl;

  return 0;
}
