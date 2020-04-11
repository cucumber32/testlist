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
	void printList(SqList& L);						// 输出线性表
	bool ListInsert(SqList& L, int i, ElemType e);	// 插入元素e
	bool ListDelete(SqList& L, int i, ElemType& e); // 删除第i个元素
	ElemType GetElem(SqList L, int i);				// 查询第i个元素
	int locateElem(SqList L, ElemType e);			// 查找值为e的元素次序
	int getLength(SqList L);						// 获取线性表的长度

	// 练习
	bool deleteMinElem(SqList &L, ElemType& e);								// 删除最小值的元素（假设唯一）
	void ListReverse(SqList& L);											// 逆置顺序表
	bool deleteElem(SqList& L, ElemType e);									// 删除所有值为e的元素
	bool deleteSeqElemFromMin2Max(SqList& L, ElemType min, ElemType max);	// 删除有序表min-max之间的所有元素
	bool deleteElemFromMin2Max(SqList& L, ElemType min, ElemType max);		// 删除顺序表中min-max之间的所有元素（包含min、max）
	void SingleList(SqList& L);												// 有序顺序表去重
	SqList unionSqList(SqList L1, SqList L2);								// 合并两个有序顺序表
};

/****** 工具函数：输出线性表 ********/
template <typename ElemType>
void SqList<ElemType>::printList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
}

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
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

/****** 删除第i个元素 ******/
template <typename ElemType>
bool SqList<ElemType>::ListDelete(SqList& L, int i, ElemType& e) {
	if (i < L.length || i < 1) {
		return false;
	}
	e = L.data[i];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

/****** 查找第i个元素 ******/
template <typename ElemType>
ElemType SqList<ElemType>::GetElem(SqList L, int i) {
	return L.data[i-1];
}

/****** 查找值为e的元素次序 ******/
template <typename ElemType>
int SqList<ElemType>::locateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) { // 这里注意，如果数据内容为结构体，那么需要特殊的判断是否相等，这里仅直接写数值类型判断
			return i + 1;
		}
	}
	return -1;
}

/****** 获取线性表的长度 ******/
template <typename ElemType>
int SqList<ElemType>::getLength(SqList L) {
	return L.length;
}

/****************************************** 下面是练习 *******************************************/

// test1
/*
** 要求：删除最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行；
*/
template <typename ElemType>
bool SqList<ElemType>::deleteMinElem(SqList &L, ElemType &e) {
	if (L.length <= 0) {
		cout << "顺序表为空，不可进行操作！" << endl;
		return false;
	}
	ElemType elem = L.data[0];
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] < elem) {
			elem = L.data[i];
		}
	}
	e = elem;
	L.data[i] = L.data[length - 1];
	L.length--;
	return true;
}

// test2
/*
** 要求：逆置顺序表的所有元素，要求算法的空间复杂度为O(1)
*/
template<typename ElemType>
void SqList<ElemType>::ListReverse(SqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[length - i - 1];
		L.data[length - i - 1] = temp;
	}
}

// test3
/*
** 要求：删除线性表中所有值为e的元素。要求时间复杂度为O(n)，空间复杂度为O(1)。
*/
template<typename ElemType>
bool SqList<ElemType>::deleteElem(SqList& L, ElemType e) {
	if (L.length <= 0) {
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != e) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test4
/*
** 要求：删除有序表中值在min-max之间的元素（min<max），如果min或max不合理或顺序表为空，显示错误信息并退出运行
*/
template<typename ElemType>
bool SqList<ElemType>::deleteSeqElemFromMin2Max(SqList& L, ElemType min, ElemType max) {
	if (min >= max || L.length == 0) {
		cout << "数据不合理，请修改参数" << endl;
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] > max || L.data[i] < min) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test5
/*
** 要求：删除线性表中值在min-max之间的元素（min<max，包含min、max），如果min或max不合理或顺序表为空，显示错误信息并退出运行
*/
template<typename ElemType>
bool SqList<ElemType>::deleteElemFromMin2Max(SqList& L, ElemType min, ElemType max) {
	if (min >= max || L.length == 0) {
		cout << "数据不合理，请修改参数" << endl;
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= max || L.data[i] <= min) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test6
/*
** 要求：从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同；
*/
template<typename ElemType>
void SqList<ElemType>::SingleList(SqList& L) {
	int k = 0;	// 重复的次数
	int j = 0;	// 不重复的元素下标
	for (int i = 1; i < L.length; i++) {
		if (L.data[j] != L.data[i]) {
			j++;
			L.data[j] = L.data[i];
		}
		else {
			k++;
		}
	}
	L.length = L.length - k;
}

// test7
/*
** 要求：合并两个有序顺序表，返回一个新的有序顺序表；
*/
template<typename ElemType>
SqList<ElemType> SqList<ElemType>::unionSqList(SqList L1, SqList L2) {
	SqList<ElemType> L;
	L.InitList(L);
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] <= L2.data[j]) {
			L.data[k] = L1.data[i];
			i++;
		}
		else {
			L.data[k] = L2.data[j];
			j++;
		}
		k++;
	}
	while (i < L1.length) {
		L.data[k] = L1.data[i];
		i++;
		k++;
	}
	while (j < L2.length) {
		L.data[k] = L2.data[j];
		j++;
		k++;
	}
	L.length = k;
	return L;
}