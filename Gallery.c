#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARAC_SAYISI 100
#define KAYIT_SAYISI 100

typedef struct
{
    char marka[20];
    char model[10];
    int yil;
    char yakit[10];
    char vites[15];
    int km;
}aracBilgileri;

typedef enum
{
    calisan = 1 , musteri = 2
}yetkiDurumu;

typedef struct
{
    char isim[20];
    char soyisim[20];
    int id;
    int sifre;
    yetkiDurumu yetki;
}kayitBilgileri;

//////////////////////////////////////////////// GİRİŞ YAP ///////////////////////////////////////////////////////

int giris_yap(kayitBilgileri *kayitListesi)
{
    int giris_id,giris_sifre;
    int i=0;
    printf("Lutfen ID'nizi giriniz : ");
    fflush(stdin);
    scanf("%d",&giris_id);

    while(i<KAYIT_SAYISI )
    {
        if(kayitListesi[i].id == giris_id)
        {
            printf("Lutfen sifrenizi giriniz : ");
            fflush(stdin);
            scanf("%d",&giris_sifre);

            if(kayitListesi[i].sifre == giris_sifre)
            {
                printf("\nGiris basarili!");
                return kayitListesi[i].yetki;
            }
            else
            {
                printf("\nYanlis sifre girdiniz\nGiris basarisiz!\n");
                return -1;
            }
        }
        i++;
    }
    return -1;
}

//////////////////////////////////////////////////////// KAYIT OL /////////////////////////////////////////////////////////////

void kayit_ol(kayitBilgileri *kayitListesi)
{
    int i=0,j=0;
    int kayit_id;
    char yetki_secim;

    while(i<KAYIT_SAYISI)
    {
        if(kayitListesi[i].id==0)
        {
            break;
        }
        i++;
    }

    if(i!=KAYIT_SAYISI)
    {
        printf("Lutfen isminizi ve soyisminizi giriniz : ");
        fflush(stdin);
        scanf("%s %s",kayitListesi[i].isim,kayitListesi[i].soyisim);
        printf("Lutfen ID'nizi giriniz : ");
        fflush(stdin);
        scanf("%d",&kayit_id);

        while(j<KAYIT_SAYISI)
        {
            if(kayitListesi[j].id==kayit_id)
            {
                printf("Bu ID baskasi tarafından kullanilmaktadir!");
                break;
            }
            j++;
        }
        if(j==KAYIT_SAYISI)
        {
            kayitListesi[i].id=kayit_id;
            printf("Lutfen sifrenizi giriniz : ");
            scanf("%d",&kayitListesi[i].sifre);
            printf("Kayit basarili!!");

            printf("Lutfen Calisansaniz 'C'yi , Musteri iseniz 'M'yi tuslayiniz : " );
            fflush(stdin);
            scanf("%c",&yetki_secim);

            switch(yetki_secim)
            {
                case 'C':
                case 'c': kayitListesi[i].yetki =1; break;
                case 'M':
                case 'm': kayitListesi[i].yetki = 2; break;
                default : printf("Yanlis bir tuslama yaptiniz!");
            }
        }
    }
    else
    {
        printf("Liste tamamen dolu!");
    }
}

////////////////////////////////////////////// ARAÇ EKLE ////////////////////////////////////////////////////////

void arac_ekle(aracBilgileri *aracListesi)
{
    int i=0;

    while(i<ARAC_SAYISI)
    {
        if(aracListesi[i].yil==0)
        {
            break;
        }
        i++;
    }

    if(i!=ARAC_SAYISI)
    {
        printf("Lutfen aracin markasini giriniz : ");
         fflush(stdin);
        scanf("%s",aracListesi[i].marka);
        printf("Lutfen aracin modelini giriniz : ");
         fflush(stdin);
        scanf("%s",aracListesi[i].model);
        printf("Lutfen aracin uretim yilini giriniz : ");
         fflush(stdin);
        scanf("%d",&aracListesi[i].yil);
        printf("Lutfen aracin yakit turunu giriniz : ");
        scanf("%s",aracListesi[i].yakit);
        printf("Lutfen aracin vites turunu giriniz : ");
        scanf("%s",aracListesi[i].vites);
        printf("Lutfen aracin km'sini giriniz : ");
        scanf("%d",&aracListesi[i].km);
    }
    else
    {
        printf("Arac listesi tamamen dolu!");
    }
}

///////////////////////////////////////////////// ARAÇ SİL ////////////////////////////////////

