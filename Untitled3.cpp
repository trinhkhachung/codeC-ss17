#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000], newStr[1000];
    int choice, i, length, count;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh chuoi khac voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap chuoi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                break;

            case 2:
                length = strlen(str);
                printf("Chuoi dao nguoc: ");
                for (i = length - 1; i >= 0; i--) {
                    printf("%c", str[i]);
                }
                printf("\n");
                break;

            case 3:
                count = 0;
                for (i = 0; str[i] != '\0'; i++) {
                    if (isspace(str[i])) {
                        count++;
                    }
                }
                if (strlen(str) > 0) count++;
                printf("So luong tu trong chuoi: %d\n", count);
                break;

            case 4:
                printf("Nhap chuoi khac: ");
                fgets(newStr, sizeof(newStr), stdin);
                newStr[strcspn(newStr, "\n")] = '\0';
                if (strlen(newStr) > strlen(str)) {
                    printf("Chuoi moi dai hon chuoi ban dau\n");
                } else if (strlen(newStr) < strlen(str)) {
                    printf("Chuoi moi ngan hon chuoi ban dau\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau\n");
                }
                break;

            case 5:
                for (i = 0; str[i] != '\0'; i++) {
                    str[i] = toupper(str[i]);
                }
                printf("Chuoi in hoa: %s\n", str);
                break;

            case 6:
                printf("Nhap chuoi khac de them vao: ");
                fgets(newStr, sizeof(newStr), stdin);
                newStr[strcspn(newStr, "\n")] = '\0';
                strcat(str, newStr);
                printf("Chuoi sau khi them: %s\n", str);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}
