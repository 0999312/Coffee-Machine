
#include <iostream> // C++ 风格输入输出，使用输入输出流进行操作。
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <list> //C++ STL实现 双向链表（我们甚至不需要自己写链表了，YES）
#include "include/structs.h" // 自己的结构体头文件
#include "include/functions.h" // 自己的函数头文件
int main() {
    //使用UTF-8编码，好像是Windows的老毛病
#ifdef _WIN32
    std::system("chcp 65001");
#endif

    // 咖啡机内菜单
    std::list<coffee_menu> machine_menus;
    if (!has_ingredients()) {
        if (!read_ingredients()) {
            create_new_ingredients();
        }
        else {
            std::cout << "已初始化成功。" << std::endl;
            press_any_button();
        }
        std::fstream ingredientsFile;
        ingredientsFile.open("ingredients.txt", std::ios::out | std::ios::trunc);
        print_machine_ingredients(ingredientsFile);
        ingredientsFile.close();
        return 0;
    }