void arac_sil(aracBilgileri *aracListesi)
{
    int i=0;
    char sil_marka[20];
    char sil_model[20];
    int sil_km;
    printf("Lutfen silmek istediginiz aracin sirasiyla marka,model ve km bilgisini giriniz : ");
    fflush(stdin);
    scanf("%s %s %d",sil_marka,sil_model,&sil_km);

    while(i<ARAC_SAYISI)
    {
        if(strcmp(aracListesi[i].marka,sil_marka)==0)
        {
            if(strcmp(sil_model,aracListesi[i].model)==0 && sil_km == aracListesi[i].km)
            {
                aracListesi[i].yil=0;
                printf("Arac basari ile silindi!");
                break;
            }
        }
        i++;
    }
}

/////////////////////////////////////////////////////// MUSTERI GÖRÜNTÜLE ///////////////////////////////////////////////////

void musteri_goruntule(kayitBilgileri *kayitListesi)
{
    int i=0;

    while(i<KAYIT_SAYISI)
    {
        if(kayitListesi[i].yetki == 2)
        {
            printf("---------------------------------------------\n");
            printf("ISIM-SOYISIM : %s %s\n",kayitListesi[i].isim,kayitListesi[i].soyisim);
            printf("ID: %d\n",kayitListesi[i].id);
            printf("---------------------------------------------\n");
        }
        i++;
    }
}

/////////////////////////////////////////////////////////// ARAÇLARI GÖRÜNTÜLE //////////////////////////////////////////////////

void arac_goruntule(aracBilgileri *aracListesi)
{
    int i=0;
    while(i<ARAC_SAYISI)
    {
        if(aracListesi[i].yil!=0)
        {
            printf("---------------------------------------------\n");
            printf("MARKA : %s\n",aracListesi[i].marka);
            printf("MODEL : %s\n",aracListesi[i].model);
            printf("URETIM YILI : %d\n",aracListesi[i].yil);
            printf("YAKIT TURU : %s\n",aracListesi[i].yakit);
            printf("VITES TURU : %s\n",aracListesi[i].vites);
            printf("KM : %d\n",aracListesi[i].km);
             printf("---------------------------------------------\n");
        }
        i++;
    }
}

//////////////////////////////////////////////////////////  ARAÇ ARA /////////////////////////////////////////////

void arac_ara(aracBilgileri *aracListesi)
{
    int i=0;
    char ara_marka[20];
    char ara_model[20];
    int ara_yil;
    printf("Lutfen aramak istediginiz aracin sirasiyla marka,model ve yil bilgisini giriniz : ");
    fflush(stdin);
    scanf("%s %s %d",ara_marka,ara_model,&ara_yil);

    while(i<ARAC_SAYISI)
    {
        if(strcmp(aracListesi[i].marka,ara_marka)==0)
        {
            if(strcmp(ara_model,aracListesi[i].model)==0 && ara_yil == aracListesi[i].yil)
            {
                printf("---------------------------------------------\n");
                printf("MARKA : %s\n",aracListesi[i].marka);
                printf("MODEL : %s\n",aracListesi[i].model);
                printf("URETIM YILI : %d\n",aracListesi[i].yil);
                printf("YAKIT TURU : %s\n",aracListesi[i].yakit);
                printf("VITES TURU : %s\n",aracListesi[i].vites);
                printf("KM : %d\n",aracListesi[i].km);
                printf("---------------------------------------------\n");
            }
        }
        i++;
    }
}

/////////////////////////////////////////////////////// ARAÇ BİLGİSİ KAYDET ////////////////////////////////////////////

void arac_bilgi_kaydet(aracBilgileri *aracListesi)
{
    FILE *arac_bilgi = fopen("aracListesi.txt","w");
    int i=0;

    while(i<ARAC_SAYISI)
    {
        if(aracListesi[i].yil!=0)
        {
            fprintf(arac_bilgi,"MARKA : %s\nMODEL : %s\nURETIM YILI : %d\nYAKIT TURU : %s\nVITES TURU : %s\nKM : %d\n\n",aracListesi[i].marka,aracListesi[i].model,aracListesi[i].yil,aracListesi[i].yakit,aracListesi[i].vites,aracListesi[i].km);
        }
        i++;
    }
    fclose(arac_bilgi);
}

/////////////////////////////////////////////// KAYIT BİLGİSİ KAYDET //////////////////////////////////////////////////////////

void kayit_bilgi_kaydet(kayitBilgileri *kayitListesi)
{
    FILE *kayit_bilgi = fopen("kayitListesi.txt","w");

    int i=0;

    while(i<KAYIT_SAYISI)
    {
        if(kayitListesi[i].id!=0)
        {
            fprintf(kayit_bilgi,"ISIM-SOYISIM : %s %s\nID : %d\nSIFRE : %d\nYETKI : %d\n\n",kayitListesi[i].isim,kayitListesi[i].soyisim,kayitListesi[i].id,kayitListesi[i].sifre,kayitListesi[i].yetki);
        }
        i++;
    }

    fclose(kayit_bilgi);

}

