#include "app.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// Membaca bilangan bulat dan mengulang input jika formatnya salah.
static int bacaInt(const string& pesan) {
    int nilai;
    while (true) {
        cout << pesan;
        if (cin >> nilai) return nilai;
        cout << "Input harus berupa angka. Silakan coba lagi.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Membaca bilangan pecahan untuk data harga dengan validasi input.
static double bacaDouble(const string& pesan) {
    double nilai;
    while (true) {
        cout << pesan;
        if (cin >> nilai) return nilai;
        cout << "Input harus berupa angka. Silakan coba lagi.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Menahan tampilan hasil sampai pengguna menekan Enter.
static void tungguEnter() {
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Mengisi data awal tamu, kamar, BST, dan antrean demonstrasi.
static void isiDummy(ListTamu& t, ListKamar& k, NodeBST*& b) {
    insertFirst(t, 103, "Citra", "081234567893");
    insertFirst(t, 102, "Budi", "081234567892");
    insertFirst(t, 101, "Andi", "081234567891");
    int nomor[] = {305, 101, 204, 402};
    string tipe[] = {"Deluxe", "Standard", "Suite", "Standard"};
    double harga[] = {750000, 450000, 1200000, 500000};
    for (int i = 0; i < 4; i++) {
        insertLast(k, nomor[i], tipe[i], harga[i]);
        b = insertBST(b, searchKamar(k, nomor[i]));
    }
}

// Menangani submenu buat, hapus, tampil, dan statistik reservasi.
static void menuReservasi(ListRelasi& relasi, ListTamu& tamu, NodeBST* bst) {
    int pilihan = bacaInt("1. Buat\n2. Hapus\n3. Tampilkan\n4. Statistik\nPilihan: ");

    if (pilihan == 1) {
        int id = bacaInt("ID Tamu: ");
        int nomor = bacaInt("Nomor Kamar: ");
        string tanggal;
        cout << "Tanggal Check-in: ";
        cin >> tanggal;
        int durasi = bacaInt("Durasi: ");
        cout << (buatReservasi(relasi, tamu, bst, id, nomor, tanggal, durasi)
            ? "Reservasi berhasil.\n" : "Reservasi gagal.\n");
    } else if (pilihan == 2) {
        int id = bacaInt("ID Tamu: ");
        int nomor = bacaInt("Nomor Kamar: ");
        cout << (hapusReservasi(relasi, id, nomor)
            ? "Reservasi dihapus.\n" : "Reservasi tidak ditemukan.\n");
    } else if (pilihan == 3) {
        showReservasi(relasi);
    } else if (pilihan == 4) {
        statistikReservasi(relasi, tamu);
    } else {
        cout << "Pilihan reservasi tidak tersedia.\n";
    }
}

// Menangani submenu Queue: enqueue, dequeue, dan tampilkan antrean.
static void menuQueue(QueueTamu& antrean, ListTamu& tamu) {
    int pilihan = bacaInt("1. Tambah antrean\n2. Layani antrean\n3. Tampilkan antrean\nPilihan: ");
    if (pilihan == 1) {
        int id = bacaInt("ID Tamu: ");
        Tamu* tamuDipilih = searchTamu(tamu, id);
        if (!tamuDipilih) cout << "Tamu tidak ditemukan.\n";
        else if (enqueue(antrean, tamuDipilih)) cout << "Tamu masuk antrean.\n";
        else cout << "Tamu sudah berada di antrean.\n";
    } else if (pilihan == 2) {
        Tamu* tamuDilayani = dequeue(antrean);
        if (tamuDilayani) cout << "Melayani tamu: " << tamuDilayani->nama << "\n";
        else cout << "Antrean kosong.\n";
    } else if (pilihan == 3) {
        showQueue(antrean);
    } else {
        cout << "Pilihan antrean tidak tersedia.\n";
    }
}

// Menjalankan loop menu utama dan menghubungkan semua ADT.
void jalankanAplikasi(ListTamu& tamu, ListKamar& kamar, ListRelasi& relasi, QueueTamu& antrean, NodeBST*& bst) {
    isiDummy(tamu, kamar, bst);
    // Dummy antrean untuk demonstrasi FIFO: Andi masuk sebelum Budi.
    enqueue(antrean, searchTamu(tamu, 101));
    enqueue(antrean, searchTamu(tamu, 102));
    int pilihan = 0;

    while (pilihan != 11) {
        cout << "\n=== SISTEM RESERVASI HOTEL ===\n"
             << "1. Tampilkan tamu\n2. Tampilkan kamar\n3. Tambah tamu\n"
             << "4. Tambah kamar\n5. Cari kamar\n6. Inorder\n7. Preorder\n"
             << "8. Postorder\n9. Reservasi\n10. Antrean Tamu\n11. Keluar\n";

        pilihan = bacaInt("Pilihan: ");

        if (pilihan == 1) {
            showTamu(tamu);
        } else if (pilihan == 2) {
            showKamar(kamar);
        } else if (pilihan == 3) {
            int id = bacaInt("ID Tamu: ");
            string nama, telepon;
            cout << "Nama: "; cin >> nama;
            cout << "Telepon: "; cin >> telepon;
            if (searchTamu(tamu, id)) {
                cout << "ID tamu sudah digunakan.\n";
            } else {
                insertFirst(tamu, id, nama, telepon);
                cout << "Tamu berhasil ditambahkan.\n";
            }
        } else if (pilihan == 4) {
            int nomor = bacaInt("Nomor Kamar: ");
            string tipe;
            cout << "Tipe: "; cin >> tipe;
            double harga = bacaDouble("Harga: ");
            if (insertLast(kamar, nomor, tipe, harga)) {
                bst = insertBST(bst, searchKamar(kamar, nomor));
                cout << "Kamar berhasil ditambahkan.\n";
            } else {
                cout << "Nomor kamar sudah ada.\n";
            }
        } else if (pilihan == 5) {
            int nomor = bacaInt("Nomor Kamar: ");
            NodeBST* node = searchBST(bst, nomor);
            if (node) {
                cout << "Ditemukan: " << node->infoKamar->nomor << " | "
                     << node->infoKamar->tipe << " | Rp" << fixed
                     << setprecision(0) << node->infoKamar->harga << "\n";
            } else {
                cout << "Kamar tidak ditemukan.\n";
            }
        } else if (pilihan == 6) {
            inorder(bst); cout << "\n";
        } else if (pilihan == 7) {
            preorder(bst); cout << "\n";
        } else if (pilihan == 8) {
            postorder(bst); cout << "\n";
        } else if (pilihan == 9) {
            menuReservasi(relasi, tamu, bst);
        } else if (pilihan == 10) {
            menuQueue(antrean, tamu);
        } else if (pilihan != 11) {
            cout << "Pilihan menu tidak tersedia.\n";
        }

        if (pilihan != 11) tungguEnter();
    }
}
