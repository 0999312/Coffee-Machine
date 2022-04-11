#ifndef INCLUDE_MAINLIST_H_
#define INCLUDE_MAINLIST_H_
/*
 * 头文件保护, IDE自带。
 * #ifndef表示如果未定义头文件则进行一次定义。
 * 这个写法来自于C，而且C++也需要使用这种方法。
 */
#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include "functions.h" // 自己的函数头文件
#include "structs.h" // 自己的结构体头文件

void ingredient_management();
void menu_management();
void add_order();
void stat_menu();

//主菜单
void main_menu() {
  int button;
  while (true) {
    system_status(); //原来的状态输出改为函数移到了functions.h文件中
    //老师说单位不清晰，添加了了大部分用单位计量的单位介绍
    std::printf("咖啡豆剩余量：%d g\n", machine_ingredients.coffeeBean);
    std::printf("水剩余量：%d g\n", machine_ingredients.water);
    std::cout<<"本次运行已制作的咖啡数量："<<coffee_count<<" 杯。"<<std::endl;
    print_line();
    std::printf("    [ 1] - 原料管理\n    [ 2] - 菜单管理\n    [ 3] - 新增订单\n    [ 4] - 统计功能\n    [ 5] - 初始化咖啡机\n    [ 0] - 结束程序\n");
    std::cin >> button;
    if (button == 0){
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
      case 1:
	      ingredient_management();
	      break;
      case 2:
	      menu_management();
	      break;
      case 3:
	      add_order();
      	break;
      case 4:
	      stat_menu();
	      break;
      case 5:
	      create_new_ingredients();
	      break;
      default:
      	std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m"); //老师可能会挑刺，改了。下面也都改了
      	break;
    }
  }
}

//子菜单，直接引用即可
//由于可能会有引用问题，下级子菜单放在上方

//------------------------------------------------------------------------
//三级子菜单

//新增订单
void add_order() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------新增订单-------------------\n");
    std::printf("    [ 1] - 选择菜单\n    [ 2] - 自定义菜单\n    [ 9] - 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
	      add_preset_order();
	      break;
      case 2:
	      add_custom_order();
	      break;
      default:
	      std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
	      break;
    }
    press_any_button_1();
  }
}

//打印预设菜单
void print_preset_menu() {
  system_status();
  for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
    print_line();
    print_coffee_menu(*i);
  }
  press_any_button_1();
}

//打印完成订单
void print_completed_menu() {
  system_status();
  for (auto i = completed_menus.begin(); i != completed_menus.end(); i++) {
    print_line();
    print_coffee_menu(*i);
  }
  press_any_button_1();
}

//打印完成订单
void print_stats() {
  system_status();
  print_machine_stats();
  press_any_button_1();
}

//新增订单
void stat_menu() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("------------------------统计功能------------------------\n");
    std::printf("    [ 1] - 打印预设菜单\n    [ 2] - 打印完成订单\n    [ 3] - 信息统计\n    [ 9] - 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {

      case 1:
      	print_preset_menu();
      	break;
      case 2:
      	print_completed_menu();
      	break;
      case 3:
      	print_stats();
      	break;
      default:
      	std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
      	press_any_button_1();
    }
  }
}

