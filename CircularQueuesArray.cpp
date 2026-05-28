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

void hapus_tertentu() {
    if (head == NULL) {
        cout << "Data Kosong" << endl;
        return;
    }
    
    string hapus;
    cout << "Masukkan nama makanan yang ingin dihapus: ";
    cin >> hapus;
    
    Node* bantu = head;
    Node* hapus_node = NULL;
    
    // Jika data yang dihapus ada di head
    if (head->data.nama_makanan == hapus) {
        hapus_node = head;
        head = head->next;
        delete hapus_node;
        cout << "Data berhasil dihapus" << endl;
        return;
    }
    
    // Jika data yang dihapus bukan di head
    while (bantu->next != NULL) {
        if (bantu->next->data.nama_makanan == hapus) {
            hapus_node = bantu->next;
            bantu->next = bantu->next->next;
            delete hapus_node;
            cout << "Data berhasil dihapus" << endl;
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "Data tidak ditemukan" << endl;
}

int main() {
    int pilihan;
    
    while (true) {
        cout << "Menu Utama:" << endl;
        cout << "1. Tambah Data Makanan Di awal" << endl;
        cout << "2. Tampilkan Semua Data Makanan" << endl;
        cout << "3. Cari Data Makanan Berdasarkan Nama" << endl;
        cout << "4. Hapus Data Makanan Tertentu" << endl;
        cout << "5. Keluar Dari Aplikasi" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambah_awal();
                break;
            case 2:
                cetak_semua();
                break;
            case 3:
                cari_makanan();
                break;
            case 4:
                hapus_tertentu();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak tersedia, coba lagi." << endl;
                break;
        }
        
        cout << endl;
    }
    
    return 0;
