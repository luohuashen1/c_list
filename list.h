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
* ��ʼ��ͷ�ڵ�
* @head ͷ�ڵ�ָ��ĵ�ַ
*/
void initHeadNode(List** head);

/*
* ͷ�巨��������
* @listHead ͷ�ڵ�ָ��
* @val ����������
* return ͷ�ڵ�ָ��
*/
List* headInsert(List* listHead, int val);

/*
* β�巨��������
* @listHead ͷ�ڵ�ָ��
* @val ����������
* return ͷ�ڵ�ָ��
*/
List* tailInsert(List* listHead, int val);

/*
* ��ӡ����������������
* @listHead ͷ�ڵ�ָ��
*/
void showDataList(List* listHead);

/*
* ɾ���������е�һ��ֵΪval�Ľڵ�
* @listHeadͷ�ڵ�ָ��
* @val ��ɾ��ֵ
*
*/
void delDataListNode_Val(List* listHead, int val);

/*
* ɾ��������������ֵΪval�Ľڵ�
* @listHead ͷ�ڵ�ָ��
* @val ��ɾ����ֵ
*
*/
void delDataListAllNode_Val(List* listHead, Ele_t val);

/*
* ɾ��������������ͷ�ڵ��������
* @listHead ��ɾ��������ĵ�ַָ��
*/
void delAllList(List** listHead);

#endif // !__LIST_H__
