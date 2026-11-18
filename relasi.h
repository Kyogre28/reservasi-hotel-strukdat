#pragma once
#include "tamu.h"
#include "kamar.h"
struct NodeBST;

struct Relasi {
    Tamu* tamu;
    Kamar* kamar;
    std::string checkIn;
    int durasi;
    Relasi* prev;
    Relasi* next;
};

struct ListRelasi { Relasi* first; Relasi* last; };
// Menginisialisasi list relasi doubly linked list.
void createListRelasi(ListRelasi& list);
// Membuat relasi tamu-kamar setelah semua data dan validasi terpenuhi.
bool buatReservasi(ListRelasi&, ListTamu&, NodeBST*, int, int, const std::string&, int);
// Menghapus relasi berdasarkan ID tamu dan nomor kamar.
bool hapusReservasi(ListRelasi&, int, int);
// Menampilkan seluruh reservasi.
void showReservasi(const ListRelasi&);
// Menghitung jumlah reservasi setiap tamu serta nilai terbanyak/tersedikit.
void statistikReservasi(const ListRelasi&, const ListTamu&);
// Menghapus seluruh node relasi dari memori.
void clearRelasi(ListRelasi&);
