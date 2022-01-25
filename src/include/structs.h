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

// C++里可以直接在结构体里定义函数。
// 不用class的原因是“保护新人”，严格来说这里可以直接使用class并且推荐使用class。
// 对于Map的操作，建议封装函数；对于剩下两个int变量的操作封装交给其他人完成。

// 咖啡添加剂
struct coffee_additives{
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
} machine_ingredients;

// 咖啡菜单表，当然是按一杯咖啡的量进行计算。
struct coffee_menu{
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
};

//
#endif /* INCLUDE_FUNCTIONS_H_ */
