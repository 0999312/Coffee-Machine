#include <cstdio>
#include <ctime>

int main(int argc, char* argv[]) {
    time_t rawtime;//����Ǵ�ӡ��ǰʱ��ģ���Ҳ��֪����д�˸�ɶ���Ǹ����Ҳ鵽���������ģ��Ҹ���һЩ��Ӧ�����ܡ�����
    struct tm* ptminfo;

    time(&rawtime);
    ptminfo = localtime(&rawtime);
        ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);

    printf("����������������������������������������������������������");
    printf("      ���Ȼ�ģ��ϵͳ ��ǰ�汾:v1.0 ��ǰʱ��:%02d-%02d-%02d %02d:%02d:%02d\n", ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec��;
    printf(" ����������������������������������������������������������");
    printf("���ȶ�ʣ����������ǰʣ��Ŀ��ȶ�����"��;//����ĵ������治���ˣ��Ͱ������ˣ�˳�㵽ʱ�����һ�°�
    printf("ˮʣ����������ǰʣ��Ŀ��ȶ�������");
    printf("���������������Ŀ���������X ����ʽ���� / Y ����ʽŨ��");
    printf("����������������������������������������������������������");
    printf��"[0] ԭ�Ϲ���[1] �˵�����[2] ��������[3] ��ӡԤ��˵�[-1] ��������");
    printf("����������������������������������������������������������");
    printf("������ָ�");
    return 0;//������һ��дע�;�Ȼֻ��Ϊ���²ۣ�Ҳ��û˭��
}
