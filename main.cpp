#include <iostream>
#include <cstdlib>
//库文件
//列表
#include "List.h"
//向量
#include "Vector.h"
template <typename T>
void Show(const List<T> &L);
template <typename T>
void Show(const Vector<T> &V);
template <typename T>
void add(T &e);

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
    // cout<<lll1.operator[](2)<<endl;
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
    cout << lll1.First()->Data() << endl;
    cout << lll1.Last()->Data() << endl;
    // --count;
    cout << lll1[--count] << endl
         << endl;

    cout << lll1.deduplicate() << endl;
    Show(lll1);
    cout << endl;
    //测试列表遍历接口
    cout << "请输入增加的节点数：" << endl;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        lll1.InsertASLast(5);
    }
    cout << "size: " << lll1.Size() << endl;
    lll1.traverse(add);
    Show(lll1);
    cout << "********** Vector **********" << endl;
    //声明
    Vector<int> vec1(10);
    cout << "请输入要储存在向量中的数 1 ：" << endl;
    int num;
    cin >> num;
    for (int i = 0; i < 10; i++)
    {
        vec1.insert(num);
    }
    cout << "插入结果：" << endl;
    // for (Rank i = 0; i < 10; i++)
    // {
    //     cout << vec1[i] << " ";
    // }
    Show(vec1);

    //向量唯一化测试
    cout<<endl;
    vec1.uniquify();
    cout<<"**********有序排列唯一化："<<endl;
    Show(vec1);
    cout << "请输入要储存在向量中的数：" << endl;
    cin >> num;
    for (int i = 0; i < 10; i++)
    {
        vec1.insert(num);
    }
    Show(vec1);
    vec1.deduplicate();
    cout<<"**********无序唯一化"<<endl;
    Show(vec1);
    return 0;
}


//显示列表
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
        cout << i << "\t\t" << // L[i]
            (((pp = pp->Succ())->Pred())->Data()) << endl;
    }
    cout << endl;
}
template <typename T>
void Show(const Vector<T> &V)
{
    using std::cout;
    using std::endl;
    int n = V.size();
    int i = 0;
    cout << "Vector: " << endl;
    cout << "序号"
         << "\t\t"
         << "节点值" << endl;
    // while (i++<n)
    // {
    //     cout<<i<<"\t\t"
    //         <<V[i]<<endl;
    // }
    for (Rank i = 0; i < V.size(); i++)
    {
        //cout << V[i] << " ";
        cout<<i<<"\t\t"
            <<V[i]<<endl;
    }
}

template <typename T>
void add(T &e)
{
    e++;
}