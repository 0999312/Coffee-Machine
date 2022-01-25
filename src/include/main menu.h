#include <cstdio>
#include <ctime>

int main(int argc, char* argv[]) {
    time_t rawtime;//这个是打印当前时间的，我也不知道我写了个啥，是根据我查到的资料来的，我改了一些，应该能跑。。。
    struct tm* ptminfo;

    time(&rawtime);
    ptminfo = localtime(&rawtime);
        ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);

    printf("—————————————————————————————");
    printf("      咖啡机模拟系统 当前版本:v1.0 当前时间:%02d-%02d-%02d %02d:%02d:%02d\n", ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec）;
    printf(" —————————————————————————————");
    printf("咖啡豆剩余量：（当前剩余的咖啡豆质量"）;//后面的调用我真不会了，就拜托你了，顺便到时候教我一下吧
    printf("水剩余量：（当前剩余的咖啡豆质量）");
    printf("本次运行已制作的咖啡数量：X 杯美式滴滤 / Y 杯意式浓缩");
    printf("—————————————————————————————");
    printf（"[0] 原料管理[1] 菜单管理[2] 新增订单[3] 打印预设菜单[-1] 结束程序");
    printf("—————————————————————————————");
    printf("请输入指令：");
    return 0;//唉，第一次写注释竟然只是为了吐槽，也是没谁了
}
