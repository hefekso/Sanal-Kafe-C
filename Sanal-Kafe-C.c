#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// ESC kontrolü ve tuş okuma fonksiyonu
// Çıkmak isterse programı kapatır, vazgeçerse 1 döndürür (ana ekrana atar)
int tus_oku_ve_kontrol(char *basilan_tus) {
    *basilan_tus = _getch();

    if (*basilan_tus == 27) { // 27 = ESC
        system("cls");
        system("color 0C"); // Uyarı için kırmızı yazı
        printf("\n\n\t\t Cikmak istediginizden emin misiniz? (E/H)\n");
        printf("\t\t (Ana ekrana donmek icin H veya baska bir tusa basiniz...)");

        char onay = _getch();
        if (onay == 'E' || onay == 'e') {
            exit(0);
        } else {
            return 1; // Ana ekrana dönüş sinyali
        }
    }
    return 0; // Normal tuş basımı
}

int main() {
    // Menü Fiyatları
    int Turk1 = 49, Turk2 = 46, Turk3 = 50, Turk4 = 40;
    int espresso1 = 43, espresso2 = 40, espresso3 = 46, espresso4 = 33;
    int mocha1 = 70, mocha2 = 75;
    int americano = 47, cappucino = 52, caffe_latte = 54, salep = 73;
    int sicak_cikolata1 = 69, sicak_cikolata2 = 73;

    char tus, tus2, tus3;
    int sonuc;

    // --- DIŞ DÖNGÜ: HOŞGELDİNİZ EKRANI ---
    while (1) {
        system("cls");
        system("color F1");

        printf("\n\n\n\n\t\t\t\t%c", 201);
        for (int i = 0; i < 50; i++) printf("%c", 205);
        printf("%c\n", 187);

        printf("\t\t\t\t%c%50s%c\n", 186, "", 186);
        printf("\t\t\t\t%c\t      SANAL KAFEYE HOSGELDINIZ             %c\n", 186, 186);
        printf("\t\t\t\t%c%50s%c\n", 186, "", 186);
        printf("\t\t\t\t%c%50s%c\n", 186, "", 186);
        printf("\t\t\t\t%c\tDevam etmek icin D veya d tusuna basiniz   %c\n", 186, 186);
        printf("\t\t\t\t%c%50s%c\n", 186, "", 186);
        printf("\t\t\t\t%c\t      CIKIS icin ESC tusuna basiniz        %c\n", 186, 186);
        printf("\t\t\t\t%c%50s%c\n", 186, "", 186);

        printf("\t\t\t\t%c", 200);
        for (int a = 0; a < 50; a++) printf("%c", 205);
        printf("%c", 188);

        sonuc = tus_oku_ve_kontrol(&tus);
        if (sonuc == 1) continue; // ESC'den vazgeçerse giriş ekranını yenile

        // --- İÇ DÖNGÜ: ANA MENÜ VE SİPARİŞ ---
        if (tus == 'D' || tus == 'd') {
            while (1) {
                int birim_fiyat = 0;
                const char *secilen_urun = "";
                int siparis_gecerli = 0; // Geçerli bir ürün seçildiyse 1 olur

                system("cls");
                system("color F1");
                printf("\t\t                            KAHVE CESITLERI \n");
                printf("\t\t               -----------------------------------------------\n\n");
                printf("\t\t                   1-TURK KAHVESI            40TL'den baslayan\n\n");
                printf("\t\t                   2-ESPRESSO                33TL'den baslayan\n\n");
                printf("\t\t                   3-MOCHA                   70TL'den baslayan\n\n");
                printf("\t\t                   4-AMERICANO               47TL\n\n");
                printf("\t\t                   5-CAPPUCINO               52TL\n\n");
                printf("\t\t                   6-CAFFE LATTE             54TL\n\n");
                printf("\t\t                   7-SICAK CIKOLATA          69TL'den baslayan\n\n");
                printf("\t\t                   8-SALEP                   73TL\n\n\n");
                printf("\t\t Lutfen seciminizi yapiniz (Ana ekrana donmek icin ESC): ");

                sonuc = tus_oku_ve_kontrol(&tus2);
                if (sonuc == 1) break; // İç döngüyü kırar -> Hoşgeldiniz ekranına döner

                switch (tus2) {
                case '1': // TÜRK KAHVESİ
                    system("cls");
                    system("color E0");
                    printf("\t\t                           TURK KAHVESI MENUSU \n");
                    printf("\t\t               -----------------------------------------------\n\n");
                    printf("\t\t                   1-SUTLU TURK KAHVESI                49TL\n\n");
                    printf("\t\t                   2-DAMLA SAKIZLI TURK KAHVESI        46TL\n\n");
                    printf("\t\t                   3-CIKOLATALI TURK KAHVESI           50TL\n\n");
                    printf("\t\t                   4-SADE TURK KAHVESI                 40TL\n\n");
                    printf("\t\t Seciminiz (Geri donmek icin ESC): ");

                    sonuc = tus_oku_ve_kontrol(&tus3);
                    if (sonuc == 1) break;

                    if (tus3 == '1') { birim_fiyat = Turk1; secilen_urun = "SUTLU TURK KAHVESI"; siparis_gecerli = 1; }
                    else if (tus3 == '2') { birim_fiyat = Turk2; secilen_urun = "DAMLA SAKIZLI TURK KAHVESI"; siparis_gecerli = 1; }
                    else if (tus3 == '3') { birim_fiyat = Turk3; secilen_urun = "CIKOLATALI TURK KAHVESI"; siparis_gecerli = 1; }
                    else if (tus3 == '4') { birim_fiyat = Turk4; secilen_urun = "SADE TURK KAHVESI"; siparis_gecerli = 1; }
                    break;

                case '2': // ESPRESSO
                    system("cls");
                    system("color E0");
                    printf("\t\t                               ESPRESSO MENU \n");
                    printf("\t\t               -----------------------------------------------\n\n");
                    printf("\t\t                   1-DOUBLE ESPRESSO                 43TL\n\n");
                    printf("\t\t                   2-ESPRESSO MACCHIATO              40TL\n\n");
                    printf("\t\t                   3-DOUBLE ESPRESSO MACCHIATO       46TL\n\n");
                    printf("\t\t                   4-ESPRESSO                        33TL\n\n");
                    printf("\t\t Seciminiz (Geri donmek icin ESC): ");

                    sonuc = tus_oku_ve_kontrol(&tus3);
                    if (sonuc == 1) break;

                    if (tus3 == '1') { birim_fiyat = espresso1; secilen_urun = "DOUBLE ESPRESSO"; siparis_gecerli = 1; }
                    else if (tus3 == '2') { birim_fiyat = espresso2; secilen_urun = "ESPRESSO MACCHIATO"; siparis_gecerli = 1; }
                    else if (tus3 == '3') { birim_fiyat = espresso3; secilen_urun = "DOUBLE ESPRESSO MACCHIATO"; siparis_gecerli = 1; }
                    else if (tus3 == '4') { birim_fiyat = espresso4; secilen_urun = "ESPRESSO"; siparis_gecerli = 1; }
                    break;

                case '3': // MOCHA
                    system("cls");
                    system("color E0");
                    printf("\t\t                                 MOCHA MENU \n");
                    printf("\t\t               -----------------------------------------------\n\n");
                    printf("\t\t                   1-SADE MOCHA                70TL\n\n");
                    printf("\t\t                   2-CIKOLATALI MOCHA          75TL\n\n");
                    printf("\t\t Seciminiz (Geri donmek icin ESC): ");

                    sonuc = tus_oku_ve_kontrol(&tus3);
                    if (sonuc == 1) break;

                    if (tus3 == '1') { birim_fiyat = mocha1; secilen_urun = "SADE MOCHA"; siparis_gecerli = 1; }
                    else if (tus3 == '2') { birim_fiyat = mocha2; secilen_urun = "CIKOLATALI MOCHA"; siparis_gecerli = 1; }
                    break;

                case '4': // AMERICANO
                    birim_fiyat = americano;
                    secilen_urun = "AMERICANO";
                    siparis_gecerli = 1;
                    break;

                case '5': // CAPPUCINO
                    birim_fiyat = cappucino;
                    secilen_urun = "CAPPUCINO";
                    siparis_gecerli = 1;
                    break;

                case '6': // CAFFE LATTE
                    birim_fiyat = caffe_latte;
                    secilen_urun = "CAFFE LATTE";
                    siparis_gecerli = 1;
                    break;

                case '7': // SICAK CIKOLATA
                    system("cls");
                    system("color E0");
                    printf("\t\t                              SICAK CIKOLATA MENU \n");
                    printf("\t\t               -----------------------------------------------\n\n");
                    printf("\t\t                   1-KAHVELI SICAK CIKOLATA          69TL\n\n");
                    printf("\t\t                   2-BEYAZ SICAK CIKOLATA            73TL\n\n");
                    printf("\t\t Seciminiz (Geri donmek icin ESC): ");

                    sonuc = tus_oku_ve_kontrol(&tus3);
                    if (sonuc == 1) break;

                    if (tus3 == '1') { birim_fiyat = sicak_cikolata1; secilen_urun = "KAHVELI SICAK CIKOLATA"; siparis_gecerli = 1; }
                    else if (tus3 == '2') { birim_fiyat = sicak_cikolata2; secilen_urun = "BEYAZ SICAK CIKOLATA"; siparis_gecerli = 1; }
                    break;

                case '8': // SALEP
                    system("cls");
                    system("color E0");
                    printf("\t\t                    SALEP SEKER SECIMI (seker ucretsizdir) \n");
                    printf("\t\t               -----------------------------------------------\n\n");
                    printf("\t\t                   1-SEKERLI\n\n");
                    printf("\t\t                   2-SEKERSIZ\n\n");
                    printf("\t\t Seciminiz (Geri donmek icin ESC): ");

                    sonuc = tus_oku_ve_kontrol(&tus3);
                    if (sonuc == 1) break;

                    if (tus3 == '1') { birim_fiyat = salep; secilen_urun = "SEKERLI SALEP"; siparis_gecerli = 1; }
                    else if (tus3 == '2') { birim_fiyat = salep; secilen_urun = "SEKERSIZ SALEP"; siparis_gecerli = 1; }
                    break;

                default:
                    system("cls");
                    printf("\n\n\t\t LUTFEN GECERLI BIR SECIM YAPINIZ!");
                    _getch();
                    continue;
                }

                // Alt menüde ESC'ye basıldıysa dış döngüye (Hoşgeldiniz ekranına) at
                if (sonuc == 1) break;

                // --- ORTAK ÖDEME VE PARA ÜSTÜ SİSTEMİ ---
                if (siparis_gecerli == 1) {
                    int adet = 0, odenen = 0, toplam_odenen = 0;

                    system("cls");
                    printf("\n\n\t\t Kac adet %s istiyorsunuz?\n", secilen_urun);
                    printf("\t\t Adet giriniz: ");
                    scanf_s("%d", &adet);

                    if (adet <= 0) {
                        printf("\n\t\t Gecersiz adet girdiniz!");
                        _getch();
                        continue;
                    }

                    int borc = birim_fiyat * adet;
                    printf("\n\t\t Toplam odemeniz gereken tutar: %d TL\n", borc);

                    while (toplam_odenen < borc) {
                        if (toplam_odenen > 0) {
                            system("cls");
                            printf("\n\n\t\t ODEME MIKTARI YETERSIZ!\n");
                            printf("\t\t ----------------------------------\n");
                            printf("\t\t Toplam Tutar        : %d TL\n", borc);
                            printf("\t\t Su ana kadar odenen : %d TL\n", toplam_odenen);
                            printf("\t\t Kalan Borc          : %d TL\n", borc - toplam_odenen);
                            printf("\t\t ----------------------------------\n");
                        }

                        printf("\t\t Yatiracaginiz ucreti giriniz: ");
                        scanf_s("%d", &odenen);
                        toplam_odenen += odenen;
                    }

                    int para_ustu = toplam_odenen - borc;

                    system("cls");
                    system("color A0"); // Başarılı ödeme için yeşil arka plan
                    printf("\n\n\n\t\t\t %d adet %s siparisiniz onaylandi.\n", adet, secilen_urun);
                    printf("\t\t\t -----------------------------------------\n");
                    printf("\t\t\t Toplam Tutar  : %d TL\n", borc);
                    printf("\t\t\t Odenen Tutar  : %d TL\n", toplam_odenen);
                    if (para_ustu > 0) {
                        printf("\t\t\t Para Ustu     : %d TL\n", para_ustu);
                    }
                    printf("\t\t\t -----------------------------------------\n");
                    printf("\t\t\t AFIYET OLSUN. YINE BEKLERIZ!\n\n");
                    printf("\t\t\t (Menuye donmek icin herhangi bir tusa basin...)");
                    _getch();
                } else {
                    // Alt menüde 1-4 dışında yanlış tuşa basıldıysa
                    system("cls");
                    printf("\n\n\t\t Gecersiz secim yaptiniz!");
                    _getch();
                }
            }
        }
    }

    return 0;
}
