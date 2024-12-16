#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n = 0, arr[100], choice, i, search, found;
    int tempArr[100];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang (Tang dan / Giam dan)\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap tung phan tu:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu [%d]: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Cac phan tu la so chan: ");
                for (i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Cac phan tu la so nguyen to: ");
                for (i = 0; i < n; i++) {
                    if (isPrime(arr[i])) printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Mang dao nguoc: ");
                for (i = 0; i < n; i++) {
                    tempArr[i] = arr[n - i - 1];
                }
                for (i = 0; i < n; i++) {
                    printf("%d ", tempArr[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Chon cach sap xep:\n1. Tang dan\n2. Giam dan\n");
                int order;
                scanf("%d", &order);

                for (i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((order == 1 && arr[i] > arr[j]) || (order == 2 && arr[i] < arr[j])) {
                            swap(&arr[i], &arr[j]);
                        }
                    }
                }

                printf("Mang sau khi sap xep: ");
                for (i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;

            case 6:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &search);
                found = 0;

                for (i = 0; i < n; i++) {
                    if (arr[i] == search) {
                        printf("Phan tu %d tim thay o vi tri %d\n", search, i + 1);
                        found = 1;
                    }
                }

                if (!found) printf("Phan tu %d khong co trong mang.\n", search);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
}

