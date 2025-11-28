#include <stdio.h>



int main(int argc, char *argv[]) {
	
	int turSayisi = 0;  // ihtimalleri yaratmak icin sans hesaplamada kullanilacak
	int i;
	
	int seviye = 1;
	int xp = 0;
	int xpSiniri = 50;
	
	int maxSaglik = 50;
	int maxEnerji = 50;
	
	int saglik = 50;
	int enerji = 50;
	int yemekSayisi = 0;
	int siginakDurumu = 0; // 0 -YOK, 1 -VAR
	int silahDurumu = 0;  // 0 -YOK, 1 -VAR (Avlanma bonusu)
	
	char komut;
	
	// GIRIS
	printf("\n======================================\n");
	printf("        HAYATTA KALMA SIMULATORU        \n");
	printf("\n======================================\n");
	printf("Issiz bir adadasin. Ucak kazasindan sag kurtuldun.\n");
	printf("Amacin: Hayatta kalmak ve guclenmek.\n\n");
	
	printf("Mevcut Kapasiten: %d Can | %d Enerji.\n", maxSaglik, maxEnerji);
	
	printf("HEDEF: Seviye atlayarak gucunu artir!\n\n");
	
	printf("----KOMUT LISTESI----\n\n");
	
	
	printf("[A] -> AVLAN : Yemek bul (Enerji harcar)\n");
	printf("[S] -> SIGINAK: Guvenli bir yer bul (Enerji harcar)\n");
	printf("[E] -> CANTA: Envanterini ve durumunu kontrol et / Yemek ye\n");
	printf("[R] -> DINLEN: Enerji ve Can yenile\n");
	printf("[F] -> SAVAS: Tehlike ile yuzles (XP Kazandirir)\n");
	printf("[P] -> KESIF: Sifreli sandik ara\n");
	printf("[X] -> CIKIS: Oyunu kapat\n");
	
	printf("----------------------------------------\n\n");
	
	printf("Maceraya basliyorsun... Ilk hamlen ne olacak?\n");
	printf("Oneri: [A] Avlan  veya  [P] Kesfet\n");
	
	printf("----------------------------------------\n");
	
	do {
		printf("\n\n");
		printf("\n======================================\n");
		turSayisi ++;
		
		// Seviye Atlama
		if (xp >= xpSiniri) {
			seviye ++;
			xp = 0;
			xpSiniri += 30;
			
			maxSaglik += 25;
			maxEnerji += 25;
			
			if (maxSaglik > 100) maxSaglik = 100;
			if (maxEnerji > 100) maxEnerji = 100;
			
			saglik = maxSaglik;
			enerji = maxEnerji;
			
			printf("\n*** TEBRIKLER! SEVIYE %d OLDUNUZ. ***\n", seviye);
			printf("Kapasiten artti! Yeni Max Can: %d | Yeni Enerji: %d\n", maxSaglik, maxEnerji);
			printf("\n======================================\n");
		}
		
		printf("[TUR: %d | SEVIYE: %d | XP: %d/%d]\n", turSayisi, seviye, xp, xpSiniri);
		printf("SAGLIK: %d/%d  |  ENERJI: %d/%d\n", saglik, maxSaglik, enerji, maxEnerji);
		printf("YEMEK : %d     |  SIGINAK: %s\n", yemekSayisi, siginakDurumu ? "VAR" : "YOK");
        printf("----------------------------------------\n");		
		
		if (enerji < 15){
			printf("(!) Enerji Kritik Seviyede.\n");
			printf(">>> ONERI: [R] tusuna basarak Dinlen.\n");
		}
		else if (saglik < 20) {
			printf("(!) Agir Yaralisin.\n");
			printf(">>> ONERI: [R] Dinlen veya [S] Siginaga git.\n");
		}
		else {
			if (turSayisi <= 3) {
				printf("Ne yapmak istersin? [A] Avlan, [F] Savas, [P] Kesfet...\n");
		}
	}
		printf("Kararin nedir? >> ");
		scanf(" %c", &komut);
		
		if(komut >= 'a' &&komut <= 'z') komut -=32; // Kucuk harfi buyuge cevirme
		
		int sansPuani = (enerji * 3 + saglik * 7 + turSayisi * 13) % 100; // Sans icin algoritma
		
		printf("\n>>> SONUC: ");
		
		switch (komut){
			
			// A - AVLAN
			case 'A':
				if (enerji >= 15) {
					enerji -= 15;
					
					int basariLimiti = (silahDurumu == 1) ? 70: 50; // Silah varsa sans artar
					
					if(sansPuani < basariLimiti){
						printf("AVLANMA BASARILI! (+1 Yemek, +20XP)\n");
						
						yemekSayisi ++;
						xp += 20;
					}
					else {
						printf("AVLANMA BASARISIZ!! Dusup yaralandin. (-5 Can, +5XP)\n");
						
						saglik -= 5;
						xp += 5;
					} 
					
					}else {
						printf("Yetersiz Enerji! Avlanamazsin. Once [R] ile dinlen.\n");
					}
					printf("(Istedigin zaman [X] ile cikabilirsin)\n");
					break;
					
					// S - SIGINAK
				case 'S':
					if (siginakDurumu == 1) {
						printf("Zaten bir siginagin var.\n");
					}
					else if (enerji > 30) {
						printf("Guvenli bir siginak buldun! (+40 XP)");
						enerji -= 20;
						siginakDurumu = 1;
						xp += 40;
					}
					else {
						printf("Siginak aramak icin yorgunsun. (Gereken Enerji: 30)\n");
					}
					break;
					
					// R - DINLEN
				case 'R':
					printf("Dinleniyorsun...\n");
					int bonus = (siginakDurumu == 1) ? 30: 15;  // Siginak varsa daha cok iyilesir
					enerji += bonus;
					saglik += 10;
					
					if(enerji > maxEnerji) enerji = maxEnerji;
					if (saglik >  maxSaglik) saglik = maxSaglik;
					
					printf("Enerji topladin. (+%d Enerji)\n", bonus);
					
					if (siginakDurumu == 1){
						int firtinaSansi = (turSayisi * 4 + enerji) % 100;
						
						if (firtinaSansi < 25) {
							printf("\n!!! GECE FIRTINA CIKTI !!!\n");
							printf("Sel basti, siginagini kaybettin.\n");
							printf("Baska bir siginak bulman gerekiyor.\n");
							siginakDurumu = 0;
						} else {
							printf("(Gece sakin gecti, hala siginagin saglam.)\n");
						}
					}
					
					break;
					
					// E - ENVANTER
				case 'E':
					printf("\n--- CANTA ICERIGI ---\n");
                    printf("   Yemek : %d Adet\n", yemekSayisi);				
					printf("   Silah : %s\n", silahDurumu ? "Yay ve Ok Var" : "Yok");
						
					if (yemekSayisi > 0 && saglik < maxSaglik) {
						printf("   -> AC VE YARALISIN: Otomatik olarak yemek yedin.\n");
						printf("   -> Saglik Yenilendi (+20 Can)\n");
						yemekSayisi --;
						saglik += 20;
						if(saglik > maxSaglik) saglik = maxSaglik;
					}
					else if (yemekSayisi == 0) {
						printf("   -> Cantan bos. Yemek bulmak icin [A] Avlan.\n");
					}
					else {
						printf("   -> Karnin tok, sagligin yerinde.\n");
					}
					break;
					
					// F - SAVAS 
				case 'F':
					printf("VAHSI HAYVAN SALDIRISI BASLADI!\n");
					for (i = 0; i < 4; i++) {
						printf("%d. Dalga!\n", i);
						
						int hasar = ((turSayisi + i * 7) % 10) + 5; // 5 - 15 arasi hasar
						
						if (siginakDurumu == 1) {
							hasar /= 2; // Siginak bonusu, hasarin yariya inmesini saglar
							printf("(Siginagin seni korudu.)\n");
							
							if ( (turSayisi + hasar) % 10 < 3) {
								printf("  !!! DIKKAT: Saldiri cok gucluydu, SIGINAK YIKILDI! !!!\n");
								siginakDurumu = 0;
							}
						}
						saglik -= hasar;
						printf("   %d. Dalga: -%d Hasar aldin! (Kalan Can: %d)\n", i, hasar, saglik);
						
						if (saglik <= 0) {
							break;
						}
					}
					if (saglik > 0) {
						printf("TEHLIKEYI ATLATTIN! (+35 XP)\n");
						xp += 35;
					}
					break;
					
					// P - KESIF / SIFRE
				case 'P':
					printf("\nKilitli Sandik Buldun!\n");
					int sifre = 8;
					int deneme;
					int kalanHak = 3;
					
					do{
						printf("Sifreyi giriniz (0-10 arasi)  (Hak: %d): ", kalanHak);
						scanf("%d", &deneme);
						
						if (deneme == sifre) {
							printf("   KILIT ACILDI!\n");
							
							int odulTuru = sansPuani % 3;
							
							if (odulTuru == 0) {
								printf("   -> Odul: ILK YARDIM KITI (+30 Can)\n");
								saglik += 30;
								if (saglik > maxSaglik) saglik = maxSaglik;
							}
							else if(odulTuru == 1) {
							
							printf("   -> Odul: KONSERVE YEMEK (+3 Yemek)\n");
							yemekSayisi += 3;
						}
								else {
									printf("   -> Odul: YAY VE OK (Avlanma sansi artti)\n");
									silahDurumu = 1;
								}
								xp +=15;
								break;
							}
							else{
								printf("Yanlis sifre! Tekrar dene\n");
								kalanHak --;
								enerji -=5;
							}
						} while (kalanHak > 0 && enerji > 0);
						
						if(kalanHak == 0) printf("Sandik acilamadi.\n");
						break;
						
						//CIKIS
					case 'X':
						printf("Oyundan cikiliyor...\n");
						break;
						
						default:
							printf("Gecersiz Komut! Tekrar dene.\n");
					}
					
					if(saglik <= 0 && komut != 'X') {
						printf("\n\n***************************************\n");
						printf("      OYUN BITTI - HAYATTA KALAMADIN     \n");
						printf("***************************************\n");
						komut = 'X';
					}
				}
					while (komut != 'X');
	
	return 0;
}
