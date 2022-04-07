#ifndef INCLUDE_STRUCTS_H_
#define INCLUDE_STRUCTS_H_
/*
 * 头文件保护, IDE自带。
 * #ifndef表示如果未定义头文件则进行一次定义。
 * 这个写法来自于C，而且C++也需要使用这种方法。
 */
#include <string> // C++ 字符串库
#include <map> // C++ Map数据类型库
#include <utility> // C++ 通用工具头文件，pair定义于此
#include <algorithm> // C++算法库

// C++里可以直接在结构体里定义函数。
// 不用class的原因是“保护新人”，严格来说这里可以直接使用class并且推荐使用class。
// 对于Map的操作，建议封装函数；对于剩下两个int变量的操作封装交给其他人完成。

// 咖啡添加剂
struct coffee_additives {
    // 奶制品
    std::map<std::string, int> milk;
    // 糖浆
    std::map<std::string, int> syrup;
    // 甜味剂，不限于砂糖等
    std::map<std::string, int> sweeter;
    // 酒
    std::map<std::string, int> alcohol;
    // 其他添加剂
    std::map<std::string, int> others;

    bool operator ==(const coffee_additives& other){
      return this->milk == other.milk
	  && this->syrup == other.syrup
	  && this->sweeter == other.sweeter
	  && this->alcohol == other.alcohol
	  && this->others == other.others;
    }

    /*
     * 直接设定原料的方法以set开头，添加原料的方法以add开头
     * 获取原料的方法以get开头，使用（减少）原料的方法以use开头
     * 如果获取不到当前材料，会直接插入一个数量为0的材料。
     * 如果无法减少（余量不足），返回false表示无法消耗材料完成任务。
     */

    /*
     * find的结果应该是一个std::pair<std::string, int>
     * pair的结构是<first, second>
     * 这里map的end()并不是最后一个元素，而是一个空元素表示未定义。
     * 如果不是未定义，则直接输出result的second。
     * 如果正好是未定义，直接插入新元素。
     * 下方的代码不再进行注释，参考这里。
     */
    void set_milk(std::string name, int count) {
      auto result = this->milk.find(name);
      if (result != this->milk.end())
	result->second = count;
      else
	this->milk.insert(std::pair<std::string, int>(name, count));
    }

    void add_milk(std::string name, int count) {
      auto result = this->milk.find(name);
      if (result != this->milk.end())
	result->second += count;
      else
	this->milk.insert(std::pair<std::string, int>(name, count));
    }

    int get_milk(std::string name) {
      auto result = this->milk.find(name);
      if (result != this->milk.end())
	return result->second;
      this->milk.insert(std::pair<std::string, int>(name, 0));
      return 0;
    }

    bool use_milk(std::string name, int count) {
      bool useResult = false;
      auto result = this->milk.find(name);
      if (result != this->milk.end()) {
	if (result->second >= count) {
	  result->second -= count;
	  useResult = true;
	}
      }
      return useResult;
    }

    bool delete_milk(std::string name) {
      bool useResult = false;
      auto result = this->milk.find(name);
      if (result != this->milk.end()) {
	this->milk.erase(name);
	useResult = true;
      }
      return useResult;
    }

    void set_syrup(std::string name, int count) {
      auto result = this->syrup.find(name);
      if (result != this->syrup.end())
	result->second = count;
      else
	this->syrup.insert(std::pair<std::string, int>(name, count));
    }

    void add_syrup(std::string name, int count) {
      auto result = this->syrup.find(name);
      if (result != this->syrup.end())
	result->second += count;
      else
	this->syrup.insert(std::pair<std::string, int>(name, count));
    }

    int get_syrup(std::string name) {
      auto result = this->syrup.find(name);
      if (result != this->syrup.end())
	return result->second;
      this->syrup.insert(std::pair<std::string, int>(name, 0));
      return 0;
    }

    bool use_syrup(std::string name, int count) {
      bool useResult = false;
      auto result = this->syrup.find(name);
      if (result != this->syrup.end()) {
	if (result->second >= count) {
	  result->second -= count;
	  useResult = true;
	}
      }
      return useResult;
    }

