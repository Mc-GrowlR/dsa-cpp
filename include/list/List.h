#pragma once

#include "ListNode.h"

template <typename T>
class List
{
private:
    /* data */
    //列表规模
    int _size;
    //头节点
    ListNode<T> *_header;
    //尾节点
    ListNode<T> *_trailer;

public:
    //列表初始化
    void Init();
    //清除列表
    int Clear();
    //判空
    bool Empty() const { return _size <= 0; };
    //返回列表规模
    Rank Size() const { return _size; }
    //返回首节点位置
    ListNode<T> *First() const { return _header->Succ(); }
    //返回末节点位置
    ListNode<T> *Last() const { return _trailer->Pred(); }
    //插入节点为首节点
    ListNode<T> *InsertAsFirst(T const &e);
    //插入节点为末节点
    ListNode<T> *InsertASLast(T const &e);
    //将e节点作为P的前驱插入
    ListNode<T> *InsertAsPred(T const &e, ListNode<T> *p);
    //将e节点作为P的后继插入
    ListNode<T> *InsertAsSucc(ListNode<T> *p, T const &e);

    //删除P节点位置的节点
    T Remove(ListNode<T> *p);

    //查找目标元素e
    ListNode<T> *Find(T const &e, int n, ListNode<T> *p) const;
    ListNode<T> *Find(T const &e) const;

    //构造函数
    List() { Init(); };

    //析构函数
    ~List();
};

template <typename T>
void List<T>::Init()
{
    //创建头尾节点
    this->_header = new ListNode<T>;
    this->_trailer = new ListNode<T>;

    //头节点
    this->_header->ChangePred(nullptr);
    this->_header->ChangeSucc(this->_trailer);
    //尾节点
    this->_trailer->ChangePred(this->_header);
    this->_trailer->ChangeSucc(nullptr);
    //列表规模
    this->_size = 0;
}


template <typename T>
ListNode<T> *List<T>::InsertAsPred(T const &e, ListNode<T> *p)
{
    ListNode<T> *iap = new ListNode(e, p->_pred, p); //让此变量成为节点，并让该节点的前驱和后继分别指向p的前驱和p本身
    ListNode<T> *i = p->Pred();
    i->ChangeSucc(iap); //让原前驱节点的后继变成e节点
    p->ChangePred(iap); //让p的前驱为e
    this->_size++;      //列表规模+1
    return iap;         //返回新节点的地址
}

template <typename T>
ListNode<T> *List<T>::InsertAsSucc(ListNode<T> *p, T const &e)
{
    ListNode<T> *ias = new ListNode(e, p, p->Succ());
    ListNode<T> *i = p->Succ();
    i->ChangePred(ias);
    p->ChangeSucc(ias);
    this->_size++;
    return ias;
}

template <typename T>
ListNode<T> *List<T>::InsertAsFirst(T const &e)
{
    return this->InsertAsSucc(this->_header, e);
}

template <typename T>
ListNode<T> *List<T>::InsertASLast(T const &e)
{
    return this->InsertAsPred(e, this->_trailer);
}
template <typename T>
T List<T>::Remove(ListNode<T> *p)
{
    //备份数据
    T temp_p = p->Data();
    ListNode<T> *pp = p->Pred();
    ListNode<T> *ps = p->Succ();

    pp->ChangeSucc(ps);
    ps->ChangePred(pp);

    delete p;

    this->_size--;
    return temp_p;
}

template <typename T>
ListNode<T> *List<T>::Find(T const &e, int n, ListNode<T> *p) const
{
    while (0 < n--)
    {
        /* code */
        if (e == (p = p->Pred())->Data())
        {
            /* code */
            return p;
        }
    }
    return nullptr;
}

template <typename T>
ListNode<T> *List<T>::Find(T const &e) const
{
    return this->Find(e, this->_size, this->_trailer);
}

template <typename T>
int List<T>::Clear()
{
    ListNode<T>* p = _header->Succ();
    while (0 < _size--)
    {
    //     p=p->Succ();
    //     Remove(p->Pred());
        Remove((p=p->Succ())->Pred());
    }
    return _size;
}

template <typename T>
List<T>::~List()
{
    Clear();
    delete this->_header;
    delete this->_trailer;
}
