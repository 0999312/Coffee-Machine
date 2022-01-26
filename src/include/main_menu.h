#ifndef INCLUDE_MAINMENU_H_
#define INCLUDE_MAINMENU_H_
/*
 * 头文件保护, IDE自带。
 * #ifndef表示如果未定义头文件则进行一次定义。
 * 这个写法来自于C，而且C++也需要使用这种方法。
 */
#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include <ctime>// C语言 时间
#include "structs.h" // 自己的结构体头文件
#include "functions.h" // 自己的函数头文件

void main_menu(){
  std::time_t now = std::time(nullptr);
  std::tm *ltm = std::localtime(&now);
  std::printf("咖啡机模拟系统 当前版本:v1.0 当前时间:  ");
  std::printf("%04d年%02d月%02d日  ", ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);
  std::printf("%02d时%02d分%02d秒\n", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  print_line();
  std::printf("咖啡豆剩余量：%d\n", machine_ingredients.coffeeBean);
  std::printf("水剩余量：%d\n", machine_ingredients.water);
  std::printf("本次运行已制作的咖啡数量：0 杯美式滴滤 / 0 杯意式浓缩\n");
  print_line();
  std::printf("[0] 原料管理 [1] 菜单管理 [2] 新增订单 [3] 打印预设菜单 [-1] 结束程序\n");
  press_any_button();
}

#endif /* INCLUDE_MAINMENU_H_ */
