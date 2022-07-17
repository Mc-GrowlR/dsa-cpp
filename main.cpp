#include <iostream>
#include <cstdlib>

#include "List.h"

template <typename T>
void Show(const List<T> &L);

template <typename T>
void add(T&e );

int main()
{
    using namespace std;
    List<int> lll1;
    
    cout << "size: " << lll1.Size() << endl;
    /*
    ListNode<int> *ppp = lll1.InsertAsFirst(5);
    cout << "size: " << lll1.Size() << endl;
    cout << "ppp 储存的值：" << ppp->Data() << endl;
    lll1.Remove(ppp);
    cout << "size: " << lll1.Size() << endl;
    */
    int count;
    cin >> count;
    
    for (int i = 0; i < count; i++)
    {
        lll1.InsertASLast(5);
    }
    cout << "size: " << lll1.Size() << endl;
    //cout<<lll1.operator[](2)<<endl;
    Show(lll1);
    /*
    lll1.InsertAsFirst(5);
    cout << endl
         << lll1.Find(0)->Data() << endl;*/
    // lll1.InsertAsFirst(5);
    // if (lll1.valid(lll1.Last()) && lll1.valid(lll1.First()))
    // {
    //     /* code */
    //     cout<<"zhengque"<<endl;;
    //     cout<<"size:"<<lll1.Size()<<endl;
    //     cout<<lll1.First()->Data()<<endl;
    //     cout<<lll1.Last()->Data()<<endl;
    // }
    // else{
    //     cout<<"cuowu"<<endl;
    // }
    cout<<lll1.First()->Data()<<endl;
    cout<<lll1.Last()->Data()<<endl;
    // --count;
    cout << lll1[--count]<<endl<<endl;

    cout<<lll1.deduplicate()<<endl;
    Show(lll1);
    cout<<endl;


    //测试列表遍历接口
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        lll1.InsertASLast(5);
    }
    cout << "size: " << lll1.Size() << endl;
    lll1.traverse(add);
    Show(lll1);
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

            /* code */
            cout << i << "\t\t" << // L[i]
              (((pp = pp->Succ())->Pred())->Data()) << endl;    
        
    }
    cout << endl;
}

template <typename T>
void add(T&e )
{
    e++;
}