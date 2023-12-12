#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "SeqStack.h"

template<class ElemType>
class Queue  //用两个栈实现队列
{
protected:
	SeqStack<ElemType> s1;
	SeqStack<ElemType> s2;
	int maxSize;  //队列最大容量

public:
	//Queue(int size = DEFAULT_SIZE);             // 构造函数
	//virtual ~Queue();							// 析构函数
	void Push(const ElemType e);                // 入队
	void Pop(ElemType& e);                      // 出队
	bool IsEmpty() const;                       // 判断队列是否为空
	void Traverse(void (*Visit)(const ElemType&)) const;	// 遍历队列
};

//用两个栈实现队列的实现部分

//template<class ElemType>
//Queue<ElemType>::Queue(int size) :maxSize(size)
//{
//	s1(maxSize);
//	s2(maxSize);
//}
//
//template<class ElemType>
//Queue<ElemType>::~Queue()
//{
//	s1.~SeqStack();
//	s2.~SeqStack();
//}

template <class ElemType>
void Queue<ElemType>::Push(const ElemType e)
{
	s1.Push(e);
}

template<class ElemType>
void Queue<ElemType>::Pop(ElemType& e)
{
	ElemType ee;
	if (!s2.IsEmpty())
	{
		s2.Pop(e);
	}
	else if (!s1.IsEmpty())
	{
		while (!s1.IsEmpty())
		{
			s1.Pop(ee);
			s2.Push(ee);
		}
		s2.Pop(e);
	}
	else
	{
		cout << "队列为空！出队失败！"<<endl;
	}
}

template <class ElemType>
bool Queue<ElemType>::IsEmpty() const
{
	return s1.IsEmpty() && s2.IsEmpty();
}

template <class ElemType>
void Queue<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
	for (int i = s2.top; i >= 0; i--)
		(*Visit)(s2.elems[i]);
	for (int i = 0; i <= s1.top; i++)
		(*Visit)(s1.elems[i]);
}

#endif