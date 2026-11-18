#include "bst.h"
#include <iostream>
// Memasukkan pointer kamar ke posisi yang sesuai aturan BST.
NodeBST* insertBST(NodeBST* root, Kamar* kamar) {
    if (!root) return new NodeBST{kamar->nomor, kamar, nullptr, nullptr};
    if (kamar->nomor < root->key) root->left=insertBST(root->left,kamar);
    else if (kamar->nomor > root->key) root->right=insertBST(root->right,kamar);
    return root;
}
// Mencari nomor kamar dengan membandingkan key secara rekursif.
NodeBST* searchBST(NodeBST* root, int nomor) { if(!root||root->key==nomor) return root; return nomor<root->key?searchBST(root->left,nomor):searchBST(root->right,nomor); }
static void cetak(NodeBST* n) { if(n) std::cout<<n->key<<" ("<<n->infoKamar->tipe<<") "; }
// Mengunjungi BST dalam urutan kiri-root-kanan.
void inorder(NodeBST* r) { if(!r)return; inorder(r->left); cetak(r); inorder(r->right); }
// Mengunjungi BST dalam urutan root-kiri-kanan.
void preorder(NodeBST* r) { if(!r)return; cetak(r); preorder(r->left); preorder(r->right); }
// Mengunjungi BST dalam urutan kiri-kanan-root.
void postorder(NodeBST* r) { if(!r)return; postorder(r->left); postorder(r->right); cetak(r); }
// Menghapus seluruh node BST secara postorder.
void deleteBST(NodeBST*& r) { if(!r)return; deleteBST(r->left); deleteBST(r->right); delete r; r=nullptr; }
