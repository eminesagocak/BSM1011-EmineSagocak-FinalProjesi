#include <stdio.h>
#include <string.h>

void printScreen(int n, int SiparisSayisi[100][6], char Musteri[100][2][10]);
void tabani(int Taban);

int main()
{
    // Waffle sipariş sistemi.
    // Ödenecek ücret standart ve 50 tldir.
    // Ürünü oluşturan malzemeler;
    // Taban, TabanSos, Meyve, Sekerleme, TozAroma, UstSos.
    
    int n; // sipariş sayısı
    int SiparisSayisi[100][6];//max 100 sipariş alınabilecek bellekte tutmak için matrixden yararlanıldı.
    char Musteri[100][2][10];//müşteri bilgileri için matrix ve char kullanıldı.

    printf("Kaç adet waffle siparişi vereceksiniz? \n");
    scanf("%d", &n);
    printf("sipariş sayımız %d \n\n", n);
    int Taban = 0, TabanSos = 0, Meyve = 0, Sekerleme = 0, TozAroma = 0, UstSos = 0;
    char name[10];
    char surname[10];

    for (int i = 0; i < n; i++)
    {   //toplu sipariş durumunda müşteri sahiplerinin servislerinin karışmaması için her servise farklı isim vermek amacıyla isim de döngüye alındı.
        printf("Adınızı giriniz. ");
        scanf("%s", &name);
        printf("Soyadınızı giriniz. ");
        scanf("%s", &surname);

        printf("\t%d. siparişiniz için taban tek ise 1'i, çift ise 2'yi tuşlatınız\n yanlış veya farklı tuşlamada tek taban seçilecektir.\n ", i + 1);
        scanf("%d", &Taban);
        printf("\tTaban sosunuzda bitter için 1'i sütlü için 2'yi istemiyorum için 3'ü tuşlayınız.\n  ");
        scanf("%d", &TabanSos);
        printf("\tMeyve seçiminiz için tuşlama yapın.\n 1=Muz\n 2=Çilek\n 3=Kivi\n 4=istemiyorum\n ");
        scanf("%d", &Meyve);
        printf("\tŞekerleme seçiminde bonibon için 1, çakıl taşı için 2 yi istemiyorum için 3 tuşlayınız.\n ");
        scanf("%d", &Sekerleme);
        printf("\tToz aroma olarak fıstık için 1, fındık için 2 istemiyorum için 3 tuşlayınız.\n  ");
        scanf("%d", &TozAroma);
        printf("\tServis sosu olarak karamel için 1, çikolata için 2, istemiyorum için 3 tuşlayınız.\n  ");
        scanf("%d", &UstSos);

        printf("\n\n");

        SiparisSayisi[i][0] = Taban;
        SiparisSayisi[i][1] = TabanSos;
        SiparisSayisi[i][2] = Meyve;
        SiparisSayisi[i][3] = Sekerleme;
        SiparisSayisi[i][4] = TozAroma;
        SiparisSayisi[i][5] = UstSos;
        strcpy(Musteri[i][0], name);
        strcpy(Musteri[i][1], surname);
    }

    printScreen(n, SiparisSayisi, Musteri);//fonksiyon kullanımı ile görsel okuma kolaylığı amaçlandı.

    return 0;
}

void printScreen(int n, int SiparisSayisi[100][6], char Musteri[100][2][10])
{
    for (int i = 0; i < n; i++)
    {   
        printf("%s %s, adlı müşteri.\n", Musteri[i][0], Musteri[i][1]);
        
        printf("\t");
        tabanbilgileriniyazdir(SiparisSayisi[i][0]);
        printf("\n");
        printf("\t");
        tabansosubilgileriniyazdir( SiparisSayisi[i][1]);
        printf("\n");
        printf("\t");
        meyvebilgileriniyazdir(SiparisSayisi[i][2]);
        printf("\n");
        printf("\t");
        sekerlemebilgileriniyazdir(SiparisSayisi[i][3]);
        printf("\n");
        printf("\t");
        aromabilgileriniyazdir(SiparisSayisi[i][4]);
        printf("\n");
        printf("\t");
        ustsosbilgileriniyazdir(SiparisSayisi[i][5]);
        printf("\n");
        printf("\t");
        printf("Waffle siparişi vermiştir. Ödenecek ücret 50 tl'dir.");
        printf("\n");

    }
}

void tabanbilgileriniyazdir(int Taban)
{
    if (Taban == 2)
    {
        printf("çift tabanlı");
    }
    else
    {
        printf("tek tabanlı");
    }
}

void tabansosubilgileriniyazdir(int TabanSos)
{
    if (TabanSos == 1)
     {
       printf("Bitter soslu") ;
    }
else if (TabanSos == 2)
    {
       printf ("Çikolata soslu");
     }
     else
    {
       printf ("Sossuz");
    }
}

void meyvebilgileriniyazdir(int Meyve) {
    if (Meyve==1) {
         printf ("Muzlu");
    }
     else if (Meyve==2) {
         printf ("Çilekli");
    }
     else if(Meyve==3){
        printf("Kivili");
     }
     else{
        printf("Meyvesiz");
     }
}

 void sekerlemebilgileriniyazdir(int Sekerleme) {
    if (Sekerleme==1) {
         printf ("Bonibon şekerlemeli");
    }
    else if (Sekerleme==2) {
         printf ("Çakıltaşı şekerlemeli");
    }
    else{
        printf("Şekerlemesiz");
     }
 }

 void aromabilgileriniyazdir(int TozAroma) {
    if (TozAroma==1) {
       printf ("Fıstıklı");
    }
     else if (TozAroma==2) {
       printf ("Fındıklı");
    }
     else{
       printf ("Toz aromasız");
     }
 }

 void ustsosbilgileriniyazdir(int UstSos) {
    if (UstSos==1) {
       printf  ("Bitter süslemeli");
    }
     else if (UstSos==2) {
        printf  ("Sütlü çikolata süslemeli");
    }
     else{
       printf  ("Sos süzlemesiz");
     }
 }