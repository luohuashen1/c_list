#pragma once
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int Ele_t;
typedef char Ele_s;

typedef struct node {
	Ele_t val;
	struct node* next;
}Node;

Node* initList(unsigned int n);
Node* headInsert(Node* head, int val);
Node* tailInsert(Node* head, int val);
void showLinklist(Node* head);
Node* delLinkList(Node* head);
Node* delNode(Node* head, int val);
int nodeNum(Node* head);
Node* upInsert(Node* head, int val);
Node* delAllNode(Node* head, Ele_t val);
bool isUpList(Node* head);
Node* inversionAllList(Node* head);
int maxList(Node* head);
int sumList(Node* head);
Node* listMidPoint(Node* head);

#endif