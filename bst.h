#pragma once
#include "kamar.h"

struct NodeBST {
    int key;
    Kamar* infoKamar;
    NodeBST* left;
    NodeBST* right;
};

// Memasukkan kamar ke BST berdasarkan nomor kamar.
NodeBST* insertBST(NodeBST* root, Kamar* kamar);
// Mencari node BST berdasarkan nomor kamar.
NodeBST* searchBST(NodeBST* root, int nomor);
// Traversal kiri-root-kanan; hasilnya terurut menaik.
void inorder(NodeBST* root);
// Traversal root-kiri-kanan.
void preorder(NodeBST* root);
// Traversal kiri-kanan-root.
void postorder(NodeBST* root);
// Menghapus seluruh node BST secara rekursif.
void deleteBST(NodeBST*& root);
