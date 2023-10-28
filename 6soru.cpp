#include <stdio.h>
#include <string.h>

void en_uzun_isim(const char *isimler[], int n) {
    if (n <= 0) {
        printf("Liste bos veya geçersiz.\n");
        return;
    }

    int uzunluk = 0;
    const char *en_uzun = isimler[0];

    for (int i = 1; i < n; i++) {
        if (strlen(isimler[i]) > uzunluk) {
            uzunluk = strlen(isimler[i]);
            en_uzun = isimler[i];
        }
    }

    printf("Listedeki en uzun isim: %s uzunluk: %d\n", en_uzun, uzunluk);
}

int main() {
    const char *isimler[] = {"ali", "veli", "ayse", "abdurrahmangazzi", "mustafa"};
    int n = sizeof(isimler) / sizeof(isimler[0]);

    en_uzun_isim(isimler, n);

    return 0;
}

