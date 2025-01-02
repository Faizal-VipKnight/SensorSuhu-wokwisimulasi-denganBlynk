# SensorSuhu-wokwisimulasi-denganBlynk
Memonitoring sensor suhu dan kelembapan yang terkoneksi dengan wifi, blynk, lcd , untuk project kali ini khusus untuk memonitoring suhu dalam celcius


![Screenshot 2025-01-03 060042](https://github.com/user-attachments/assets/cca828f2-e36d-4298-8bca-49d7965f54b6)

gambar diatas merupakan wiring untuk kode yang digunakan

alat yang dipakai diantaranya :
sensor suhu
lcd
buzzer
esp32
jumper
resistor

untuk menjalankan project ini kalian harus membuat akun blynk terlebih dahulu dan membuat virtual pin, lalu konfigurasi di web dashborad blynk/ aplikasi setelah itu save dan buat add device, untuk ini saya sarankan memakai template dari blynk, setelah itu akan keluar token, id, auth, dll, copy ini lalu masukkan kedalam kode

jangan lupa tambah library yang sesuai, untuk project ini library nya yaitu blynk, dallastemperatur, liquidcystal_i2c

tambahan, perlu menggunakan resistor 4.7 K ohm
