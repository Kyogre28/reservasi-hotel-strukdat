#include "app.h"

int main() {
    // Membuat dan menginisialisasi seluruh struktur data utama.
    ListTamu tamu;
    ListKamar kamar;
    ListRelasi relasi;
    QueueTamu antrean;
    NodeBST* bst = nullptr;

    createList(tamu);
    createListKamar(kamar);
    createListRelasi(relasi);
    createQueue(antrean);

    // Menjalankan menu utama yang menghubungkan semua fungsi aplikasi.
    jalankanAplikasi(tamu, kamar, relasi, antrean, bst);

    // Membebaskan memori sebelum program selesai.
    clearQueue(antrean);
    clearRelasi(relasi);
    deleteBST(bst);
    clearTamu(tamu);
    clearKamar(kamar);
    return 0;
}
