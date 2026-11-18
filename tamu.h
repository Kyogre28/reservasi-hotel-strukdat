#pragma once
#include <string>

struct Tamu {
    int id;
    std::string nama;
    std::string telepon;
    Tamu* next;
};

struct ListTamu { Tamu* first; };

// Menginisialisasi list tamu agar kosong.
void createList(ListTamu& list);
// Menambahkan tamu baru di awal list jika ID belum digunakan.
void insertFirst(ListTamu& list, int id, const std::string& nama, const std::string& telepon);
// Mencari tamu berdasarkan ID dan mengembalikan alamat datanya.
Tamu* searchTamu(ListTamu& list, int id);
// Menampilkan seluruh data tamu dari awal sampai akhir list.
void showTamu(const ListTamu& list);
// Menghapus seluruh node tamu dari memori.
void clearTamu(ListTamu& list);
