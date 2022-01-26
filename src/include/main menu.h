#include<iostream>

#include<ctime>

using namespace std;

int main(void) {

    time_t now = time(0);

    struct tm p;//指向本地时间的tm结构体
    localtime_s(&p, &now);	//我根据网上找的资料写的，我试过了，能跑
    printf("咖啡机模拟系统 当前版本:v1.0 当前时间:  ");
    printf("%04d年%02d月%02d日  ", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday);
    printf("%02d时%02d分%02d秒\n", p.tm_hour, p.tm_min, p.tm_sec);

    printf(" —————————————————————————————\n");
    printf("咖啡豆剩余量：（当前剩余的咖啡豆质量）\n");//后面的调用我真不会了，就拜托你了，顺便到时候教我一下吧
    printf("水剩余量：（当前剩余的咖啡豆质量）\n");
    printf("本次运行已制作的咖啡数量：X 杯美式滴滤 / Y 杯意式浓缩\n");
    printf("—————————————————————————————\n");
    printf("[0] 原料管理[1] 菜单管理[2] 新增订单[3] 打印预设菜单[-1] 结束程序\n");
    printf("—————————————————————————————\n");
    printf("请输入指令：\n");
    return 0;//唉，第一次写注释竟然只是为了吐槽，也是没谁了
}