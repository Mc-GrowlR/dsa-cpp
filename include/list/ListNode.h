//# pragma once

typedef int Rank;

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

public:
    
    
    //ADT
    //获取节点数据
    T Data();
    //获取节点前驱位置
    ListNode<T>* Pred();
    ListNode<T>* Succ();
    //获取后继前驱位置
    
    //改变前驱
    ListNode<T>* ChangePred(ListNode<T>* cp);
    //改变后继
    ListNode<T>* ChangeSucc(ListNode<T>* cs);
    
    //构造函数
    ListNode() {};
    ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr) : _data(e), _pred(p), _succ(s) {};
    //析构函数
    ~ListNode() {};
};
template <typename T>
T ListNode<T>::Data()
{
    return  this->_data;
}

template <typename T>
ListNode<T>* ListNode<T>::Pred()
{
    return this->_pred;
}

template <typename T>
ListNode<T>* ListNode<T>::Succ()
{
    return this->_succ;
}

template <typename T>
ListNode<T>* ListNode<T>::ChangePred(ListNode<T>* cp)
{
    this->_pred = cp;
    return this->_pred;
}

template <typename T>
ListNode<T>* ListNode<T>::ChangeSucc(ListNode<T>* cs)
{
    this->_succ = cs;
    return this->_succ;
}