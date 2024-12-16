#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int *n);
void hienThiMang(int *arr, int n);
int tinhDoDaiMang(int *arr, int n);
int tinhTongMang(int *arr, int n);
int phanTuLonNhat(int *arr, int n);

int main() {
    int choice, n = 0;
    int *arr = NULL;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai mang la: %d\n", n);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTongMang(arr, n));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang: %d\n", phanTuLonNhat(arr, n));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                free(arr);
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}

void nhapMang(int *arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);

    arr = (int *)malloc((*n) * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap tung phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int *arr, int n) {
    if (n == 0 || arr == NULL) {
        printf("Mang trong, vui long nhap du lieu truoc!\n");
        return;
    }
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhTongMang(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int phanTuLonNhat(int *arr, int n) {
    if (n == 0 || arr == NULL) {
        printf("Mang trong, vui long nhap du lieu truoc!\n");
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

