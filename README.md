\# Sanal Kafe Otomasyonu (C Console App)



C dili kullanılarak geliştirilmiş, konsol tabanlı bir kafe sipariş ve ödeme simülasyonu.



\## Özellikler

\* \*\*Kategori ve Ürün Seçimi:\*\* Türk Kahvesi, Espresso, Mocha, Sıcak Çikolata gibi alt menüler ve ürün seçenekleri.

\* \*\*Dinamik Ödeme Sistemi:\*\* Seçilen ürün ve adede göre toplam tutar hesaplama, eksik bakiye durumunda ödeme tamamlanana kadar ek ücret isteme ve para üstü hesaplama.

\* \*\*Navigasyon ve Kontrol:\*\* `\\\_getch()` ile anlık tuş algılama ve herhangi bir menüde `ESC` tuşu ile çıkış veya ana ekrana dönüş kontrolü.



\## Kurulum ve Çalıştırma

Kod Windows konsol kütüphanelerini (`conio.h` ve `system("cls")`) kullandığı için Windows ortamında derlenmelidir:



```bash

gcc sanal\\\_kafe.c -o sanal\\\_kafe.exe

sanal\\\_kafe.exe


