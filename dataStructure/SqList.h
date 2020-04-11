#include<iostream>
using namespace std;

#define INITSIZE 100 // 顺序表的初始大小

template <typename ElemType>
class SqList {
	// 顺序表的属性
	ElemType* data;	// 顺序表动态存储空间的首地址
	int listSize;	// 顺序表目前已分配的存储空间大小
	int length;		// 顺序表当前个数

public:
	// 顺序表的方法
	void InitList(SqList& L);						// 初始化线性表
	//Elemtype getLength(SqList L);					// 获取线性表的长度
	//Elemtype locateElem(SqList L, int e);			// 查找具体值的元素
	//Elemtype GetElem();
	bool ListInsert(SqList& L, int i, ElemType e);	// 插入元素e
};

/****** 初始化线性表 ****/
template <typename ElemType>
void SqList<ElemType>::InitList(SqList& L) {
	L.length = 0;
	L.data = new ElemType[INITSIZE]; // 动态申请存储空间【如果需要增加长度，则重新开辟空间，将内容复制进新空间，释放旧空间
	L.listSize = INITSIZE;
}

/****** 插入元素e ******/
template <typename ElemType>
bool SqList<ElemType>::ListInsert(SqList& L, int i, ElemType e) {
	if (i > L.length + 1 || i < 1) {
		return false;
	}
	if (L.listSize == L.length) {
		return false;
	}
	for (int j = L.length; j-1 > i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}