# Survival Simulator (Hayatta Kalma Simülatörü)

Bu proje, Algoritma ve Programlama dersi kapsamında C programlama dili kullanılarak geliştirilmiş metin tabanlı bir simülasyon oyunudur.

## 🎯 Proje Hakkında
Kullanıcı; sağlık, enerji ve açlık durumlarını yöneterek ıssız bir adada hayatta kalmaya çalışır. Proje, C dilindeki temel yapıların (döngüler, karar mekanizmaları, operatörler) işlevsel kullanımını göstermek amacıyla tasarlanmıştır.

## 🚀 Teknik Özellikler
Bu projede aşağıdaki teknik yapılar kullanılmıştır:
* **Durum Yönetimi:** "tursayısı", "sağlık", "enerji"  gibi değişkenlerin dinamik kontrolü.
* **Algoritmik Rastgelelik:** aritmetik operatörler kullanılarak geliştirilen özel şans formülü: "(enerji * 3 + saglik * 7 + turSayisi * 13) % 100"
* **Döngüler:** Oyun akışı için "do-while", savaş simülasyonu için "for" döngüleri.
* **Dinamik Menü:** Oyuncunun durumuna göre değişen akıllı yönlendirme sistemi (IF-ELSE).

## 🎮 Nasıl Oynanır? (Kontroller)

| Tuş | Komut | Açıklama |
| :--- | :--- | :--- |
| **A** | **Avlan** | Yemek bulma şansı (Enerji harcar). |
| **S** | **Sığınak** | Güvenli bölge inşa et (Fırtınadan korur). |
| **R** | **Dinlen** | Enerji ve sağlık yeniler. |
| **E** | **Envanter** | Durum kontrolü ve otomatik yemek yeme. |
| **F** | **Savaş** | 3 dalgalık tehlike simülasyonu başlatır. |
| **P** | **Keşif** | Şifreli sandık arar (Nested Loop içerir). |
| **X** | **Çıkış** | Oyunu sonlandırır. |
