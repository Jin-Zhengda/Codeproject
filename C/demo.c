#include <stdio.h>

#define ROWS 3
#define COLS 2

void sortArray(int arr[ROWS][COLS]) {
    int i, j, temp[2];
    // 使用冒泡排序按第二列的值对数组进行排序
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < ROWS - i - 1; j++) {
            if (arr[j][1] < arr[j + 1][1]) {
                temp[0] = arr[j][0];
                temp[1] = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp[0];
                arr[j + 1][1] = temp[1];
            }
        }
    }
}

int main() {
    int array[ROWS][COLS] = {{2, 8}, {1, 5}, {3, 3}};
    
    printf("Original Array:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d %d\n", array[i][0], array[i][1]);
    }
    
    sortArray(array);
    
    printf("\nSorted Array:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d %d\n", array[i][0], array[i][1]);
    }
    
    return 0;
}
