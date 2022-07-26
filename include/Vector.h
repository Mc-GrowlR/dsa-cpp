#pragma once
#define DEFAULT_CAPACITY 3 //默认初始容量（实际应用中可设置为更大）
typedef int Rank;
template <typename T>
static Rank binsearch(T *A, Rank lo, Rank hi);
template <typename T>
class Vector
{
protected:
    //规模
    Rank _size;
    //容量
    int _capacity;
    //数据区
    T *_elem;
    //空间不足时扩容
    void expand();
    //复刢数组匙间A[lo, hi)
    void copyFrom(T const *A, Rank lo, Rank hi);
    //装填因子过小时压缩
    void shrink();
    //扫描交换
    bool bubble(Rank lo, Rank hi);
    //选取最大元素
    Rank max(Rank lo, Rank hi)
    {
        if (lo < hi)
        {
            return hi;
        }
        else
        {
            return lo;
        }
    };
    void selectionSort(Rank lo, Rank hi);  //选择排序算法
    void merge(Rank lo, Rank mi, Rank hi); //弻幵算法
    void mergeSort(Rank lo, Rank hi);      //弻幵排序算法
    Rank partition(Rank lo, Rank hi);      //轴点极造算法
    void quickSort(Rank lo, Rank hi);      //快速排序算法
    void heapSort(Rank lo, Rank hi);       //堆排序（稍后结合完全堆讱解）
public:
    //只读访问接口
    //返回向量规模
    Rank size() const { return _size; };
    //取秩为r的值
    T get(int r);
    //判断向量是否为空
    bool empty() const { return !_size; }
    //判断向量是否已排序
    int disordered() const;
    //无序向量整体查找
    Rank find(T const &e) const { return find(e, 0, _size); }
    //无序向量区间查找 在[lo,hi)区间内查找元素 e
    Rank find(T const &e, Rank lo, Rank hi) const;
    Rank search(T const &e) const //有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; //有序向量匙间查找
    // 可写讵问接口
    //重载下标操作符，可以类似亍数组形式引用各元素
    T &operator[](Rank r) const
    {
        if (r < _size)
            return _elem[r];
    };
    Vector<T> &operator=(Vector<T> const &); //重载赋值操作符，以便直接克隆向量
    //初除秩为r癿元素
    T remove(Rank r);
    int remove(Rank lo, Rank hi);                        //初除秩在匙间[lo, hi)乀内癿元素
    Rank insert(Rank r, T const &e);                     //揑入元素
    Rank insert(T const &e) { return insert(_size, e); } //默讣作为末元素揑入
    void sort(Rank lo, Rank hi);                         //对[lo, hi)排序
    void sort() { sort(0, _size); }                      //整体排序
    void unsort(Rank lo, Rank hi);                       //对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  //整体置乱
    int deduplicate();                                   //无序去重
    int uniquify();                                      //有序去重
    // 遍历
    void traverse(void (*)(T &)); //遍历（使用函数指针，叧读戒尿部性修改）
    template <typename VST>
    void traverse(VST &); //遍历（使用函数对象，可全尿性修改）

    //构造函数
    Vector(int c = DEFAULT_CAPACITY)
    {
        _elem = new T[_capacity = c];
        _size = 0;
    }                                    //默认
    Vector(T const *A, Rank lo, Rank hi) //数组区间复制
    {
        copyFrom(A, lo, hi);
    }
    Vector(Vector<T> const &V, Rank lo, Rank hi) //向量区间复制
    {
        copyFrom(V._elem, lo, hi);
    }
    Vector(Vector<T> const &V) //向量整体复制
    {
        copyFrom(V._elem, 0, V._size);
    }
    //析构函数
    ~Vector() { delete[] _elem; } //释放内部空间
};

template <typename T>
void Vector<T>::expand()
{
    //当规模小于容量时，不必扩容
    if (_size < _capacity)
    {
        return;
    }
    //不必小于最小容量
    _capacity = max(_capacity, DEFAULT_CAPACITY);
    //备份原数组
    T *oldElem = _elem;
    //开辟新数组
    _elem = new T[_capacity << 1];
    for (Rank i = 0; i < _size; i++) //复制原向量内容
        _elem[i] = oldElem[i];       // T为基本类型，或已重载赋值操作符'='
    //释放原空间
    delete[] oldElem;
}
template <typename T>
void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1)
    {
        return;
    }
    if (_capacity < _size << 2)
    {
        return;
    }
    //备份
    T *oldElem = _elem;
    //分配容量减半的新空间
    _elem = new T[_capacity >>= 1]
        //复制原向量内容
        for (int i = 0; i < _size; i++)
            _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = (hi - lo) * 2];
    _size = 0;
    while (lo < hi)
    {
        _elem[_size++] = A[lo++];
    }
}

template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && e != _elem[hi])
        ;
    return hi;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
    {
        return 0;
    }
    while (hi < _size)
    {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();
    return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r)
{
    T old_data = _elem[r];
    remove(r, r + 1);
    return old_data;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (Rank i = _size; r < i; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
    {
        if (find(_elem[i], 0, i) < 0)
        {
            i++;
        }
        else
        {
            remove(i);
        }
    }
    return oldSize - _size;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

template <typename T>
template <typename VST>              //元素类型、操作器
void Vector<T>::traverse(VST &visit) //倚劣函数对象机刢
{
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
} //遍历向量

template <typename T>
int Vector<T>::disordered() const
{
    int num = 0;
    for (int i = 1; i < _size; i++)
    {
        if (_elem[i - 1] > _elem[i])
        {
            //若是逆序则计数
            num++;
        }
    }
    return num;
}

template <typename T>
int Vector<T>::uniquify()
{
    //声明双指针
    Rank i = 0, j = 0;
    while (++j < _size)
    {
        if (_elem[i - 1] !=)
        {
            _elem[++i] = _elem[j];
        }
    }
    _size = ++i;
    shrink();
    return j - i;
}

template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    binSearch(_elem, e, lo, hi);
}

//有序向量查找
template <typename T>
static Rank binsearch(T *A, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mi = (lo + hi) >> 1;
        if (e < _elem[mi])
        {
            mi = hi;
        }
        else if (e > _elem[mi])
        {
            mi = lo;
        }
        else
        {
            return mi;
        }
    }
    return -1;
}
