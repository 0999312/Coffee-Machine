
#include <iostream> // C++ ������������ʹ��������������в�����
#include <utility> // C++ ͨ�ù���ͷ�ļ���pair�����ڴ�
#include <list> //C++ STLʵ�� ˫������������������Ҫ�Լ�д�����ˣ�YES��
#include "include/structs.h" // �Լ��Ľṹ��ͷ�ļ�
#include "include/functions.h" // �Լ��ĺ���ͷ�ļ�
int main() {
    //ʹ��UTF-8���룬������Windows����ë��
#ifdef _WIN32
    std::system("chcp 65001");
#endif

    // ���Ȼ��ڲ˵�
    std::list<coffee_menu> machine_menus;
    if (!has_ingredients()) {
        if (!read_ingredients()) {
            create_new_ingredients();
        }
        else {
            std::cout << "�ѳ�ʼ���ɹ���" << std::endl;
            press_any_button();
        }
        std::fstream ingredientsFile;
        ingredientsFile.open("ingredients.txt", std::ios::out | std::ios::trunc);
        print_machine_ingredients(ingredientsFile);
        ingredientsFile.close();
        return 0;
    }