void delete_drink_menu() {
  std::string menu_name;
  bool flag = false;
  int num;
  do {
    num = 1;
    for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
      std::cout << num << '.' << i->name << std::endl;
      num++;
    }
    std::cout << "请输入您想要移除的菜单名称。" << std::endl;
    std::cin >> menu_name;
    if(delete_menu(menu_name))
      std::cout << "菜单移除成功。" << std::endl;
    else
      std::cout << "\033[31m菜单移除失败，不存在此菜单。\033[0m" << std::endl;
    std::cout << "您还需要继续删除其他菜单吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//添加其他原料子菜单
void add_other_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------其他原料-------------------\n");
    std::printf("    [ 1] - 奶制品\n    [ 2] - 糖浆\n    [ 3] - 甜味剂\n    [ 4] - 酒\n    [ 5] - 其他原料\n    [ 9] - 返回上一级\n");
    //添加了单位的说明，避免单位不清楚，将原本的“质量”改成了“重量”，避免歧义，原来的质量有品质的歧义
    std::cout << "温馨提示：所有的数据均按照重量（单位：克）来进行计算。" << std::endl;
    std::cout << "数值对应为原料的重量，即当前有多少克原料。" << std::endl;
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
      	input_milk(machine_ingredients.additives);
      	break;
      case 2:
      	input_syrup(machine_ingredients.additives);
	break;
      case 3:
      	input_sweeter(machine_ingredients.additives);
      	break;
      case 4:
      	input_alcohol(machine_ingredients.additives);
      	break;
      case 5:
      	input_other_ingredient(machine_ingredients.additives);
      	break;
      default:
      	std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
      	break;
    }
    press_any_button_1();
  }
}

//------------------------------------------------------------------------
//二级子菜单
//原料资源管理子菜单
//添加新原料
void add_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("------------------添加新原料------------------\n");
    std::printf("    [ 1] - 添加水\n    [ 2] - 添加咖啡豆\n    [ 3] - 添加其他原料\n    [ 9] - 返回上一级\n");
    //添加了单位的说明，避免单位不清楚，将原本的“质量”改成了“重量”，避免歧义，原来的质量有品质的歧义
    std::cout << "温馨提示：所有的数据均按照重量（单位：克）来进行计算。" << std::endl;
    std::cout << "数值对应为原料的重量，即当前有多少克原料。" << std::endl;
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
      	std::cout << "请输入咖啡机内当前的水的重量（单位：克）。" << std::endl;
      	input_value(machine_ingredients.water);
      	break;
      case 2:
      	std::cout << "请输入咖啡机内当前的咖啡豆的重量（单位：克）。" << std::endl;
      	input_value(machine_ingredients.coffeeBean);
      	break;
      case 3:
      	add_other_ingredient();
      	break;
      default:
      	std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
	      break;
    }
    press_any_button_1();
  }
}

//删除原料
void delete_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("---------------请选择需要删除的原料类型---------------\n");
    std::printf("    [ 1] - 奶制品\n    [ 2] - 糖浆\n    [ 3] - 甜味剂\n    [ 4] - 酒\n    [ 5] - 其他原料\n    [ 9] - 返回上一级\n");
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
	      delete_milk(machine_ingredients.additives);
	      break;
      case 2:
      	delete_syrup(machine_ingredients.additives);
      	break;
      case 3:
      	delete_sweeter(machine_ingredients.additives);
      	break;
      case 4:
      	delete_alcohol(machine_ingredients.additives);
      	break;
      case 5:
      	delete_other_ingredient(machine_ingredients.additives);
      	break;
      default:
        std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
      	break;
    }
    press_any_button_1();
  }
}

//------------------------------------------------------------------------
//一级子菜单

//原料资源管理
void ingredient_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------原料管理-------------------\n");
    std::printf("    [ 1] - 添加原料\n    [ 2] - 删除原料\n    [ 3] - 现有原料列表\n    [ 9] - 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
	      add_ingredient();
	      break;
      case 2:
	      delete_ingredient();
      	break;
      case 3:
      	print_machine_ingredients();
	      break;
      default:
	      std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
      	break;
    }
    press_any_button_1();
  }
}

//预设菜单管理
void menu_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------菜单管理-------------------\n");
    std::printf("    [ 1] - 添加新菜单\n    [ 2] - 删除菜单\n    [ 9] - 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 1:
      	add_new_coffee_menu();
      	break;
      case 2:
      	delete_drink_menu();
      	break;
      default:
      	std::printf("\033[31m输入错误,请重新输入选项对应的数字。\n\033[0m");
      	break;
    }
    press_any_button_1();
  }
}

#endif /* INCLUDE_MAINLIST_H_ */
