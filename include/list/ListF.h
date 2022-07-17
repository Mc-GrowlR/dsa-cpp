#pragma once

#include"List.h"

//LisNode

// template <typename T>
// T ListNode<T>::Data()
// {
//     return this->_data;
// }

// template <typename T>
// ListNode<T> *ListNode<T>::Pred()
// {
//     return this->_pred;
// }

// template <typename T>
// ListNode<T> *ListNode<T>::Succ()
// {
//     return this->_succ;
// }

// template <typename T>
// ListNode<T> *ListNode<T>::ChangePred(ListNode<T> *cp)
// {
//     this->_pred = cp;
//     return this->_pred;
// }

// template <typename T>
// ListNode<T> *ListNode<T>::ChangeSucc(ListNode<T> *cs)
// {
//     this->_succ = cs;
//     return this->_succ;
// }

// template <typename T>
// T ListNode<T>::ChangeData(T const &e)
// {
//     _data = e;
// }






//List
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
ListNode<T> *List<T>::InsertAsPred(ListNode<T> *p,T const &e)
{
    ListNode<T> *iap = new ListNode(e, p->Pred(), p); //让此变量成为节点，并让该节点的前驱和后继分别指向p的前驱和p本身
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
    return this->InsertAsPred(this->_trailer,e);
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
        if (e == (p = p->Pred())->Data())
        {
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
    ListNode<T> *p = _header->Succ();
    while (0 < _size--)
    {
        Remove((p = p->Succ())->Pred());
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

template <typename T>
T List<T>::operator[](Rank r) const
{
    ListNode<T>* p = this->First();
    while (0<r--)
    {
        p=p->Succ();
    }
    T a = p->Data();
    return a;
}
template <typename T>
int List<T>::deduplicate()
{
    if (_size < 2)
    {
        return 0;
    }
    //记录原规模
    int OldSize = _size;
    ListNode<T>* p = _header;
    Rank r = 0;
    //
    while (_trailer != (p=p->_succ))
    {
        if (ListNode<T>* q = Find(p->Data(),r,p))
            Remove(q);
        else
            r++;
        //p->ChangeSucc(p->Succ());
    }
    return OldSize - _size;
}
template <typename T>
void List<T>::traverse(void (*visit)(T &))
{
    for (ListNode<T>* p =_header->Succ();p!=_trailer;p=p->Succ())
        visit(p->_data);
}