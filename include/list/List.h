#pragma once

#include "ListNode.h"

typedef int Rank;



//ListNode
// template <typename T>
// class ListNode
// {
// private:
//     /*数据*/
//     T _data;
//     /*前驱*/
//     ListNode<T> *_pred;
//     /*后继*/
//     ListNode<T> *_succ;
//     friend void List<T>::traverse(void* (*visit)(T&));
// public:
//     // ADT
//     //获取节点数据
//     T Data();
//     //获取节点前驱位置
//     ListNode<T> *Pred();
//     //获取后继前驱位置
//     ListNode<T> *Succ();

//     //改变前驱
//     ListNode<T> *ChangePred(ListNode<T> *cp);
//     //改变后继
//     ListNode<T> *ChangeSucc(ListNode<T> *cs);
//     //改变数据
//     T ChangeData(T const &e);

//     //构造函数
//     ListNode(){};
//     ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr) : _data(e), _pred(p), _succ(s){};
//     //析构函数
//     ~ListNode(){};

// };



//List
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
    ListNode<T> *Last() const {  return _trailer->Pred(); }

    //插入e节点（e为数据）为首节点
    ListNode<T> *InsertAsFirst(T const &e);
    //插入e节点（e为数据）为末节点
    ListNode<T> *InsertASLast(T const &e);
    //将e节点（e为数据）作为P的前驱插入
    ListNode<T> *InsertAsPred(ListNode<T> *p,T const &e);
    //将e节点（e为数据）作为P的后继插入
    ListNode<T> *InsertAsSucc(ListNode<T> *p, T const &e);

    //删除p节点位置的节点
    T Remove(ListNode<T> *p);

    //在 p 位置的 n 个前驱中查找目标元素 e
    ListNode<T> *Find(T const &e, int n, ListNode<T> *p) const;
    //无序列表：
    // 在整个列表中查找目标元素 e
    ListNode<T> *Find(T const &e) const;

    //判断 p 节点位置是否合法
    //判断 p 节点是否为 nullptr 和 p 是否为头尾节点
    bool valid(ListNode<T>* p) { return p && (_trailer != p) && (_header != p); }
    
    
    //寻秩访问
    T operator[] (Rank r) const;
    
    //唯一化，剔除无序列表中的重复节点,并返回规模变化量（变化量类型为 int ）
    int deduplicate();
    
    //遍历接口：批量式节点访问，并对节点进行批量操作
    void traverse(void (*visit)(T&));
    //构造函数
    List() { Init(); };

    //析构函数
    ~List();
};

#include"ListF.h"