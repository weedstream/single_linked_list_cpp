#include <iostream>

using namespace std;

struct linkedlist {
    string data;
    linkedlist * next;
};

linkedlist * head;
linkedlist * tail;
linkedlist * simpul;

void buat_simpul(string data_masukkan) {
    simpul = new linkedlist;
    simpul -> data = data_masukkan;
    simpul -> next = NULL;
}

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool simpul_kosong() {
    if (head == NULL && tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void tambah_belakang(string data_user) {
    if (simpul_kosong() == true) {
        buat_simpul(data_user);
        head = simpul;
        tail = simpul;
    } else {
        simpul = new linkedlist;
        simpul -> data = data_user;
        simpul -> next = tail;
        tail -> next = simpul;
        tail = simpul;
        simpul -> next = NULL;
    }
}

void tambah_depan(string data_user) {
    if (simpul_kosong() == true) {
        buat_simpul(data_user);
        head = simpul;
        tail = simpul;
    } else {
        buat_simpul(data_user);
        simpul -> next = head;
        head = simpul;
    }
}

void hapus_belakang() {
    if (simpul_kosong() == true) {
        cout << "Tidak ada simpul" << endl;
    } else {
        linkedlist * helper;
        helper = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            while (helper -> next != tail) {
                helper = helper -> next;
            }
            tail = helper;
            helper = helper -> next;
            tail -> next = NULL;
            delete helper;
        }
    }
}

void hapus_depan() {
    if (simpul_kosong() == true) {
        cout << "Tidak ada simpul" << endl;
    } else {
        linkedlist * helper;
        helper = head;
        if (head == tail) {
             head = NULL;
            tail = NULL;
            delete helper;
        } else {
            head = head -> next;
            helper -> next = NULL;
            delete helper;
        }
    }
}

void tampil_data() {
    if (simpul_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        linkedlist * helper;
        helper = head;
        while (helper != NULL) {
            cout << helper -> data << " ";
            helper = helper -> next;
        }
    }
}

int main() {
    inisialisasi();

    cout << endl << endl;

    tambah_depan("Rabu");
    tambah_belakang("Kamis");
    //tambah_depan("Selasa");
    //hapus_belakang();
    tampil_data();

    cout << endl << endl;
    return 0;
}