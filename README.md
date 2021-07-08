# Ağaç Yapısı ve Arama Algoritmaları

## 1.Ödev İsterleri
 
İkili Ağaç: Bu ödevde öğrenci listesini saklayacak ağaç yapısı kurmanız beklenmektedir. Programınız girdi dosyasından öğrenci numarası, isim ve soy isim bilgilerini okuyarak, ikili ağaç yapısında tutmalıdır. 3 farklı girdi dosyası için 3 farklı ağaç oluşturmanız beklenmektedir.
Programda şu fonksiyonlar yer almalıdır:
* agacKur(): Girdi dosyasının okunarak, ağaç yapısının kurulduğu fonksiyondur. Ağaç yapısının düğümleri öğrenci numarası kullanılarak oluşturulmalıdır. (Not: Ağaç oluşturma sırasında gereken dosyadan okuma işlemleri için bir kod örneği, ödevde yer alan dosyadan_oku.cpp dosyasında yer almaktadır.)
* ogrenciSil(): Öğrenci numarasını kullanıcıdan alarak, öğrenciyi ağaçtan siler.
* inorderTara(): Ağaç yapısını sıralı (inorder) olarak listeler.
* preorderTara(): Ağaç yapısını kökten başlayarak (preorder) olarak listeler.
* postorderTara(): Ağaç yapısını sondan başlayarak (postorder) olarak listeler.
* ilkDerinlikAra(): Öğrenci numarasını kullanıcıdan alarak, ağaç üzerinde ilk derinlik öncelikli arama(depth-first search) işlemi yapar. Bulunduğu takdirde öğrenci numarasına ait isim ve soy isim bilgilerini, aksi takdirde bulunamadığı bilgisini döner. (Yığın yapısı kullanarak gerçekleyiniz.)
* ilkGenişlikAra(): Öğrenci numarasını kullanıcıdan alarak, ağaç üzerinde ilk genişlik öncelikli arama(breath-first search) işlemi yapar. Bulunduğu takdirde öğrenci numarasına ait isim ve soy isim bilgilerini, aksi takdirde bulunamadığı bilgisini döner. (Kuyruk yapısı kullanarak gerçekleyiniz.)
* dosyayaYaz(): Çıktı dosyasının oluşturulduğu fonksiyondur. Oluşturulan ağacın son hali çıktı dosyasına yazdırılır. Bu fonksiyonda ağaç, uygun yöntemi kullanarak rekürsif bir şekilde dosyaya yazdırılmalıdır.

Verilen 3 adet girdi dosyasında (data1.txt, data2.txt, data3.txt), aynı öğrenci bilgilerinin farklı sıralanışları yer almaktadır. Kodu hazırladıktan sonra, raporunuzda, farklı girdi dosyaları için arama fonksiyonlarının performanslarını değerlendirmeniz beklenmektedir (sayaç koyarak toplam işlem adımını sayma vb.). Raporda sözel ve sayısal olarak ölçüm ve değerlendirmeleriniz yer almalıdır.
