#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

template<typename T>
struct listNode {
   T value; // each listNode contains a character
   listNode<T> *nextPtr; // pointer to next node

   listNode(T val = 0, listNode<T>* p = nullptr) : value(val), nextPtr(p){}//constructor

   T operator*() const {return value;}
}; // end structure listNode
template<typename T, typename Reference, typename Pointer>
struct nodeWrapperBase
:public iterator<forward_iterator_tag, T, ptrdiff_t, Pointer, Reference>{ };

template<typename T>
struct nodeWrapper: public nodeWrapperBase<T, T&, T*>{

    listNode<T> *ptr;
    nodeWrapper(listNode<T>* p = nullptr) : ptr(p){ }

    T& operator*()const{return ptr->value;}
    T* operator->()const{return ptr;}
    nodeWrapper&operator++(){ptr = ptr->nextPtr;return *this;}
    nodeWrapper operator++(int){nodeWrapper tmp = *this;ptr = ptr ->nextPtr;return tmp;}

    bool operator ==(const nodeWrapper& i)const {return ptr == i.ptr;}
    bool operator !=(const nodeWrapper& i)const {return ptr != i.ptr;}
};


template <typename T>
struct linkedList {
    nodeWrapper<T>* start;

    linkedList(nodeWrapper<T>* p = nullptr) : start(p) { }
    nodeWrapper<T> begin(){ return *start;}
    nodeWrapper<T> end(){ return nodeWrapper<T>(nullptr);}
};

template<typename T>
void Insert(linkedList<T>& List, T value )
{
    cout<<"Insert value "<<value<<endl;
    nodeWrapper<T> L;
    if(List.start != nullptr){
        L = *List.start;
    }
    listNode<T> *newPtr; // pointer to new node
    listNode<T> *previousPtr; // pointer to previous node in list
    listNode<T> *currentPtr; // pointer to current node in list


    newPtr = new listNode<T>; // create node

    if ( newPtr != nullptr ) { // is space available
        newPtr->value = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node


        previousPtr = NULL;
        currentPtr = L.ptr;


      // loop to find the correct location in the list
        while ( currentPtr != nullptr && value > currentPtr->value) {
            previousPtr = currentPtr; // walk to ...

            currentPtr = currentPtr->nextPtr; // ... next node
        } // end while
      // insert new node at beginning of list
        if ( previousPtr == nullptr ) {
            newPtr->nextPtr = L.ptr;
            L.ptr = newPtr;
            List.start = &L;
        } // end if
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } // end else

   } // end if
   else {
      cout<<value<<" not inserted. No memory available."<<endl;
   } // end else
} // end function insert


template<typename T>
void isEmpty(linkedList<T> List){
    if(List.start==nullptr)
        cout<<"List is empty"<<endl;
    else
        cout<<"List is not empty"<<endl;
}


template<typename T>
void printList(linkedList<T> List)
{
    nodeWrapper<T> L = *List.start;
    if (L == nullptr)
    {
        cout<<"The list is empty!"<<endl;
        return;
    }

    while (L != nullptr)
    {
        cout<<*L<<" ";
        (L)++;
    }
    cout<<endl<<endl;
}

template<typename T>
void Delete(linkedList<T> List, T value){
    cout<<"Delete value "<<value<<endl;
    listNode<T> *current = List.start->ptr, *previous = nullptr;
    while (current != nullptr && current->value != value) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->nextPtr;                  // 或是current->data == x
    }                                             // 即結束while loop

    if (current == nullptr) {                 // list沒有要刪的node, 或是list為empty
        cout << "There is no " << value << " in list.\n";
        // return;
    }
    else if (current == List.start->ptr) {        // 要刪除的node剛好在list的開頭
        List.start->ptr = current->nextPtr;          // 把first移到下一個node
        free(current);                 // 如果list只有一個node, 那麼first就會指向NULL
        current = nullptr;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
        // return;
    }
    else {                              // 其餘情況, list中有欲刪除的node,
        previous->nextPtr = current->nextPtr; // 而且node不為first, 此時previous不為NULL
        free(current);
        current = nullptr;
        // return;
    }
}

template<typename T>
void test(linkedList<T> List,T value){
    cout<<"I want to find value "<<value<<endl<<endl;
    auto h = find(List.begin(), List.end(), value);
    if(h == nullptr)
        cout<<"It can't find value in the list."<<endl;

    Insert(List, value);

    printList(List);

    Delete(List,value);

    printList(List);
}
int main( void )
{
    listNode<int> n1(90), n2(20, &n1), n3(10, &n2);
    nodeWrapper<int> s(&n3);
    linkedList<int> intList(&s);
    for(int i=0;i<50;i++){
        int m = rand() % 100;
        test(intList,m);
    }
    linkedList<double> L;

    Insert(L,1.1);
    test(L,1.2);
}



