#include <iostream>
#include <algorithm>
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

    //void insert( listNode<T> *sPtr, T value );
    //void Delete( listNode<T> *sPtr, T value );
    //void printList( listNode<T> currentPtr );
    //void isEmpty( void );
};


template <typename T>
struct linkedList {
    nodeWrapper<T>* start;

    linkedList(nodeWrapper<T>* p = nullptr) : start(p) { }
    nodeWrapper<T> begin(){ return *start;}
    nodeWrapper<T> end(){ return nodeWrapper<T>(nullptr);}
};

template<typename T>
void Insert(listNode<T> *sPtr, T value )
{
   listNode<T> *newPtr; // pointer to new node
   listNode<T> *previousPtr; // pointer to previous node in list
   listNode<T> *currentPtr; // pointer to current node in list

   newPtr = new listNode<T>; // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->value = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previousPtr = NULL;
      currentPtr = sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && value > currentPtr->value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = sPtr;
         sPtr = newPtr;
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } // end else
   } // end if
   else {
      printf( "%c not inserted. No memory available.\n", value );
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
        return;
    }

    while (L != nullptr)
    {
        cout<<*L<<" ";
        (L)++;
    }
}

int main( void )
{
    listNode<int> n1(30), n2(20, &n1), n3(10, &n2);
    nodeWrapper<int> s(&n3);
    linkedList<int> intList(&s);
    isEmpty(intList);
    printList(intList);

    int value = 20;
    auto h = find(intList.begin(), intList.end(), value);
    cout<<*h<<endl;
    int value2 = 77;

    Insert(&n2, value2);
    auto p = find(intList.begin(), intList.end(), value2);
    cout<<*p<<endl;
    printList(intList);
} // end main