    bool delete_syrup(std::string name) {
      bool useResult = false;
      auto result = this->syrup.find(name);
      if (result != this->syrup.end()) {
	this->syrup.erase(name);
	useResult = true;
      }
      return useResult;
    }

    void set_sweeter(std::string name, int count) {
      auto result = this->sweeter.find(name);
      if (result != this->sweeter.end())
	result->second = count;
      else
	this->sweeter.insert(std::pair<std::string, int>(name, count));
    }

    void add_sweeter(std::string name, int count) {
      auto result = this->sweeter.find(name);
      if (result != this->sweeter.end())
	result->second += count;
      else
	this->sweeter.insert(std::pair<std::string, int>(name, count));
    }

    int get_sweeter(std::string name) {
      auto result = this->sweeter.find(name);
      if (result != this->sweeter.end())
	return result->second;
      this->sweeter.insert(std::pair<std::string, int>(name, 0));
      return 0;
    }

    bool use_sweeter(std::string name, int count) {
      bool useResult = false;
      auto result = this->sweeter.find(name);
      if (result != this->sweeter.end()) {
	if (result->second >= count) {
	  result->second -= count;
	  useResult = true;
	}
      }
      return useResult;
    }

    bool delete_sweeter(std::string name) {
      bool useResult = false;
      auto result = this->sweeter.find(name);
      if (result != this->sweeter.end()) {
	this->sweeter.erase(name);
	useResult = true;
      }
      return useResult;
    }

    void set_alcohol(std::string name, int count) {
      auto result = this->alcohol.find(name);
      if (result != this->alcohol.end())
	result->second = count;
      else
	this->alcohol.insert(std::pair<std::string, int>(name, count));
    }

    void add_alcohol(std::string name, int count) {
      auto result = this->alcohol.find(name);
      if (result != this->alcohol.end())
	result->second += count;
      else
	this->alcohol.insert(std::pair<std::string, int>(name, count));
    }

    int get_alcohol(std::string name) {
      auto result = this->alcohol.find(name);
      if (result != this->alcohol.end())
	return result->second;
      this->alcohol.insert(std::pair<std::string, int>(name, 0));
      return 0;
    }

    bool use_alcohol(std::string name, int count) {
      bool useResult = false;
      auto result = this->alcohol.find(name);
      if (result != this->alcohol.end()) {
	if (result->second >= count) {
	  result->second -= count;
	  useResult = true;
	}
      }
      return useResult;
    }

    bool delete_alcohol(std::string name) {
      bool useResult = false;
      auto result = this->alcohol.find(name);
      if (result != this->alcohol.end()) {
	this->alcohol.erase(name);
	useResult = true;
      }
      return useResult;
    }

    void set_other_ingredient(std::string name, int count) {
      auto result = this->others.find(name);
      if (result != this->others.end())
	result->second = count;
      else
	this->others.insert(std::pair<std::string, int>(name, count));
    }

    void add_other_ingredient(std::string name, int count) {
      auto result = this->others.find(name);
      if (result != this->others.end())
	result->second += count;
      else
	this->others.insert(std::pair<std::string, int>(name, count));
    }

    int get_other_ingredient(std::string name) {
      auto result = this->others.find(name);
      if (result != this->others.end())
	return result->second;
      this->others.insert(std::pair<std::string, int>(name, 0));
      return 0;
    }

    bool use_other_ingredient(std::string name, int count) {
      bool useResult = false;
      auto result = this->others.find(name);
      if (result != this->others.end()) {
	if (result->second >= count) {
	  result->second -= count;
	  useResult = true;
	}
      }
      return useResult;
    }

    bool delete_other_ingredient(std::string name) {
      bool useResult = false;
      auto result = this->others.find(name);
      if (result != this->others.end()) {
	this->others.erase(name);
	useResult = true;
      }
      return useResult;
    }

