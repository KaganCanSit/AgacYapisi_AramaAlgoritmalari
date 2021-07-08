#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

//Düğüm Yapısı
struct ogrenci_dugum
{
	char ogrno[20];
	char ad[20];
	char soyad[20];
	ogrenci_dugum* sag;
	ogrenci_dugum* sol;
};

//Yapılacak İşlemler İçin Kullanılacak Olan Fonksiyon Yapısı
struct Islemler
{
	ogrenci_dugum* data1_kok;
	ogrenci_dugum* data2_kok;
	ogrenci_dugum* data3_kok;
	void AnaMenu();
	void AgacBaslangic();
	void DosyadanOku(string);
	void AgacKur(ogrenci_dugum*, int);
	void Listele(int);
	void PreorderListele(ogrenci_dugum* p);
	void InorderListele(ogrenci_dugum* p);
	void PostorderListele(ogrenci_dugum* p);
	void Sil(char*, int);
	void SilDugum(ogrenci_dugum**);
	void DosyayaYaz(int, int);
	void PreorderYaz(ogrenci_dugum* p);
	void InorderYaz(ogrenci_dugum* p);
	void PostorderYaz(ogrenci_dugum* p);
	void IlkDerinlikAra(int);
	void IlkGenislikAra(int);
};
int ListeSec();
int YazdirmaTuruSec();
int AramaTuruSec();
void EkraniTemizle();
void Cikis();

//Fonksiyonları ve Kök Düğümleri Tüm Alanda Kullanabilmek İçin İşlemler Yapısından Nesne Oluşturuyoruz
Islemler* islem = new Islemler();

//Ana Main Fonksiyonu
int main(void)
{
	islem->AgacBaslangic();
	islem->AnaMenu();
}

//İşlem Yapacağımız Listelerin Seçimi İçin Hazırladığımız Fonksiyon
int ListeSec()
{
	int secim;
	cout << "\nIsleminizi Gerceklestirmek Istediginiz Listeyi Seciniz: " << endl;
	cout << "data1.txt icin: 1" << endl;
	cout << "data2.txt icin: 2" << endl;
	cout << "data3.txt icin: 3" << endl;
	cin >> secim;

	if (secim < 1 || secim>3)
	{
		cout << "Hatali Deger Girdiniz." << endl;
		Cikis();
	}
	return secim;
}

//Dosyaya Yazdırma Sırasında Hangi Dosyayi Yeniden Yazacağımızı Seçtikten Sonra Dosyanın Hangi Yöntem İle Yazdirilacagini Seçerek İşlemi Tamamlıyoruz.
int YazdirmaTuruSec()
{
	int secim;
	cout << "\nAgac Yapinizi Hangi Yontem Ile Yazmak Istiyorsunuz?" << endl;
	cout << "Preorder Yazdirmak Icin: 1" << endl;
	cout << "Inorder Yazdirmak Icin: 2" << endl;
	cout << "Postorder Yazdirmak Icin: 3" << endl;
	cin >> secim;

	if (secim < 1 || secim>3)
	{
		cout << "Hatali Deger Girdiniz." << endl;
		Cikis();
	}

	return secim;
}

//Arama Yapma İşlemi Altında Nasıl Arama Yapacağı Bilgisini Kullanıcıdan Alıyoruz.
int AramaTuruSec()
{
	int secim;
	cout << "\nArama Yapma Turunuzu Seciniz: " << endl;
	cout << "Ilk Derinlik Oncelikli Arama: 1" << endl;
	cout << "Ilk Genislik Arama: 2" << endl;
	cin >> secim;

	if (secim < 1 || secim>2)
	{
		cout << "Hatali Deger Girdiniz." << endl;
		Cikis();
	}

	return secim;
}

//Çıkış Fonksiyonu
void Cikis()
{
	cout << "Cikis Yapiliyor";
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		Sleep(500);
		cout << ".";
		Sleep(500);
	}
	system("cls");
	exit(1);
}

//Her İşlemden Sonra Ekranın Temizliği İçin Kullandığımız Fonksiyon
void EkraniTemizle()
{
	cout << "Baska Islem Yapabilmeniz Icin 10 Saniyenin Ardindan Menuye Yonlendiriliceksiniz." << endl;
	Sleep(10000);
	system("cls");
}

