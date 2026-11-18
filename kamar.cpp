#include "kamar.h"
#include <iostream>
#include <iomanip>
// Membuat list kamar dalam keadaan kosong.
void createListKamar(ListKamar& list) { list.first = nullptr; }
// Menambah kamar di akhir list dan menolak nomor kamar duplikat.
bool insertLast(ListKamar& list, int nomor, const std::string& tipe, double harga) {
    if (searchKamar(list, nomor)) return false;
    Kamar* baru = new Kamar{nomor, tipe, harga, nullptr};
    if (!list.first) list.first=baru; else { Kamar* p=list.first; while(p->next) p=p->next; p->next=baru; }
    return true;
}
// Mencari kamar berdasarkan nomor kamar.
Kamar* searchKamar(ListKamar& list, int nomor) { for (Kamar* p=list.first; p; p=p->next) if(p->nomor==nomor) return p; return nullptr; }
// Mencetak seluruh kamar dengan format harga tetap.
void showKamar(const ListKamar& list) {
    if (!list.first) { std::cout << "Belum ada kamar.\n"; return; }
    for (Kamar* p=list.first; p; p=p->next) std::cout << "No: "<<p->nomor<<" | "<<p->tipe<<" | Rp"<<std::fixed<<std::setprecision(0)<<p->harga<<"\n";
}
// Membebaskan semua node kamar.
void clearKamar(ListKamar& list) { while(list.first) { Kamar* p=list.first; list.first=p->next; delete p; } }
