#pragma once
#include"List.h"
typedef int Rank;

template <typename T> class List;
template <typename T>
class ListNode
{
private:
    /*数据*/
    T _data;
    /*前驱*/
    ListNode<T> *_pred;
    /*后继*/
    ListNode<T> *_succ;
    friend class List<T>;
    //friend void List<T>::traverse(void* (*visit)(T&));
public:
    // ADT

    /*获取节点数据，只读操作*/

    //获取节点数据
    T Data() const;
    //获取节点前驱
    ListNode<T> *Pred() const;
    //获取节点后继
    ListNode<T> *Succ() const;

    /*操作节点数据*/

    //改变节点前驱
    ListNode<T> *ChangePred(ListNode<T> *cp);
    //改变节点后继
    ListNode<T> *ChangeSucc(ListNode<T> *cs);
    //改变节点数据
    T ChangeData(T const &e);

    //构造函数
    ListNode(){};
    ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr) : _data(e), _pred(p), _succ(s){};
    //析构函数
    ~ListNode(){};

};
template <typename T>
T ListNode<T>::Data() const
{
    return this->_data;
}

template <typename T>
ListNode<T> *ListNode<T>::Pred() const
{
    return this->_pred;
}

template <typename T>
ListNode<T> *ListNode<T>::Succ() const
{
    return this->_succ;
}

template <typename T>
ListNode<T> *ListNode<T>::ChangePred(ListNode<T> *cp)
{
    this->_pred = cp;
    return this->_pred;
}

template <typename T>
ListNode<T> *ListNode<T>::ChangeSucc(ListNode<T> *cs)
{
    this->_succ = cs;
    return this->_succ;
}

template <typename T>
T ListNode<T>::ChangeData(T const &e)
{
    _data = e;
}