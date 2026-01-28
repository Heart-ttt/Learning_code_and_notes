/*假设你正在编写一个收银系统的小票打印程序。
请编写一个c程序，定义几件商品的名称、数量和单价，然后使用printf打印，要求如下
商品名称列宽度为15字符，左对齐
数量列宽度为10字符，右对齐
单价列宽度为10字符，保留两位小数，右对齐*/
#include <stdio.h>
int main(void) {
    // 定义商品信息
    const char *item1_name = "苹果";
    int item1_quantity = 3;
    double item1_price = 2.50;

    const char *item2_name = "香蕉";
    int item2_quantity = 5;
    double item2_price = 1.20;

    const char *item3_name = "橙子";
    int item3_quantity = 2;
    double item3_price = 3.00;

    // 打印小票头部
    printf("%-15s %10s %10s\n", "商品名称", "数量", "单价");
    printf("----------------------------------------\n");   
    printf("%-15s %10d %10.2f\n", item1_name, item1_quantity, item1_price);
    printf("%-15s %10d %10.2f\n", item2_name, item2_quantity, item2_price);
    printf("%-15s %10d %10.2f\n", item3_name, item3_quantity, item3_price);
}

