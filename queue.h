#pragma once
#include "tamu.h"

struct NodeQueue {
    Tamu* tamu;
    NodeQueue* next;
};

struct QueueTamu {
    NodeQueue* front;
    NodeQueue* rear;
};

// Menginisialisasi Queue dengan front dan rear kosong.
void createQueue(QueueTamu& queue);
// Menambahkan tamu ke belakang antrean (FIFO).
bool enqueue(QueueTamu& queue, Tamu* tamu);
// Mengambil dan menghapus tamu paling depan antrean (FIFO).
Tamu* dequeue(QueueTamu& queue);
// Menampilkan isi antrean dari front sampai rear.
void showQueue(const QueueTamu& queue);
// Menghapus seluruh node antrean dari memori.
void clearQueue(QueueTamu& queue);
