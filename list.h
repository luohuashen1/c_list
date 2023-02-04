#pragma once
#ifndef __LIST_H__
#define __LIST_H__

typedef int Ele_t;
typedef char Ele_s;

typedef struct node {
	Ele_t val;
	struct node* next;
}Node;

typedef struct list {
	Node* dataTail;
	Node* dataHead;
	Ele_t dataNodeNum;

}List;

/*
* 初始化头节点
* @head 头节点指针的地址
*/
void initHeadNode(List** head);

/*
* 头插法插入数据
* @listHead 头节点指针
* @val 待插入数据
* return 头节点指针
*/
List* headInsert(List* listHead, int val);

/*
* 尾插法插入数据
* @listHead 头节点指针
* @val 待插入数据
* return 头节点指针
*/
List* tailInsert(List* listHead, int val);

/*
* 打印数据链的所有数据
* @listHead 头节点指针
*/
void showDataList(List* listHead);

/*
* 删除数据链中第一个值为val的节点
* @listHead头节点指针
* @val 待删除值
*
*/
void delDataListNode_Val(List* listHead, int val);

/*
* 删除数据链中所有值为val的节点
* @listHead 头节点指针
* @val 待删除的值
*
*/
void delDataListAllNode_Val(List* listHead, Ele_t val);

/*
* 删除整个链表，包括头节点和数据链
* @listHead 待删除的链表的地址指针
*/
void delAllList(List** listHead);

#endif // !__LIST_H__
