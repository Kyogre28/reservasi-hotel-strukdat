#pragma once
#include <string>

struct Kamar {
    int nomor;
    std::string tipe;
    double harga;
    Kamar* next;
};

struct ListKamar { Kamar* first; };

// Menginisialisasi list kamar agar kosong.
void createListKamar(ListKamar& list);
// Menambahkan kamar di akhir list jika nomor kamar belum digunakan.
bool insertLast(ListKamar& list, int nomor, const std::string& tipe, double harga);
// Mencari kamar berdasarkan nomor kamar.
Kamar* searchKamar(ListKamar& list, int nomor);
// Menampilkan seluruh data kamar.
void showKamar(const ListKamar& list);
// Menghapus seluruh node kamar dari memori.
void clearKamar(ListKamar& list);
