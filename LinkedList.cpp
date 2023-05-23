
#include "LinkedList.h"
#include <iostream>
using namespace std;

// Return type name of class::name of function/constructor (parameters)
//make sure it works if list is empty

// default constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

//copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
        head = nullptr;
    
    Node *p = head;
    for (int i = 0; i< rhs.size(); i++){
        Node *n = new Node;
        if (i == 0){
            head = n;
        }
        else {
            p->next = n;
        }
        string x;
        rhs.get(i,x);
        n->value = x;
        n->next = nullptr;
        p = n;
    }
}

// destructor
LinkedList::~LinkedList()
{
    Node *p;
    p = head;
    while (p!= nullptr){
        Node *n = p->next;
        delete p;
        p = n;
    }
}

// assignment operator
 const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
     if (&rhs == this) {

         return *this;

        }

        Node *p;

        p = head;

        while (p!= nullptr){

            Node *n = p->next;

            delete p;

            p = n;

        }

     

        head = nullptr;

     

        Node *p2 = head;

        for (int i = 0; i< rhs.size(); i++){

            Node *n2 = new Node;

            if (i == 0){

                head = n2;

            }

            else {

                p2->next = n2;

            }

            string x;

            rhs.get(i,x);

            n2->value = x;

            n2->next = nullptr;

            p2 = n2;

        }

        return *this;
 }

// Inserts val at the front of the list
 void LinkedList::insertToFront(const ItemType &val)
{
     Node *p;
     p = new Node;
     p->value = val;
     p->next = head;
     head = p;
 }

// Prints the LinkedList
void LinkedList::printList() const
{
    Node *p;
    p = head;
    while (p != nullptr){
        cout << p-> value << " ";
        p = p->next;
    }
    cout << endl;
}

// Sets item to the value at position i in this
 // LinkedList and return true, returns false if
 // there is no element i
 bool LinkedList::get(int i, ItemType& item) const
{
    Node *p;
    p = head;
   int count = 0;
    while (p!=nullptr){
        if (count == i){
            item = p->value;
            return true;
        }
        p = p->next;
        count++;
    }
    
    return false;
}


// Reverses the LinkedList
 void LinkedList::reverseList()
{
     if (head == nullptr)
         return;
     Node *prev = nullptr;
     Node *current = nullptr;
     Node *next = nullptr;
     current = head;
     while (current != nullptr){
         next = current -> next;
         current->next = prev;
         prev = current;
         current = next;
     }
     head = prev;
 }

 // Prints the LinkedList in reverse order
 void LinkedList::printReverse() const
{
    int size = this->size();
    for (int i = size; i > 0; i--){
        string x;
        this->get(i-1, x);
        cout << x << " ";
    }
    cout << endl;
}

 // Appends the values of other onto the end of this
 // LinkedList.
 void LinkedList::append(const LinkedList &other)
{
     Node *p;
     p = other.head;
     while (p!= nullptr){
         if (head == nullptr)
             insertToFront(p->value);
         else {
             Node *q;
             q = head;
             while (q->next!=nullptr)
                 q = q->next;
             Node *n = new Node;
             n->value = p->value;
             q->next = n;
             n->next = nullptr;
         }
         p = p->next;
     }
 }

 // Exchange the contents of this LinkedList with the other
 // one.
 void LinkedList::swap(LinkedList &other)
{
     LinkedList temp = other;

      

     if (head == nullptr) {

        other.head = nullptr;

        append(temp);

        return;

     }

      if (other.head == nullptr) {

       temp = *this;

       other.append(temp);

       head = nullptr;

       return;

      }

     Node *p;

     p = head;

     Node *o;

     Node *o1 = nullptr;

     o = other.head;

      

     while (p != nullptr) {

       if (o != nullptr) {

       o->value = p->value;

       p = p->next;

       o1 = o;

       o = o->next;

       } else {

        Node *n = new Node;

        n->value = p->value;

        p = p->next;

        n->next = nullptr;

        o1->next = n;

        o1 = n;

       }

     }

     if (o1 != nullptr) {

     o1->next = nullptr;

     }

      

     Node *p2;

     p2 = temp.head;

     Node *f;

     Node *f1 = nullptr;

     f = head;

     while (p2 != nullptr) {

       if (f != nullptr) {

       f->value = p2->value;

       p2 = p2->next;

       f1 = f;

       f = f->next;

       } else {

        Node *n2 = new Node;

        n2->value = p2->value;

        p2 = p2->next;

        n2->next = nullptr;

        f1->next = n2;

        f1 = n2;

       }

      

     }

     if (f1 != nullptr) {

     f1->next = nullptr;
 }
 }

 // Returns the number of items in the Linked List.
 int LinkedList::size() const
{
    int count = 0;
    Node *p;
    p = head;
    while (p != nullptr){
        p = p-> next;
        count++;
    }
    return count;
}
