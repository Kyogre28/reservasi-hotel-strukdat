#include "queue.h"
#include <iostream>

// Mengosongkan front dan rear Queue.
void createQueue(QueueTamu& queue) {
    queue.front = nullptr;
    queue.rear = nullptr;
}

// Menambahkan tamu di rear; ini adalah operasi masuk Queue FIFO.
bool enqueue(QueueTamu& queue, Tamu* tamu) {
    if (!tamu) return false;
    for (NodeQueue* p = queue.front; p; p = p->next) {
        if (p->tamu == tamu) return false;
    }
    NodeQueue* baru = new NodeQueue{tamu, nullptr};
    if (!queue.rear) queue.front = queue.rear = baru;
    else { queue.rear->next = baru; queue.rear = baru; }
    return true;
}

// Mengambil tamu dari front; tamu yang masuk paling awal dilayani dahulu.
Tamu* dequeue(QueueTamu& queue) {
    if (!queue.front) return nullptr;
    NodeQueue* hapus = queue.front;
    Tamu* tamu = hapus->tamu;
    queue.front = hapus->next;
    if (!queue.front) queue.rear = nullptr;
    delete hapus;
    return tamu;
}

// Menampilkan antrean dari tamu paling depan sampai paling belakang.
void showQueue(const QueueTamu& queue) {
    if (!queue.front) { std::cout << "Antrean kosong.\n"; return; }
    int posisi = 1;
    for (NodeQueue* p = queue.front; p; p = p->next)
        std::cout << posisi++ << ". ID: " << p->tamu->id << " | " << p->tamu->nama << " | " << p->tamu->telepon << "\n";
}

// Menghapus seluruh node Queue tanpa menghapus data Tamu aslinya.
void clearQueue(QueueTamu& queue) {
    while (queue.front) dequeue(queue);
    queue.rear = nullptr;
}
