#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "SeqStack.h"

template<class ElemType>
class Queue  //������ջʵ�ֶ���
{
protected:
	SeqStack<ElemType> s1;
	SeqStack<ElemType> s2;
	int maxSize;  //�����������

public:
	//Queue(int size = DEFAULT_SIZE);             // ���캯��
	//virtual ~Queue();							// ��������
	void Push(const ElemType e);                // ���
	void Pop(ElemType& e);                      // ����
	bool IsEmpty() const;                       // �ж϶����Ƿ�Ϊ��
	void Traverse(void (*Visit)(const ElemType&)) const;	// ��������
};

//������ջʵ�ֶ��е�ʵ�ֲ���

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
		cout << "����Ϊ�գ�����ʧ�ܣ�"<<endl;
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