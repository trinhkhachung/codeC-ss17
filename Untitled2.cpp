#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    int choice;
    int i;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0; 
                break;

            case 2:
                printf("Chuoi da nhap la: %s\n", str);
                break;

            case 3: {
                int count = 0;
                for (i = 0; str[i] != '\0'; i++) {
                    if (isalpha(str[i])) {
                        count++;
                    }
                }
                printf("So luong chu cai trong chuoi: %d\n", count);
                break;
            }

            case 4: {
                int count = 0;
                for (i = 0; str[i] != '\0'; i++) {
                    if (isdigit(str[i])) {
                        count++;
                    }
                }
                printf("So luong chu so trong chuoi: %d\n", count);
                break;
            }

            case 5: {
                int count = 0;
                for (i = 0; str[i] != '\0'; i++) {
                    if (!isalnum(str[i]) && !isspace(str[i])) {
                        count++;
                    }
                }
                printf("So luong ky tu dac biet trong chuoi: %d\n", count);
                break;
            }

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
        }
    } while (choice != 6);

    return 0;
}

