#include "relasi.h"
#include "bst.h"
#include <iostream>
void createListRelasi(ListRelasi& list) { list.first=nullptr; list.last=nullptr; }
bool buatReservasi(ListRelasi& l,ListTamu& ts,NodeBST* b,int id,int no,const std::string& d,int dur){Tamu*t=searchTamu(ts,id);NodeBST*n=searchBST(b,no);if(!t||!n||dur<=0)return false;for(Relasi*r=l.first;r;r=r->next)if(r->tamu==t&&r->kamar==n->infoKamar)return false;Relasi*x=new Relasi{t,n->infoKamar,d,dur,nullptr,nullptr};if(!l.last)l.first=l.last=x;else{x->prev=l.last;l.last->next=x;l.last=x;}return true;}
bool hapusReservasi(ListRelasi& l,int id,int no){for(Relasi*r=l.first;r;r=r->next)if(r->tamu->id==id&&r->kamar->nomor==no){if(r->prev)r->prev->next=r->next;else l.first=r->next;if(r->next)r->next->prev=r->prev;else l.last=r->prev;delete r;return true;}return false;}
void showReservasi(const ListRelasi& l){if(!l.first){std::cout<<"Belum ada reservasi.\n";return;}for(Relasi*r=l.first;r;r=r->next)std::cout<<r->tamu->nama<<" -> Kamar "<<r->kamar->nomor<<" ("<<r->kamar->tipe<<") | Check-in: "<<r->checkIn<<" | "<<r->durasi<<" hari\n";}
void statistikReservasi(const ListRelasi& l,const ListTamu& ts){Tamu*maxT=nullptr,*minT=nullptr;int mx=-1,mn=2147483647;for(Tamu*t=ts.first;t;t=t->next){int n=0;for(Relasi*r=l.first;r;r=r->next)if(r->tamu==t)n++;std::cout<<t->nama<<": "<<n<<" kamar\n";if(n>mx)mx=n,maxT=t;if(n<mn)mn=n,minT=t;}if(maxT)std::cout<<"Terbanyak: "<<maxT->nama<<" ("<<mx<<")\nTersedikit: "<<minT->nama<<" ("<<mn<<")\n";}
void clearRelasi(ListRelasi& l){while(l.first){Relasi*r=l.first;l.first=r->next;delete r;}l.last=nullptr;}
