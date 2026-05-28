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

void cetak_semua() {
    // Mengecek apakah data kosong
    if (head == NULL) {
        cout << "Data Kosong" << endl;
        return;
    }
    
    // Menampilkan semua data jika data tidak kosong atau isi dari pointer head != NULL
    Node* bantu = head;
    while (bantu != NULL) {
        cout << "================================" << endl;
        cout << "Nama Makanan: " << bantu->data.nama_makanan << endl;
        cout << "Harga: " << bantu->data.harga_makanan << endl;
        cout << "Kategori: " << bantu->data.kategori << endl;
        bantu = bantu->next;
    }
    cout << "================================" << endl;
}

void cari_makanan() {
    // Mengecek apakah data kosong
    if (head == NULL) {
        cout << "Data Kosong" << endl;
        return;
    }
    
    string cari;
    cout << "Masukkan nama makanan yang dicari: ";
    cin >> cari;
    
    // Menampilkan data yang dicari jika data tidak kosong
    Node* bantu = head;
    bool ditemukan = false;
    
    while (bantu != NULL) {
        if (bantu->data.nama_makanan == cari) {
            cout << "================================" << endl;
            cout << "Nama Makanan: " << bantu->data.nama_makanan << endl;
            cout << "Harga: " << bantu->data.harga_makanan << endl;
            cout << "Kategori: " << bantu->data.kategori << endl;
            ditemukan = true;
        }
        bantu = bantu->next;
    }
    
    if (!ditemukan) {
        cout << "Data tidak ditemukan" << endl;
    }
}

