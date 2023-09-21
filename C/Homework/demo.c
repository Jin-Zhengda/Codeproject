#include <stdio.h>

int main() {
    int quarter;

    printf("请输入季度");
    scanf("%d", &quarter);

    switch (quarter) {
        case 1:
            printf("1月、2月、3月\n");
            break;
        case 2:
            printf("4月、5月、6月\n");
            break;
        case 3:
            printf("7月、8月、9月\n");
            break;
        case 4:
            printf("10月、11月、12月\n");
            break;
        default:
            printf("输入不合法！\n");
            break;
    }

    return 0;
}