//Ana İşlem Menüsü
void Islemler::AnaMenu()
{
	int listesecim = 0, aramaturusecim = 0;
	char secim, silinecekogrno[20];

yeniden:
	cout << "Arama Yapmak Icin: A" << endl;
	cout << "Listeyi Ekrana Yazdirmak Icin: L" << endl;
	cout << "Ogrenci Silmek Icin: S" << endl;
	cout << "Dosyaya Yazmak Icin: Y" << endl;
	cout << "Cikis Icin: C" << endl;
	cout << "Preorder Listeleme Yapmak Icin: R" << endl;
	cout << "Inorder Listeleme Yapmak Icin: U" << endl;
	cout << "Postorder Listeleme Yapmak Icin: O" << endl;

	cout << "Yukarida Listelenen Islemlerden Yapmak Istediginiz Islemi Seciniz: ";
	cin >> secim;

	//Her Aşamada Liste Seçimi Fonk. Yazmak Yerine Başa Yazıyoruz. Fakat Çıkış Fonksiyonu Bu Seçimin Dışında Kalması Gerektiği İçin İlk Kontrolü "c" Harfine Gerçekleştiriyoruz.
	if (secim == 'c' || secim == 'C')
		Cikis();

	listesecim = ListeSec();

	switch (secim)
	{
	case 'A': case 'a':
	{
		aramaturusecim = AramaTuruSec();

		if (aramaturusecim == 1)
			IlkDerinlikAra(listesecim);
		else if (aramaturusecim == 2)
			IlkGenislikAra(listesecim);
		else
			cout << "\nYanlis Deger Girdiniz." << endl;

		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'L': case 'l':
	{
		Listele(listesecim);
		cout << "\nListeleme Tamamlandi.";
		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'S': case 's':
	{
		cout << "Silmek Istediginiz Ogrencinin Numarisini Giriniz:";
		cin >> silinecekogrno;
		Sil(silinecekogrno, listesecim);
		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'Y': case 'y':
	{
		DosyayaYaz(listesecim, YazdirmaTuruSec());
		cout << "\nDosya Yazdirildi. " << endl;
		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'R': case 'r':
	{
		if (listesecim == 1)
		{
			PreorderListele(data1_kok);
			cout << "\ndata1.txt Preorder Olarak Listelendi. " << endl;
		}
		else if (listesecim == 2)
		{
			PreorderListele(data2_kok);
			cout << "\ndata2.txt Preorder Olarak Listelendi. " << endl;
		}
		else
		{
			PreorderListele(data3_kok);
			cout << "\ndata3.txt Preorder Olarak Listelendi. " << endl;
		}
		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'U': case 'u':
	{
		if (listesecim == 1)
		{
			InorderListele(data1_kok);
			cout << "\ndata1.txt Inorder Olarak Listelendi. " << endl;
		}
		else if (listesecim == 2)
		{
			InorderListele(data2_kok);
			cout << "\ndata2.txt Inorder Olarak Listelendi. " << endl;
		}
		else
		{
			InorderListele(data3_kok);
			cout << "\ndata3.txt Inorder Olarak Listelendi. " << endl;
		}
		EkraniTemizle();
		goto yeniden;
		break;
	}
	case 'O': case 'o':
	{
		if (listesecim == 1)
		{
			PostorderListele(data1_kok);
			cout << "\ndata1.txt Postorder Olarak Listelendi. " << endl;
		}
		else if (listesecim == 2)
		{
			PostorderListele(data2_kok);
			cout << "\ndata2.txt Postorder Olarak Listelendi. " << endl;
		}
		else
		{
			PostorderListele(data3_kok);
			cout << "\ndata3.txt Postorder Olarak Listelendi. " << endl;
		}
		EkraniTemizle();
		goto yeniden;
		break;
	}
	default:
	{
		system("cls");
		cout << "Hatali Harf Girdiniz. Yeniden Deneyiniz.\n" << endl;
		EkraniTemizle();
		goto yeniden;
	}
	}
}

//Listele Komutu Yardımıyla Dosyanın İlk Halini Ekrana Yazdırıyoruz. Bu İşlem İçin Dosya Seçimini Parametre Olarak Kullanıcıdan Alıyoruz.
void Islemler::Listele(int dosyasecim)
{

	ogrenci_dugum* bilgi;
	string dosyaadi, satir;

	if (dosyasecim == 1)
	{
		bilgi = data1_kok;
		dosyaadi = "data1.txt";
	}
	else if (dosyasecim == 2)
	{
		bilgi = data2_kok;
		dosyaadi = "data2.txt";
	}
	else
	{
		bilgi = data3_kok;
		dosyaadi = "data3.txt";
	}

	cout << "\nListenizi Dosya Icerisinde Bulundugu Sekli;" << endl;
	ifstream DosyadanOku(dosyaadi);
	if (DosyadanOku.is_open()) {

		while (getline(DosyadanOku, satir))
		{
			cout << satir << endl;
		}
		DosyadanOku.close();
	}
	else
		cout << "Dosya Acilamadi. Yeniden Deneyiniz.";

	cout << "\n\nListenizin Preorder Yonteme Gore Guncel Hali: " << endl;
	cout << "Agac Yapısı Icerisinde Degisiklige Ugramis Olabilir. (*Silme Islemi Uygulanmis Olabilir.)" << endl;
	PreorderListele(bilgi);
}


//Ağaç Yapısının Kök Düğümlerini Oluşturarak İlk Adres Değerlerini Atıyoruz. Oluşturacağımız Ağaç Yapıları İçin Okunacak Dosyaları "DosyadanOku" Fonksiyonuna Sıralı Olarak Parametre Gönderiyoruz.
void Islemler::AgacBaslangic()
{
	data1_kok = NULL;
	data2_kok = NULL;
	data3_kok = NULL;

	DosyadanOku("data1.txt");
	DosyadanOku("data2.txt");
	DosyadanOku("data3.txt");
}

//Parametre Olarak Aldığımız Dosya İsmine Göre Verileri Okuyarak, Atanması İçin Ağaç Yapısı Kurma Fonksiyonumaza Parametre Olarak Gönderiyoruz.
void Islemler::DosyadanOku(string dosyaismi)
{
	char ogrno[15], ad[30], soyad[30], satirAl[75];
	char* ptr;
	ogrenci_dugum* yeni;

	ifstream dosya1(dosyaismi);
	if (!dosya1)
	{
		cout << "\nDosyayi Bulamadik Veya Acamiyoruz. Islem Dosyasini Kontrol Ediniz." << endl;
		Cikis();
	}
	dosya1.getline(satirAl, 75);
	for (int i = 0; i < 75; i++)
	{
		if (satirAl[i] == '\r')
			satirAl[i] = '\0';
	}
	while (dosya1)
	{
		ptr = strtok(satirAl, "\t");
		int j = 0;
		while (ptr != NULL)
		{
			if (j == 0)
				strcpy(ogrno, ptr);
			if (j == 1)
				strcpy(ad, ptr);
			if (j == 2)
				strcpy(soyad, ptr);
			if (j == 3)
			{
				strcat(ad, " ");
				strcat(ad, soyad);
				strcpy(soyad, ptr);
			}
			ptr = strtok(NULL, " ");
			j++;
		}
		dosya1.getline(satirAl, 75);
		for (int i = 0; i < 75; i++)
		{
			if (satirAl[i] == '\r')
				satirAl[i] = '\0';
		}

		yeni = new ogrenci_dugum;
		strcpy(yeni->ogrno, ogrno);
		strcpy(yeni->ad, ad);
		strcpy(yeni->soyad, soyad);

		if (dosyaismi == "data1.txt")
			AgacKur(yeni, 1);
		else if (dosyaismi == "data2.txt")
			AgacKur(yeni, 2);
		else
			AgacKur(yeni, 3);
	}
	dosya1.close();
}

//Parametre Olarak Almış Olduğumuz Dosya Verilerini Uygun Şekilde Ağaç Yapısı İçerisine Yerleştiriyoruz.
void Islemler::AgacKur(ogrenci_dugum* eklenecek, int koksecimi)
{
	ogrenci_dugum* tara, * yeni;
	int karsilas;
	bool eklendi = false;
	yeni = new ogrenci_dugum;
	strcpy(yeni->ogrno, eklenecek->ogrno);
	strcpy(yeni->ad, eklenecek->ad);
	strcpy(yeni->soyad, eklenecek->soyad);
	yeni->sol = NULL;
	yeni->sag = NULL;

	if (koksecimi == 1)
	{
		tara = data1_kok;
		if (data1_kok == NULL)
		{
			data1_kok = yeni;
			return;
		}
	}
	else if (koksecimi == 2)
	{
		tara = data2_kok;
		if (data2_kok == NULL)
		{
			data2_kok = yeni;
			return;
		}
	}
	else
	{
		tara = data3_kok;
		if (data3_kok == NULL)
		{
			data3_kok = yeni;
			return;
		}
	}

	while ((tara != NULL) && (!eklendi))
	{
		karsilas = strcmp(yeni->ogrno, tara->ogrno);	// < 0 ise str1 bellek içeriği str2 bellek içeriğinden küçüktür.
		if (karsilas < 0)								// > 0 ise str2 bellek içeriği str1 bellek içeriğinden küçüktür.
		{												// = 0 ise str1 bellek içeriği str2 bellek içeriğine eşittir.
			if (tara->sol != NULL)
				tara = tara->sol;
			else
			{
				tara->sol = yeni;
				eklendi = true;
			}
		}
		else if (karsilas > 0)
		{
			if (tara->sag != NULL)
				tara = tara->sag;
			else
			{
				tara->sag = yeni;
				eklendi = true;
			}
		}
		else
			cout << "Veri tekrari olamaz \n";
	}
}

//Preorder - Inorder - Postorder Ağaçların Yazdırılması
void Islemler::PreorderListele(ogrenci_dugum* p)
{
	if (p)
	{
		cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		PreorderListele(p->sol);
		PreorderListele(p->sag);
	}
}
void Islemler::InorderListele(ogrenci_dugum* p)
{
	if (p)
	{
		InorderListele(p->sol);
		cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		InorderListele(p->sag);
	}
}
void Islemler::PostorderListele(ogrenci_dugum* p)
{
	if (p)
	{
		PostorderListele(p->sol);
		PostorderListele(p->sag);
		cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
	}
}

//Silinecek Öğrenci No'yu Ara, Bulunduğunda İse Var Olduğu Şartlara Göre Sil.
void Islemler::Sil(char* silinecekogrno, int koksecimi)
{
	ogrenci_dugum* tara, * ust;
	ust = NULL;
	bool bulundu = false;
	char yon = 'k';

	if (koksecimi == 1)
		tara = data1_kok;
	else if (koksecimi == 2)
		tara = data2_kok;
	else
		tara = data3_kok;

	while (tara && !bulundu)
	{
		int karsilas = strcmp(silinecekogrno, tara->ogrno);
		if (karsilas < 0)
		{
			ust = tara;
			yon = 'l';
			tara = tara->sol;
		}
		else if (karsilas > 0)
		{
			ust = tara;
			yon = 'r';
			tara = tara->sag;
		}
		else
			bulundu = true;
	}
	if (bulundu)
	{
		if (tara->sol == NULL && tara->sag == NULL)
		{
			switch (yon)
			{
			case 'l':
				ust->sol = NULL;
				break;
			case 'r':
				ust->sag = NULL;
				break;
			default:
				if (koksecimi == 1)
					data1_kok = NULL;
				else if (koksecimi == 2)
					data2_kok = NULL;
				else
					data3_kok = NULL;
				break;
			}
		}
		else if (tara->sag == NULL)
		{
			switch (yon)
			{
			case 'l':
				ust->sol = tara->sol;
				break;
			case 'r':
				ust->sag = tara->sol;
				break;
			default:
				if (koksecimi == 1)
					data1_kok = tara->sol;
				else if (koksecimi == 2)
					data2_kok = tara->sol;
				else
					data3_kok = tara->sol;
				break;
			}
		}
		else if (tara->sol == NULL)
		{
			switch (yon)
			{
			case 'l':
				ust->sol = tara->sag;
				break;
			case 'r':
				ust->sag = tara->sag;
				break;
			default:
				if (koksecimi == 1)
					data1_kok = tara->sag;
				else if (koksecimi == 2)
					data2_kok = tara->sag;
				else
					data3_kok = tara->sag;
				break;
			}
		}
		else
		{
			ogrenci_dugum* q = tara->sag;
			while (q->sol)
				q = q->sol;

			q->sol = tara->sol;
			switch (yon)
			{
			case 'l':
				ust->sol = tara->sag;
				break;
			case 'r':
				ust->sag = tara->sag;
				break;
			default:
				if (koksecimi == 1)
					data1_kok = tara->sag;
				else if (koksecimi == 2)
					data2_kok = tara->sag;
				else
					data3_kok = tara->sag;
				break;
			}
		}
		delete tara;
	}
	else
		cout << "Silinecek Kayit Bulunamadi\n";
}

//Seçilen Dosyayı, Seçilen Yazdırma Şekline Göre Dosya İçerisine Yazıyoruz.
void Islemler::DosyayaYaz(int secim, int YazdirmaTuru)
{
	ogrenci_dugum* bilgi;
	bilgi = new ogrenci_dugum;

	if (secim == 1)
		bilgi = data1_kok;
	else if (secim == 2)
		bilgi = data2_kok;
	else
		bilgi = data3_kok;

	if (YazdirmaTuru == 1)
		PreorderYaz(bilgi);
	else if (YazdirmaTuru == 2)
		InorderYaz(bilgi);
	else
		PostorderYaz(bilgi);

}
void Islemler::PreorderYaz(ogrenci_dugum* p)
{
	remove("YazdirilanAgac.txt");
	ofstream dosyayaYaz("YazdirilanAgac.txt", ios::app);

	if (p)
	{
		dosyayaYaz << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		PreorderYaz(p->sol);
		PreorderYaz(p->sag);
	}
	dosyayaYaz.close();
}
void Islemler::InorderYaz(ogrenci_dugum* p)
{
	remove("YazdirilanAgac.txt");
	ofstream dosyayaYaz("YazdirilanAgac.txt", ios::app);

	if (p)
	{
		PreorderYaz(p->sol);
		dosyayaYaz << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		PreorderYaz(p->sag);
	}
	dosyayaYaz.close();
}
void Islemler::PostorderYaz(ogrenci_dugum* p)
{
	remove("YazdirilanAgac.txt");
	ofstream dosyayaYaz("YazdirilanAgac.txt", ios::app);

	if (p)
	{
		PreorderYaz(p->sol);
		dosyayaYaz << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		PreorderYaz(p->sag);
	}
	dosyayaYaz.close();
}

//Yığın Yapısını Kullanarak Ağaç İçerisine Öğrenci No Bilgisine Göre Öğrenciyi Arıyoruz.
void Islemler::IlkDerinlikAra(int dosyasecimi)
{
	int sayac = 1;
	char ogrno[20];
	cout << "Aramak Istediginiz Ogrencinin Numarasini Giriniz: ";
	cin >> ogrno;
	ogrenci_dugum* p;
	stack <ogrenci_dugum*> yigin;

	if (dosyasecimi == 1)
		yigin.push(data1_kok);
	else if (dosyasecimi == 2)
		yigin.push(data2_kok);
	else
		yigin.push(data3_kok);

	while (!yigin.empty())
	{
		p = yigin.top();
		yigin.pop();
		sayac += 2;
		if (strcmp(ogrno, p->ogrno) == 0)
		{
			sayac += 2;
			cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
			cout << "Islem " << sayac << ". adimda tamamlandi." << endl;
			return;
		}
		if (p->sag)
		{
			yigin.push(p->sag);
			sayac++;
		}
		if (p->sol)
		{
			yigin.push(p->sol);
			sayac++;
		}

	}

	cout << "Aradiginiz dosya icerisinde bu numaraya sahip ogrenci yok.\n" << endl;
}

//Kuyruk Yapısını Kullanarak Ağaç İçerisine Öğrenci No Bilgisine Göre Öğrenciyi Arıyoruz.
void Islemler::IlkGenislikAra(int dosyasecimi)
{
	int sayac = 1;
	char ogrno[20];
	cout << "Ogrenci Numarasini Giriniz: ";
	cin >> ogrno;
	ogrenci_dugum* p;
	queue <ogrenci_dugum*> kuyruk;

	if (dosyasecimi == 1)
		kuyruk.push(data1_kok);
	else if (dosyasecimi == 2)
		kuyruk.push(data2_kok);
	else
		kuyruk.push(data3_kok);

	while (!kuyruk.empty())
	{
		p = kuyruk.front();
		kuyruk.pop();
		sayac += 2;
		if (strcmp(ogrno, p->ogrno) == 0)
		{
			sayac += 2;
			cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
			cout << "Islem " << sayac << ". adimda tamamlandi." << endl;
			return;
		}
		if (p->sag)
		{
			kuyruk.push(p->sag);
			sayac++;
		}
		if (p->sol)
		{
			kuyruk.push(p->sol);
			sayac++;
		}
	}
	cout << "Aradiginiz dosya icerisinde bu numaraya sahip ogrenci yok.\n" << endl;
}