#include <stdio.h>

int main() {
    int quarter;

    printf("�����뼾��");
    scanf("%d", &quarter);

    switch (quarter) {
        case 1:
            printf("1�¡�2�¡�3��\n");
            break;
        case 2:
            printf("4�¡�5�¡�6��\n");
            break;
        case 3:
            printf("7�¡�8�¡�9��\n");
            break;
        case 4:
            printf("10�¡�11�¡�12��\n");
            break;
        default:
            printf("���벻�Ϸ���\n");
            break;
    }

    return 0;
}