#ifndef INCLUDE_FUNCTIONS_H_
#define INCLUDE_FUNCTIONS_H_
/*
 * ͷ�ļ�����, IDE�Դ���
 * #ifndef��ʾ���δ����ͷ�ļ������һ�ζ��塣
 * ���д��������C������C++Ҳ��Ҫʹ�����ַ�����
 */
#include <string> // C++ �ַ�����
#include <map> // C++ Map�������Ϳ�
#include <utility> // C++ ͨ�ù���ͷ�ļ���pair�����ڴ�

// C++�����ֱ���ڽṹ���ﶨ�庯����
// ����class��ԭ���ǡ��������ˡ����ϸ���˵�������ֱ��ʹ��class�����Ƽ�ʹ��class��
// ����Map�Ĳ����������װ����������ʣ������int�����Ĳ�����װ������������ɡ�

// ������Ӽ�
struct coffee_additives{
    // ����Ʒ
    std::map<std::string, int> milk;
    // �ǽ�
    std::map<std::string, int> syrup;
    // ��ζ����������ɰ�ǵ�
    std::map<std::string, int> sweeter;
    // ��
    std::map<std::string, int> alcohol;
    // ������Ӽ�
    std::map<std::string, int> others;

    /*
     * ֱ���趨ԭ�ϵķ�����set��ͷ�����ԭ�ϵķ�����add��ͷ
     * ��ȡԭ�ϵķ�����get��ͷ��ʹ�ã����٣�ԭ�ϵķ�����use��ͷ
     * �����ȡ������ǰ���ϣ���ֱ�Ӳ���һ������Ϊ0�Ĳ��ϡ�
     * ����޷����٣��������㣩������false��ʾ�޷����Ĳ����������
     */

    /*
     * find�Ľ��Ӧ����һ��std::pair<std::string, int>
     * pair�Ľṹ��<first, second>
     * ����map��end()���������һ��Ԫ�أ�����һ����Ԫ�ر�ʾδ���塣
     * �������δ���壬��ֱ�����result��second��
     * ���������δ���壬ֱ�Ӳ�����Ԫ�ء�
     * �·��Ĵ��벻�ٽ���ע�ͣ��ο����
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

// ���Ȼ�����ԭ�ϱ�����ˮ�����ȶ�������Ʒ����Ӽ���
// ����ֻģ��һ̨���Ȼ���
struct coffee_ingredients {
    // ˮ
    int water;
    // ���ȶ�
    int coffeeBean;
    // ��Ӽ�
    coffee_additives additives;
} machine_ingredients;

// ���Ȳ˵�����Ȼ�ǰ�һ�����ȵ������м��㡣
struct coffee_menu{
    // ��������
    std::string name;
    // ���Ȼ������ͣ�true����ʹ����ʽŨ����false����ʹ����ʽ���ˡ�
    // �������͵������㷨�Ѿ�д���ĵ����ˡ�
    // �������Ҫ���Ȼ���װ�������͵Ŀ��Ȼ��ף���ֱ�ӷ�issue��
    bool type;
    // ��������
    int amount;
    // ��Ӽ�
    coffee_additives additives;
};

//
#endif /* INCLUDE_FUNCTIONS_H_ */