///////////////////////////////////////////////////// ARAÇ BİLGİ OKUMA ///////////////////////////////////////////////////

void arac_bilgi_okuma(aracBilgileri  *aracListesi)
{
    int i=0;
    FILE *arac_bilgi = fopen("aracListesi.txt","r");

    while(i<ARAC_SAYISI && !feof(arac_bilgi))
    {
        if(aracListesi[i].yil==0)
        {
            fscanf(arac_bilgi,"MARKA : %s\nMODEL : %s\nURETIM YILI : %d\nYAKIT TURU : %s\nVITES TURU : %s\nKM : %d\n\n",aracListesi[i].marka,aracListesi[i].model,&aracListesi[i].yil,aracListesi[i].yakit,aracListesi[i].vites,&aracListesi[i].km);
        }
        i++;
    }
    fclose(arac_bilgi);
}

///////////////////////////////////////////////////////////////// KAYIT BİLGİ OKUMA /////////////////////////////////////////////////////////////////

void kayit_bilgi_okuma(kayitBilgileri *kayitListesi)
{
    FILE *kayit_bilgi = fopen("kayitListesi.txt","r");

    int i=0;

    while(i<KAYIT_SAYISI && !feof(kayit_bilgi))
    {
        if(kayitListesi[i].id==0)
        {
            fscanf(kayit_bilgi,"ISIM-SOYISIM : %s %s\nID : %d\nSIFRE : %d\nYETKI : %d\n\n",kayitListesi[i].isim,kayitListesi[i].soyisim,&kayitListesi[i].id,&kayitListesi[i].sifre,&kayitListesi[i].yetki);
        }
        i++;
    }

    fclose(kayit_bilgi);
}

int main()
{
    kayitBilgileri *kayitListesi = (kayitBilgileri*)calloc(sizeof(kayitBilgileri),KAYIT_SAYISI);
    aracBilgileri *aracListesi = (aracBilgileri*)calloc(sizeof(aracBilgileri),ARAC_SAYISI);

    arac_bilgi_okuma(aracListesi);
    kayit_bilgi_okuma(kayitListesi);

    int islem,yetki,secim;

        printf("********************* GALERI SISTEMINE HOS GELDINIZ! *************************\n\n");

    do
    {
        printf("\n1-GIRIS YAP\n2-KAYIT OL\n3-CIKIS\n");
        printf("Lutfen yapmak istediginiz islemi seciniz : ");
        scanf("%d",&islem);

        switch(islem)
        {
            case 1: yetki = giris_yap(kayitListesi);

                    if(yetki==calisan)
                    {
                        do
                        {
                            printf("\n1- ARAC EKLE\n2- ARAC SIL\n3- MUSTERILERI GORUNTULE\n4- CIKIS\n\n");
                            printf("Lutfen yapmak istediginiz islemi seciniz : ");
                            scanf("%d",&secim);

                            switch(secim)
                            {
                                case 1 : arac_ekle(aracListesi); break;
                                case 2 : arac_sil (aracListesi); break;
                                case 3 : musteri_goruntule(kayitListesi); break;
                                case 4 : arac_bilgi_kaydet(aracListesi);
                                              kayit_bilgi_kaydet(kayitListesi); break;
                                default : printf("Yanlis bir tuslama yaptiniz!");
                            }
                        }while(secim!=4);
                    }
                else if(yetki == musteri)
                {
                    do
                    {
                        printf("\n1-ARACLARI GORUNTULE\n2-ARAC ARA\n3- CIKIS\n\n");
                        printf("Lutfen yapmak istediginiz islemi giriniz : ");
                        scanf("%d",&secim);

                        switch(secim)
                        {
                            case 1: arac_goruntule(aracListesi); break;
                            case 2: arac_ara(aracListesi); break;
                            case 3: arac_bilgi_kaydet(aracListesi);
                                        kayit_bilgi_kaydet(kayitListesi); break;
                            default : printf("Yanlis bir tuslama yaptiniz!");
                        }
                    }while(secim!=3);
                } break;

            case 2: kayit_ol(kayitListesi);break;
            case 3: printf("Cikis yapildi!"); break;
            default : printf("Yanlis tuslama yaptiniz!");
        }
    }while(islem!=3);

    free(kayitListesi);
    free(aracListesi);
    return 0;
}
