# IF2110_TB_01_A
## Penjelasan Ringkas Program
BurBir merupakan program buatan kelompok A dari K01 IF2110 Algoritma dan Struktur Data untuk menyelesaikan permasalahan pembuatan simulator aplikasi sosial media berbasis command-line interface (CLI) yang memanfaatkan ADT dengan menggunakan bahasa C. Program ini sebagai bentuk simulasi pengoperasian suatu sosial media. Pengimplementasian ADT primitif menjadi fitur aplikasi memerlukan beberapa aksi modifikasi untuk menyesuaikan kebutuhan fitur. Fitur-fitur yang terdapat pada program ini sesuai dengan spesifikasi antara lain adalah pengguna, profil, pertemanan, permintaan pertemanan, kicauan, balasan, draf kicauan, utas, serta simpan dan muat.

## Cara Kompilasi dan Menjalankan Program
1. Pastikan anda sudah berada pada OS Linux Ubuntu dan telah menginstall "gcc compiler" dan program "make"
2. Masuk ke terminal
3. Clone repository ini
   ```
   git clone https://github.com/wigaandini/IF2110_TB_01_A.git
   ```
4. Pindah ke directory IF2110_TB_01_A
5. Jalankan command berikut untuk melakukan kompilasi
   ```
   make
   ```
6. Jalankan command berikut untuk menjalankan program
   ```
   ./main
   ```
7. Jalankan command berikut untuk membersihkan file hasil kompilasi
   ```
   make clean
   ```

## Pembagian Tugas
| NIM      | Tugas                                                                         |
|----------|-------------------------------------------------------------------------------|
| 13522015 | - Membuat struktur folder GitHub                                              |
|          | - Membuat ADT List Statik User                                               |
|          | - Membuat program PROFIL dan PENGGUNA/USER beserta drivernya                |
|          | - Mengintegrasikan program dengan main.c                                     |
|          | - Membuat semua driver dari ADT yang ada                                    |
|          | - Membuat laporan dengan penjelasan tambahan spesifikasi tugas, data test, test script, lampiran                                        |
| 13522024 | - Membuat ADT Tree Balasan                                                  |
|          | - Membuat program BALASAN beserta drivernya dan mengintegrasikannya dengan main.c |
|          | - Membuat program SIMPAN dan MUAT                                           |
|          | - Membuat laporan                                                            |
| 13522040 | - Membuat perencanaan dan sketsa seluruh ADT yang dipakai pada Program Burbir |
|          | - Membuat ADT Graf dengan Representasi Adjacency Matrix                      |
|          | - Membuat ADT Priority Queue dengan Struktur Berkait                         |
|          | - Membuat header dan realisasi dari ADT Matriks Pertemanan dan Permintaan Pertemanan |
|          | - Membuat driver permintaan pertemanan                                       |
|          | - Mengintegrasikan ADT Matriks Pertemanan dan Permintaan Pertemanan ke main.c |
|          | - Membuat laporan                                                            |
| 13522047 | - Membuat ADT Stack Draf Kicauan                                             |
|          | - Membuat program DRAF beserta drivernya dan mengintegrasikannya dengan main.c |
|          | - Membuat program SIMPAN dan MUAT                                           |
|          | - Membuat laporan                                                            |
| 13522053 | - Membuat struktur folder GitHub                                             |
|          | - Convert ADT-ADT bawaan                                                    |
|          | - Membuat dan memodifikasi ADT Word Machine                                 |
|          | - Membuat ADT Linked List Utas                                              |
|          | - Membuat program UTAS beserta drivernya dan mengintegrasikannya dengan main.c |
|          | - Notulen asistensi dan meeting kelompok                                    |
|          | - Membuat laporan dengan ringkasan, penjelasan tambahan spesifikasi tugas, struktur data, data test, test script |
| 13522060 | - Membuat ADT List Dinamis Kicauan                                          |
|          | - Membuat program KICAUAN beserta drivernya dan mengintegrasikannya dengan main.c |
|          | - Memodifikasi ADT Word Machine                                             |
|          | - Notulen asistensi dan meeting kelompok                                    |
|          | - Membuat laporan dengan ringkasan, struktur data, data test, test script   |


## Daftar Fitur Beserta Status Pengerjaannya
### Fitur yang telah selesai
1. DAFTAR
2. MASUK
3. KELUAR
4. TUTUP_PROGRAM
5. GANTI_PROFIL
6. LIHAT_PROFIL
7. ATUR_JENIS_AKUN
8. UBAH_FOTO_PROFIL
9. DAFTAR_TEMAN
10. HAPUS_TEMAN
11. TAMBAH_TEMAN
12. DAFTAR_PERMINTAAN_PERTEMANAN
13. SETUJUI_PERTEMANAN
14. KICAU
15. KICAUAN
16. SUKA_KICAUAN <ID_KICAU>
17. UBAH_KICAUAN <ID_KICAU>
18. BALAS <ID_KICAU> <ID_BALASAN>
19. BALASAN <ID_KICAU>
20. HAPUS_BALASAN <ID_KICAU> <ID_BALASAN>
21. BUAT_DRAF
22. LIHAT_DRAF
23. UTAS <ID_KICAU>
24. SAMBUNG_UTAS <ID_UTAS> <INDEX>
25. HAPUS_UTAS <ID_UTAS> <INDEX>
26. CETAK_UTAS <ID_UTAS>
27. SIMPAN
28. MUAT
29. FYB

### Fitur yang tidak selesai
1. Program UTAS (Belum bisa terintegrasi dengan file config)

