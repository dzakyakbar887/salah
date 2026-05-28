#include <iostream>
#include <string>

using namespace std;

struct Menu {
    string nama_makanan;
    int harga_makanan;
    string kategori;
};

struct Node {
    Menu data;
    Node* next;
};

Node* head = NULL;

void tambah_awal() {
    Node* baru;
    baru = new Node;
    
    cout << "Nama Makanan: ";
    cin >> baru->data.nama_makanan;
    cout << "Harga: ";
    cin >> baru->data.harga_makanan;
    
    // Validasi input kategori
    if (baru->data.nama_makanan == "" || baru->data.harga_makanan <= 0) {
        cout << "Input tidak valid" << endl;
        return;
    }
    
    // Pilih Kategori Barang
    int pilih_kategori;
    cout << "Pilih Kategori:" << endl;
    cout << "1. Makanan" << endl;
    cout << "2. Minuman" << endl;
    cout << "Pilihan: ";
    cin >> pilih_kategori;
    
    // Pengkondisian untuk menentukan isi dari kategori berdasarkan pilihan user
    if (pilih_kategori == 1) {
        baru->data.kategori = "Makanan";
    } else {
        baru->data.kategori = "Minuman";
    }
    
    baru->next = head;
    head = baru;
}