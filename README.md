# Sistem Reservasi Hotel

Sistem reservasi hotel berbasis C++ untuk tugas besar Struktur Data. Program berjalan melalui Command Line Interface (CLI) dan menggabungkan beberapa struktur data untuk mengelola tamu, kamar, reservasi, pencarian kamar, serta antrean tamu.

## Struktur Data

Program menggunakan struktur data berikut:

1. **Singly Linked List Tamu**
   - Menyimpan ID, nama, dan nomor telepon tamu.
   - Operasi: tambah, cari, tampilkan, dan hapus dari memori.

2. **Singly Linked List Kamar**
   - Menyimpan nomor kamar, tipe kamar, dan harga.
   - Nomor kamar harus unik.

3. **Doubly Linked List Relasi**
   - Menghubungkan tamu dengan kamar melalui data reservasi.
   - Menyimpan tanggal check-in dan durasi reservasi.

4. **Binary Search Tree (BST)**
   - Menyimpan pointer ke data kamar.
   - Digunakan untuk pencarian kamar berdasarkan nomor kamar.
   - Menyediakan traversal inorder, preorder, dan postorder.

5. **Queue Tamu**
   - Digunakan untuk antrean tamu.
   - Menggunakan prinsip FIFO (*First In, First Out*).
   - Tamu yang masuk lebih dahulu akan dilayani lebih dahulu.

## Fitur Program

- Menampilkan data tamu.
- Menampilkan data kamar.
- Menambah tamu dengan validasi ID unik.
- Menambah kamar dengan validasi nomor unik.
- Mencari kamar menggunakan BST.
- Menampilkan traversal BST:
  - Inorder
  - Preorder
  - Postorder
- Membuat reservasi.
- Menghapus reservasi.
- Menampilkan seluruh reservasi.
- Menampilkan statistik jumlah reservasi setiap tamu.
- Menampilkan tamu dengan reservasi terbanyak dan tersedikit.
- Menambah tamu ke antrean.
- Melayani tamu dari antrean menggunakan FIFO.

## Struktur File

| File | Fungsi |
|---|---|
| `main.cpp` | Inisialisasi struktur data dan menjalankan aplikasi |
| `app.h` / `app.cpp` | Menu utama, input pengguna, dan integrasi fitur |
| `tamu.h` / `tamu.cpp` | Struktur dan operasi List Tamu |
| `kamar.h` / `kamar.cpp` | Struktur dan operasi List Kamar |
| `relasi.h` / `relasi.cpp` | Struktur dan operasi reservasi |
| `bst.h` / `bst.cpp` | Struktur dan operasi Binary Search Tree |
| `queue.h` / `queue.cpp` | Struktur dan operasi Queue Tamu |

## Persyaratan

- Windows 10/11
- Compiler C++ dengan dukungan C++11, misalnya MinGW atau GCC
- Visual Studio Code atau IDE C++ lainnya

## Cara Compile

Buka PowerShell pada folder project, lalu jalankan:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp app.cpp tamu.cpp kamar.cpp relasi.cpp bst.cpp queue.cpp -o hotel.exe
```

## Cara Menjalankan

```powershell
.\hotel.exe
```

## Menu Utama

```text
1. Tampilkan tamu
2. Tampilkan kamar
3. Tambah tamu
4. Tambah kamar
5. Cari kamar
6. Inorder
7. Preorder
8. Postorder
9. Reservasi
10. Antrean Tamu
11. Keluar
```

## Contoh Alur Queue

Data dummy antrean dimulai dengan:

```text
1. Andi
2. Budi
```

Jika memilih menu **Antrean Tamu → Layani antrean**, Andi akan dilayani terlebih dahulu. Setelah Andi dilayani, Budi menjadi tamu paling depan.

Hal ini menunjukkan prinsip:

```text
First In, First Out (FIFO)
```

## Catatan

Data saat ini masih disimpan di memori. Data akan kembali ke data dummy ketika program dijalankan ulang. Penyimpanan permanen menggunakan file handling dapat ditambahkan pada tahap pengembangan berikutnya.
