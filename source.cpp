#include<iostream>
#include "avl.h"

using namespace std;

int main()
{

#ifdef CONFIG_AVL
    cout<<"AVL Tree"<<endl;
#else
    cout<<"BST"<<endl;
#endif
    //Test Case
	AvlTree avlt1;
    avlt1.findMin();
    cout<<endl;
	avlt1.insert(4);
	avlt1.insert(5);
	avlt1.insert(6);
	avlt1.insert(7);
    cout<<endl;
    avlt1.findMin();
    cout<<endl;
	avlt1.insert(3);
	avlt1.insert(2);
    avlt1.insert(1);
    cout<<endl;
    avlt1.findMin();
    cout<<endl;
    avlt1.search(5);
    avlt1.search(7);
    avlt1.search(3);
    avlt1.search(10);
    cout<<endl;
	avlt1.print();
    cout<<endl;
	avlt1.insert(16);
	avlt1.insert(15);
    cout<<endl;
	avlt1.print();
    cout<<endl;

	avlt1.insert(14);
	avlt1.insert(13);
	avlt1.insert(12);
	avlt1.insert(11);
	avlt1.insert(10);
	avlt1.insert(8);
	avlt1.insert(9);
    cout<<endl;
 
    avlt1.findMin();
    cout<<endl;
	avlt1.print();
    cout<<endl;

    avlt1.remove(7);
    avlt1.remove(8);
    avlt1.remove(12);
    avlt1.remove(13);
    cout<<endl;

    avlt1.print();
    cout<<endl;

    avlt1.remove(1);
    avlt1.remove(2);
    avlt1.remove(10);
    avlt1.remove(15);
    cout<<endl;

    avlt1.findMin();
    cout<<endl;
    avlt1.print();
    cout<<endl;
    return 0;
}