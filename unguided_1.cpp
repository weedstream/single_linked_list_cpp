#include <iostream>

using namespace std;

int menu;
char ya_tidak;
bool keluar = false;
string isi_data;

void menu_keluar ();
int main ();

struct linkedlist {
    string data;
    linkedlist * next;
};

linkedlist * head;
linkedlist * tail;
linkedlist * simpul;

void buat_simpul_nc(string data_masukkan) {
    simpul = new linkedlist;
    simpul -> data = data_masukkan;
    simpul -> next = NULL;
}

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool simpul_kosong_nc() {
    if (head == NULL && tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void tambah_belakang_nc(string data_user) {
    if (simpul_kosong_nc() == true) {
        buat_simpul_nc(data_user);
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

void tambah_depan_nc(string data_user) {
    if (simpul_kosong_nc() == true) {
        buat_simpul_nc(data_user);
        head = simpul;
        tail = simpul;
    } else {
        buat_simpul_nc(data_user);
        simpul -> next = head;
        head = simpul;
    }
}

void hapus_belakang_nc() {
    if (simpul_kosong_nc() == true) {
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

void hapus_depan_nc() {
    if (simpul_kosong_nc() == true) {
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

void tampil_data_nc() {
    if (simpul_kosong_nc() == true) {
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

/*          CIRCULAR           */

bool list_kosong_ci() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

void buat_simpul_ci(string dataMasukkan) {
    simpul = new linkedlist;
    simpul -> data = dataMasukkan;
    simpul -> next = NULL;
}

void tambah_belakang_ci(string data_user) {
    buat_simpul_ci(data_user);
    if (list_kosong_ci() == true) {
        head = simpul;
        tail = simpul;
        simpul -> next = head;
    } else {
        while (tail -> next != head) {
            tail = tail -> next;
        }
        tail -> next = simpul;
        simpul -> next = head;
    }
}

void tambah_depan_ci(string data_user) {
    buat_simpul_ci(data_user);
        if (list_kosong_ci() == true) {
        head = simpul;
        tail = simpul;
        simpul -> next = head;
    } else {
        while (tail -> next != head) {
            tail = tail -> next;
        }
        simpul -> next = head;
        head = simpul;
        tail -> next = simpul;
    }
}

void hapus_belakang_ci() {
    if (list_kosong_ci() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        linkedlist * helper;
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

void hapus_depan_ci() {
    if (list_kosong_ci() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        linkedlist * helper;
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

void tampil_list_ci() {
    if (list_kosong_ci() == true) {
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

void menu_nc () {
    cout << "Linked List Non Circular" << endl;
            cout << "1. Tambah Depan\n";
            cout << "2. Tambah Belakang\n";
            cout << "3. Hapus Depan\n";
            cout << "4. Hapus Belakang\n";
            cout << "5. Tampil Data\n";
            cout << "6. Keluar\n";
            cout << "Silahkan pilih menu : ";
            cin >> menu;
            
            if (menu == 1) {
                cout << "Tambah Depan" << endl;
                cout << "Silahkan masukkan data : ";
                cin >> isi_data;
                tambah_depan_nc (isi_data);
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_nc ();
                    }
                }
            } else if (menu == 2) {
                cout << "Tambah Belakang" << endl;
                cout << "Silahkan masukkan data : ";
                cin >> isi_data;
                tambah_belakang_nc (isi_data);
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_nc ();
                    }
                }
            } else if (menu == 3) {
                cout << "Hapus Depan" << endl;
                hapus_depan_nc ();
                cout << "Data terhapus" << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_nc ();
                    }
                }
            } else if (menu == 4) {
                cout << "Hapus Belakang" << endl;
                hapus_belakang_nc ();
                cout << "Data terhapus" << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_nc ();
                    }
                }
            } else if (menu == 5) {
                cout << "Tampil Data" << endl;
                tampil_data_nc ();
                cout << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_nc ();
                    }
                }
            } else if (menu == 6) {
                system ("clear");
                main ();
            } else {
                cout << "Pilihan tidak ada" << endl;
            }
}

void menu_ci () {
    cout << "Linked List Circular" << endl;
            cout << "1. Tambah Depan\n";
            cout << "2. Tambah Belakang\n";
            cout << "3. Hapus Depan\n";
            cout << "4. Hapus Belakang\n";
            cout << "5. Tampil Data\n";
            cout << "6. Keluar\n";
            cout << "Silahkan pilih menu : ";
            cin >> menu;
            
            if (menu == 1) {
                cout << "Tambah Depan" << endl;
                cout << "Silahkan masukkan data : ";
                cin >> isi_data;
                tambah_depan_ci (isi_data);
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_ci ();
                    }
                }
            } else if (menu == 2) {
                cout << "Tambah Belakang" << endl;
                cout << "Silahkan masukkan data : ";
                cin >> isi_data;
                tambah_belakang_ci (isi_data);
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_ci ();
                    }
                }
            } else if (menu == 3) {
                cout << "Hapus Depan" << endl;
                hapus_depan_ci ();
                cout << "Data terhapus" << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_ci ();
                    }
                }
            } else if (menu == 4) {
                cout << "Hapus Belakang" << endl;
                hapus_belakang_ci ();
                cout << "Data terhapus" << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_ci ();
                    }
                }
            } else if (menu == 5) {
                cout << "Tampil Data" << endl;
                tampil_list_ci ();
                cout << endl;
                cout << "Lanjut (y/t) ? : ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || 'Y') {
                    keluar = true;
                    if (keluar == true) {
                        system("clear");
                        menu_ci ();
                    }
                }
            } else if (menu == 6) {
                system ("clear");
                main ();
            } else {
                cout << "Pilihan tidak ada" << endl;
            }
}

void menu_keluar () {
    cout << "Keluar (y/t) ?";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y') {
                    cout << "Sampai Jumpa Kembali" << endl;
                    keluar = true;
                } else {
                    system ("clear");
                }
}

int main() {
    inisialisasi();

    cout << "Program Single Linked List" << endl;
    cout << "1. Linked List Non Circular" << endl;
    cout << "2. Linked List Circular" << endl;
    cout << "3. Keluar" << endl;
    cout << "Silahkan pilih menu (1 - 2) :  ";
    cin >> menu;

    system("clear");

    switch (menu) {
        case 1:
            menu_nc ();
            break;

        case 2:
            menu_ci ();
            break;

        case 3:
            menu_keluar ();
            break;
        
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
    }
    
    return 0;
}
