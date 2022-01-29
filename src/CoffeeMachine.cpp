#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <list> //C++ STL实现 双向链表（我们甚至不需要自己写链表了，YES）
#include <fstream> //C++ 文件输入输出流
#include "include/structs.h" // 自己的结构体头文件
#include "include/functions.h" // 自己的函数头文件
#include "include/main_menu.h" // 主菜单头文件
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
  //使用UTF-8编码，好像是Windows的老毛病
#ifdef _WIN32
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);
#endif

  if (!read_ingredients()) {
    std::cout << "检测到原料文件异常，进行初始化工作。" << std::endl;
    press_any_button();
    std::fstream ingredientsFile;
    ingredientsFile.open("ingredients.txt", std::ios::out | std::ios::trunc);
    create_new_ingredients();
    ingredientsFile.close();
  }
  if (!read_machine_menus()) {
    std::cout << "检测到预设菜单异常！" << std::endl;
    press_any_button();
  }
  /*
   else{
   std::cout<<"已初始化成功。"<<std::endl;
   press_any_button();
   }
   */
  print_machine_ingredients_file();

  // 主菜单
  main_menu();
  return EXIT_SUCCESS;
}
