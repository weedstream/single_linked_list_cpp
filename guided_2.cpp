#include <iostream>

using namespace std;

struct melist {
    string data;
    melist * next;
};

melist * head;
melist * tail;
melist * simpul_baru;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool list_kosong() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

void buat_simpul(string dataMasukkan) {
    simpul_baru = new melist;
    simpul_baru -> data = dataMasukkan;
    simpul_baru -> next = NULL;
}

void tambah_belakang(string data_user) {
    buat_simpul(data_user);
    if (list_kosong() == true) {
        head = simpul_baru;
        tail = simpul_baru;
        simpul_baru -> next = head;
    } else {
        while (tail -> next != head) {
            tail = tail -> next;
        }
        tail -> next = simpul_baru;
        simpul_baru -> next = head;
    }
}

void tambah_depan(string data_user) {
    buat_simpul(data_user);
        if (list_kosong() == true) {
        head = simpul_baru;
        tail = simpul_baru;
        simpul_baru -> next = head;
    } else {
        while (tail -> next != head) {
            tail = tail -> next;
        }
        simpul_baru -> next = head;
        head = simpul_baru;
        tail -> next = simpul_baru;
    }
}

void hapus_belakang() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        melist * helper;
        helper = head;
        tail = head;
        if (helper -> next == head) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            while (helper -> next != head) {
                helper = helper -> next;
            }
            while (tail -> next != helper) {
                tail = tail -> next;
            }
            tail -> next = head;
            helper -> next = NULL;
            delete helper;
        }
    }
}

void hapus_depan() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        melist * helper;
        helper = head;
        tail = head;
        if (helper -> next == head) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            while (tail -> next != helper) {
                tail = tail -> next;
            }
            head = head -> next;
            tail -> next = head;
            helper -> next = NULL;
            delete helper;
        }
    }
}

void tampil_list() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        tail = head;
        do {
            cout << tail -> data << " ";
            tail = tail -> next;
        } while (tail != head);
        cout << endl;
    }
}

int main() {

    cout << endl << endl;

    tambah_belakang("Rabu");
    tambah_belakang("Kamis");
    tambah_belakang("Jum'at");
    tambah_depan("Selasa");
    tampil_list();
    hapus_belakang();
    tampil_list();
    hapus_depan();
    tampil_list();

    cout << endl << endl;
    
    return 0;
}