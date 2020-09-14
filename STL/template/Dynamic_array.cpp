//
// Created by lcx on 2020/9/9.
//

//一个简单的动态数组的案例
#include <iostream>

using namespace std;

template <typename T>
class Dynamic_array
{
public:
    //重载[]操作符
    T& operator[] (int index)
    {
        return this->mptr[index];
    }

    //构造函数
    Dynamic_array(int capacity)
    {
        this->mCapacity = capacity;
        this->mlen = 0;
        this->mptr = new T[capacity];
    }
    //拷贝构造函数
    Dynamic_array( const Dynamic_array<T> &arr );

    //重载=操作符
    Dynamic_array<T> operator= (const Dynamic_array<T> &arr)
    {
        //判断是否为空
        if(this->mptr != NULL)
        {
            delete[] this->mptr;
            this->mptr = NULL;
        }
        this->mlen = arr.mlen;
        this->mCapacity = arr.mCapacity;

        //申请空间
        this->mptr = new T[arr.mCapacity];
        for( int i = 0; i < this->mlen; i++)
        {
            //this->mptr[i] = arr[i];
            this->mptr[i] = arr.mptr[i];
        }
        return *this;
    }

    //从尾部添加元素
    void pushback( T&& val);
    //析构函数
    ~Dynamic_array()
    {
        if(this->mptr != NULL)
        {
            delete[] this->mptr;
            this->mptr = NULL;
        }
    }

private:
    int mCapacity;//数组容量
    int mlen;//数组当前元素数量
    T* mptr;//数组首地址指针
};

template <typename T>
Dynamic_array<T>::Dynamic_array( const Dynamic_array<T> &arr )
{
    this->mlen = arr.mlen;
    this->mCapacity = arr.mCapacity;

    //申请空间
    this->mptr = new T[arr.mCapacity];
    for( int i = 0; i < this->mlen; i++)
    {
        this->mptr[i] = arr.mptr[i];
    }
}

template <typename T>
void Dynamic_array<T>::pushback(T &&val)//右值引用
{
    //判断数组是否还有位置
    if(this->mlen >= this->mCapacity)
    {
        cout<<"Array is full"<<endl;
        return;
    }
    this->mptr[this->mlen] = val;
    this->mlen++;
}

int main()
{
    Dynamic_array<int> myarr(10);
    myarr.pushback(1);
    myarr.pushback(2);

    cout<<myarr[1]<<endl;

    Dynamic_array<int> myarr1(myarr);
    cout<<myarr1[0]<<endl;

    Dynamic_array<int> myarr2 = myarr;
    cout<<myarr2[0]<<endl;
    return 0;
}