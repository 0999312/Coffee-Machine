#include "functions.h" // 自己的函数头文件

//子菜单，直接引用即可

//一级子菜单

//原料资源管理
void ingredient_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------原料管理-------------------\n");
    std::printf("[0] 添加新原料 [1] 添加已有原料 [2] 删除原料 [3] 现有原料列表 [4] 返回主界面\n");
    std::cin >> button;
    if (button == 4)
      break;
    switch (button) {
      /*
       case 0 : break;
       case 1 : break;
       case 2 : break;
       case 3 : break;
       case 4 : break;
       */
      default:
	std::printf("未完成，请返回上一级\n");
	break;
    }
    press_any_button();
  }
}

//预设菜单管理
void menu_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------菜单管理-------------------\n");
    std::printf("[0] 添加新菜单 [1] 删除菜单 [2] 返回主界面\n");
    std::cin >> button;
    if (button == 2)
      break;
    switch (button) {
      /*
       case 0 : break;
       case 1 : break;
       */
      default:
	std::printf("未完成，请返回上一级\n");
	break;
    }
    press_any_button();
  }
}

//新增订单
void add_order() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------新增订单-------------------\n");
    std::printf("[0] 添加新菜单 [1] 删除菜单 [2] 返回主界面\n");
    std::cin >> button;
    if (button == 2)
      break;
    switch (button) {
      /*
       case 0 : break;
       case 1 : break;
       */
      default:
	std::printf("未完成，请返回上一级\n");
	break;
    }
    press_any_button();
  }
}

//打印预设菜单
void print_preset_menu() {
  system_status();
  std::printf("未完成\n");
  press_any_button();
}
