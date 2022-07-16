# pragma once

#include"ListNode.h"

template <typename T> 
class List
{
private:
    /* data */
    //列表规模
    int _size;
    //头节点
    ListNode<T>* _header;
    //尾节点
    ListNode<T>* _trailer;
public:
    //列表初始化
    void Init();
    //清除列表
    int clear();
    //判空
    bool Empty() const {return _size <= 0;};
    //返回列表规模
    Rank Size() const {return _size;}
    //返回首节点位置
    ListNode<T>* first() const { return _header._succ;}
    //返回末节点位置
    ListNode<T>* last() const { return _trailer._pred;}
    //插入节点为首节点
    ListNode<T>* InsertAsFirst(T const& e);
    //插入节点为末节点
    ListNode<T>* InsertASLast(T const& e);
    //将e节点作为P的后继插入
    ListNode<T>* InsertAsPred(ListNode<T>* p,T const& e);
    //将e节点作为P的前驱插入
    ListNode<T>* InsertAsSucc(T const& e,ListNode<T>* p);
    
    //删除P节点位置的节点
    T Remove(ListNode<T>* p);




    //构造函数
    List() {Init();};

    //析构函数
    ~List();
};


template <typename T>
void List<T>::Init()
{
    //创建头尾节点
    this->_header = new ListNode<T>;
    this->_trailer = new ListNode<T>;

    


    /* 错误
    //
    this->_header->_pred = nullptr;
    this->_header->_succ = this->_trailer->_pred;
    //
    this->_trailer->_succ = nullptr;
    this->_trailer->_pred = this->_header->_succ;
    //
    this->_size = 0;
    */
}

template <typename T>
List<T>::~List()
{
    delete this->_header;
    delete this->_trailer;
}