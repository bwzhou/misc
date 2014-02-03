#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
    int NUMS = 4000;
    const int GAP  =   3711;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );

    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );

    if( NUMS < 40 )
        t.printTree( );
    if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 2 )
        cout << "FindMin or FindMax error!" << endl;

    for( i = 2; i < NUMS; i+=2 )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < NUMS; i+=2 )
    {
        if( t.contains( i ) )
            cout << "Find error2!" << endl;
    }

    BinarySearchTree<int> t2;
    t2 = t;

    for( i = 2; i < NUMS; i+=2 )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < NUMS; i+=2 )
    {
        if( t2.contains( i ) )
            cout << "Find error2!" << endl;
    }

    BinarySearchTree<int> t3;
    vector<int> v;

    for (i = 0; i < NUMS; ++i) {
      v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for (auto &each : v) {
      t3.insert(each);
    }

    for (i = 0; i < 200; ++i) {
      int curr = rand() % NUMS;
      int succ = t3.succ(curr);
      int pred = t3.pred(curr);
      if (curr != (succ + pred) / 2) {
        cout << "Error: " << curr << " succ " << succ << " pred " << pred << endl;
      }
    }

    cout << "Finished testing" << endl;

    return 0;
}
