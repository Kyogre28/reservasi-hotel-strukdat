#include "tamu.h"
#include <iostream>
// Membuat list tamu dalam keadaan kosong.
void createList(ListTamu& list) { list.first = nullptr; }
// Menambah tamu di posisi paling awal setelah mengecek ID duplikat.
void insertFirst(ListTamu& list, int id, const std::string& nama, const std::string& telepon) {
    if (searchTamu(list, id)) return;
    list.first = new Tamu{id, nama, telepon, list.first};
}
// Menelusuri list dan mengembalikan pointer tamu dengan ID yang cocok.
Tamu* searchTamu(ListTamu& list, int id) { for (Tamu* p=list.first; p; p=p->next) if (p->id==id) return p; return nullptr; }
// Mencetak seluruh isi list tamu.
void showTamu(const ListTamu& list) {
    if (!list.first) { std::cout << "Belum ada tamu.\n"; return; }
    for (Tamu* p=list.first; p; p=p->next) std::cout << "ID: "<<p->id<<" | "<<p->nama<<" | "<<p->telepon<<"\n";
}
// Membebaskan semua node tamu sebelum program selesai.
void clearTamu(ListTamu& list) { while (list.first) { Tamu* p=list.first; list.first=p->next; delete p; } }
