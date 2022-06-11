#include <iostream>

using namespace std;

struct node {
    string data;
    node *next;
    node *prev;
};

node *head;
node *tail;
node *entry;
node *print;

void init () {
    head = NULL;
    tail = NULL;
}

bool isEmpty () {
    if (head == NULL) {
        return 1;
    } else
        return 0;
}

void input(string data_masuk)
{
      entry = new node;
      entry->data = data_masuk;
      entry->next = NULL;
      entry->prev = NULL;
      if(isEmpty()==1)
      {
            head = entry;
            head->next = NULL;
            head->prev = NULL;
            tail=head;
      }
      else
      {
            tail->next = entry;
            entry->prev = tail;
            tail = entry;
      }
}

void cetak()
{
    print = head;
    if(head!=NULL) {
        while(print!=NULL) {
            cout << print->data << " ";
            print = print->next;
        }
    } else
        cout<<"\nTidak ada data dalam linked list"<<endl;
}

int main () {

    cout << endl << endl;

    init ();
    input ("Fauzi");
    cetak ();

    cout << endl << endl;

    return 0;
}