    bool use_ingredient(std::string name, int count) {
      if (use_milk(name, count))
	return true;
      if (use_syrup(name, count))
	return true;
      if (use_sweeter(name, count))
	return true;
      if (use_alcohol(name, count))
	return true;
      if (use_other_ingredient(name, count))
	return true;
      return false;
    }

    bool use_additives(coffee_additives& additives) {
      std::map<std::string, int>::iterator it; //定义map迭代器，用于遍历map。
      for (it = additives.milk.begin();
          it != additives.milk.end(); it++) {
        if(!use_milk(it->first, it->second))
          return false;
      }
      for (it = additives.syrup.begin();
          it != additives.syrup.end(); it++) {
        if(!use_syrup(it->first, it->second))
          return false;
      }
      for (it = additives.sweeter.begin();
          it != additives.sweeter.end(); it++) {
        if(!use_sweeter(it->first, it->second))
          return false;
      }
      for (it = additives.alcohol.begin();
          it != additives.alcohol.end(); it++) {
        if(!use_alcohol(it->first, it->second))
          return false;
      }
      for (it = additives.others.begin();
          it != additives.others.end(); it++) {
        if(!use_other_ingredient(it->first, it->second))
          return false;
      }
      return true;
    }

    bool delete_ingredient(std::string name) {
      if (delete_milk(name))
	return true;
      if (delete_syrup(name))
	return true;
      if (delete_sweeter(name))
	return true;
      if (delete_alcohol(name))
	return true;
      if (delete_other_ingredient(name))
	return true;
      return false;
    }
};

// 咖啡机器内原料表，包括水，咖啡豆，奶制品等添加剂。
// 我们只模拟一台咖啡机！
struct coffee_ingredients {
    // 水
    int water;
    // 咖啡豆
    int coffeeBean;
    // 添加剂
    coffee_additives additives;

    bool use_water(int count) {
      if (water >= count) {
	water -= count;
	return true;
      }
      return false;
    }

    bool use_coffee_bean(int count) {
      if (coffeeBean >= count) {
	coffeeBean -= count;
	return true;
      }
      return false;
    }

} machine_ingredients;

//struct coffee_cup {
//    // 咖啡名称
//    std::string name;
//    // 添加剂
//    int amount;
//
//    bool is_too_much(int coffee_amount){
//      //出现负数代表无限容量的杯子。
//      //判断负数是因为可能会出现胡乱修改数据的情况以及方便调试。
//      if(this->amount < 0) return false;
//      return coffee_amount > this->amount;
//    }
//
//    bool operator == (const coffee_cup &other){
//      return this->name == other.name && this->amount == other.amount;
//    }
//
//    bool operator <(const coffee_cup &other){
//      bool result = this->amount < other.amount;
//      return result ? result : (this->amount == other.amount && this->name < other.name);
//    }
//
//    bool operator >(const coffee_cup &other){
//      bool result = this->amount > other.amount;
//      return result ? result : (this->amount == other.amount && this->name > other.name);
//    }
//
//};


// 咖啡菜单表，当然是按一杯咖啡的量进行计算。
struct coffee_menu {
    // 咖啡名称
    std::string name;
    // 咖啡基底类型，true代表使用意式浓缩，false代表使用美式滴滤。
    // 咖啡类型的用量算法已经写在文档里了。
    // 如果你想要咖啡机里装其他类型的咖啡基底，请直接发issue。
    bool type;
    // 咖啡用量
    int amount;
    // 添加剂
    coffee_additives additives;

    bool operator ==(const coffee_menu& other){
      return this->name == other.name
	  && this->type == other.type
	  && this->amount == other.amount
	  && this->additives == other.additives;
    }

}null_menu;

struct coffee_machine_stat {
    // 美式滴滤的杯数
    int drip = 0;
    // 意式浓缩的杯数
    int espresso = 0;
    // 添加剂
    coffee_additives additives;


}machine_stat;

// machine_menus为咖啡机的预设菜单，completed_menus为咖啡机制作完成的菜单表。
// 两个最后都需要打印出来
std::list<coffee_menu> machine_menus, completed_menus;

//
#endif /* INCLUDE_STRUCTS_H_ */
