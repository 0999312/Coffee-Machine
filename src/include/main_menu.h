#ifndef INCLUDE_MAINMENU_H_
#define INCLUDE_MAINMENU_H_
/*
 * 头文件保护, IDE自带。
 * #ifndef表示如果未定义头文件则进行一次定义。
 * 这个写法来自于C，而且C++也需要使用这种方法。
 */
#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include "structs.h" // 自己的结构体头文件
#include "functions.h" // 自己的函数头文件
#include "menu_list.h" // 子菜单函数头文件

//主菜单
void main_menu() {

  int button;
  while (true) {
    system_status(); //原来的状态输出改为函数移到了functions.h文件中
    std::printf("咖啡豆剩余量：%d\n", machine_ingredients.coffeeBean);
    std::printf("水剩余量：%d\n", machine_ingredients.water);
    std::cout<<"本次运行已制作的咖啡数量："<<coffee_count<<" 杯。"<<std::endl;
    print_line();
    std::printf("[0] 原料管理 [1] 菜单管理 [2] 新增订单 [3]统计功能 [4] 初始化咖啡机 [-1] 结束程序\n");
    std::cin >> button;
    if (button == -1){
      std::ofstream menusFile;
      menusFile.open("drinks_menu.json", std::ios::out | std::ios::trunc);
      menusFile << gen_machine_menu_string();
      menusFile.close();
      // 我不想一故障的时候就把原料的JSON给清空了！——政
      std::ofstream ingredientsFile;
      ingredientsFile.open("ingredients.json", std::ios::out | std::ios::trunc);
      ingredientsFile << gen_ingredient_string();
      ingredientsFile.close();
      break;
    }
    switch (button) {
      case 0:
	ingredient_management();
	break;
      case 1:
	menu_management();
	break;
      case 2:
	add_order();
	break;
      case 3:
	stat_menu();
	break;
      case 4:
	create_new_ingredients();
	break;
      default:
	std::printf("输入错误,请重新输入：\n");
	break;
    }
  }

}

#endif /* INCLUDE_MAINMENU_H_ */
