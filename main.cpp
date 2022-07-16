#include <iostream>
#include <cstdlib>

#include "List.h"

template <typename T>
void Show(const List<T> &L);

int main()
{
    using namespace std;
    List<int> lll1;

    cout << "size: " << lll1.Size() << endl;

    ListNode<int> *ppp = lll1.InsertAsFirst(5);
    cout << "size: " << lll1.Size() << endl;
    cout << "ppp 储存的值：" << ppp->Data() << endl;
    lll1.Remove(ppp);
    cout << "size: " << lll1.Size() << endl;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        lll1.InsertAsFirst(rand() / 1000);
    }
    cout << "size: " << lll1.Size() << endl;

    Show(lll1);
    lll1.InsertAsFirst(5);
    cout << endl
         << lll1.Find(5)->Data() << endl;
    return 0;
}

template <typename T>
void Show(const List<T> &L)
{
    using std::cout;
    using std::endl;
    ListNode<T> *pp = L.First();
    int n = L.Size();
    int i = 0;
    cout << "List: " << endl;
    cout << "序号"
         << "\t\t"
         << "节点值" << endl;
    while (i++ < n)
    {
        cout << i << "\t\t" << (((pp = pp->Succ())->Pred())->Data()) << endl;
    }
    cout << endl;
}