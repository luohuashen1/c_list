#include<stdlib.h>
#include<iostream>
#include"list.h"
using namespace std;

/*
* ��ʼ��ͷ�ڵ�
* @head ͷ�ڵ�ָ��ĵ�ַ
*/
void initHeadNode(List** head)
{
	List* t = (List*)malloc(sizeof(List));
	if (t == NULL)
	{
		cout << "initHeadNode_Error:Memory allocation failure!" << endl;//���ڴ��������׳�����
		exit(-1);
	}
	t->dataHead = NULL;//��ʼ�����������Ϊ��
	t->dataTail = NULL;
	t->dataNodeNum = 0;
	*head = t; //�޸ĵ�ַ����head
}

/*
* ͷ�巨��������
* @listHead ͷ�ڵ�ָ��
* @val ����������
* return ͷ�ڵ�ָ��
*/
List* headInsert(List* listHead, int val)
{
	if (listHead == NULL)//��ͷ�ڵ�Ϊ��ʱ���׳�����
	{
		cout << "headInsert_Error:The header node has not been initialized!";
		return listHead;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));//����������Ľڵ�
	if (newNode == NULL)
	{
		cout << "headInsert_Error:Memory allocation failure!" << endl;//���ڴ��������׳�����
		exit(-1);
	}
	newNode->val = val;//����½ڵ�������
	newNode->next = listHead->dataHead;
	listHead->dataHead = newNode;
	if (listHead->dataTail == NULL)//��������Ϊ��ʱ����newNode��Ϊ������β��
		listHead->dataTail = newNode;
	listHead->dataNodeNum++;//��¼�������ڵ���
	return listHead;
}

/*
* β�巨��������
* @listHead ͷ�ڵ�ָ��
* @val ����������
* return ͷ�ڵ�ָ��
*/
List* tailInsert(List* listHead, int val)
{
	if (listHead == NULL)//��ͷ�ڵ�Ϊ��ʱ���׳�����
	{
		cout << "tailInsert_Error:The header node has not been initialized!";
		return listHead;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));//����������Ľڵ�
	if (newNode == NULL)
	{
		cout << "tailInsert_Error:Memory allocation failure!" << endl;//���ڴ��������׳�����
		exit(-1);
	}
	newNode->val = val;//����½ڵ�������
	newNode->next = NULL;
	if (listHead->dataTail == NULL)//��������Ϊ��ʱ����newNode��Ϊ������ͷ��
	{
		listHead->dataHead = newNode;
		
	}
	else//����������Ϊ��ʱ����������β�����½ڵ�
	{
		listHead->dataTail->next = newNode;
	}
	listHead->dataTail = newNode;//�½ڵ��Ϊ����β
	listHead->dataNodeNum++;//��¼�������ڵ���
	return listHead;
}

/*
* ��ӡ����������������
* @listHead ͷ�ڵ�ָ��
*/
void showDataList(List* listHead)
{
	if (listHead == NULL)//��ͷ�ڵ�Ϊ��ʱ���׳�����
	{
		cout << "showDataList_Error:The header node has not been initialized!";
		return ;
	}
	Node* temp = listHead->dataHead;//����������ͷ�ڵ�
	if (temp == NULL)//��������Ϊ��ʱ���׳�����
	{
		cout << "showDataList_Error:Data_list is a void_list!";
		return;
	}
	cout << "showDataList:";
	//����������������ӡ���д洢����
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

/*
* ɾ���������е�һ��ֵΪval�Ľڵ�
* @listHeadͷ�ڵ�ָ��
* @val ��ɾ��ֵ
* 
*/
void delDataListNode_Val(List* listHead, int val)
{
	if (listHead == NULL)//��ͷ�ڵ�Ϊ��ʱ���׳�����
	{
		cout << "delDataListNode_Val_Error:The header node has not been initialized!";
		return;
	}
	Node* head = listHead->dataHead;//����������ͷ�ڵ�
	if (head == NULL)//��������Ϊ��ʱ���׳�����
	{
		cout << "delDataListNode_Val_Error:Data_list is a void_list!";
		return;
	}
	listHead->dataNodeNum--;
	if (head->val == val)//����һ���ڵ�Ϊ��ɾ���Ľڵ�ʱ
	{
		cout << "delDataList_Val:" << val << endl;
		listHead->dataHead = head->next;//��ͷ
		free(head);
		return;
	}
	//����������һ���ڵ㲻�Ǵ�ɾ���ڵ�
	Node* betemp = NULL;//����һ����ʱ���������������ɾ���ڵ����һ���ڵ���Ϣ
	int flag = 1;//����һ����־����¼�Ƿ���ɾ������
	//����������Ѱ�Ҵ�ɾ���Ľڵ�
	while (head->val != val)
	{
		betemp = head;
		if (head->next == NULL && head->val != val)//�������������������δ����ɾ������
		{
			flag = 0;//��ձ�־λ����ʾδ����ɾ������
			break;//����ѭ��
		}
		head = head->next;
	}
	if (flag)//���ҵ��˴�ɾ���ڵ�
	{
		cout << "delDataList_Val:" << val << endl;
		betemp->next = head->next;//����ָ��
		if (betemp->next == NULL)//����ɾ���ڵ�Ϊβ�ڵ�ʱ
			listHead->dataTail = betemp;
		free(head);//ɾ���ڵ�
	}
	else
	{//��������������δ����ɾ������ʱ
		listHead->dataNodeNum++;
		cout << "delDataListNode_Val_Error:The val no found of list!" << endl;//�׳�����
	}
}


/*
* ɾ��������������ֵΪval�Ľڵ�
* @listHead ͷ�ڵ�ָ��
* @val ��ɾ����ֵ
* 
*/
void delDataListAllNode_Val(List* listHead, Ele_t val)
{
	if (listHead == NULL)//��ͷ�ڵ�Ϊ��ʱ���׳�����
	{
		cout << "delDataListAllNode_Val_Error:The header node has not been initialized!";
		return;
	}
	Node* head = listHead->dataHead;//����������ͷ�ڵ�
	if (head == NULL)//��������Ϊ��ʱ���׳�����
	{
		cout << "delDataListAllNode_Val_Error:Data_list is a void_list!";
		return;
	}
	Node* temp = head;//����һ����ʱ��������ͷָ�����ɾ������
	Node* behead = NULL;//head��ǰ���ڵ�
	int flag = 0;//����һ����־����¼�Ƿ���ɾ��
	//�����������нڵ㣬��ɾ������ֵΪval�Ľڵ�
	while (temp != NULL)
	{
		//����һ���ڵ�Ϊ��ɾ���ڵ�ʱ
		if (head->val == val)
		{
			flag++;
			listHead->dataNodeNum--;
			head = head->next;//��headָ��head����һ���ڵ�
			listHead->dataHead = head;//��ͷ
			free(temp);//�ͷ�head����ڵ�
			temp = head;//��tempָ����head�ڵ�
			continue;//��������ѭ������ֹ��head�ڵ���Ϊ��ɾ���ڵ�δɾ��
		}

		//����ɾ���ڵ㲻Ϊ��һ��ʱ
		if (temp->val == val)
		{
			flag++;
			listHead->dataNodeNum--;
			behead->next = temp->next;//��ǰ���ڵ�ָ���ɾ���ڵ����һ���ڵ�
			free(temp);
			temp = behead->next;//����ָ��
			if (temp == NULL)//��ɾ���Ľڵ�Ϊβ�ڵ�ʱ
			{
				listHead->dataTail = behead;//��β
			}
			continue;//ɾ���ڵ��behead����Ҫ�ڱ���temp
		}
		behead = temp;//ǰ���ڵ㱸��temp
		temp = behead->next;//��ǰ���ڵ���temp����һ���ڵ�

	}
	if (flag)
	{
		cout << "delDataListAllNode_Val:This run deletes " << flag << " val = "<<val<<" nodes from the list!" << endl;//��ӡɾ���˼����ڵ�
	}
	else
	{
		cout << "delDataListAllNode_Val_Error:The val no found of list!" << endl;//��δ����ɾ��ʱ���׳�����
	}
}

/*
* ɾ��������������ͷ�ڵ��������
* @listHead ��ɾ��������ĵ�ַָ��
*/
void delAllList(List** listHead)
{
	Node* dataHead = (*listHead)->dataHead;//����������ͷ�ڵ�
	Node* temp;
	//����ɾ��������
	while (dataHead != NULL)
	{
		(*listHead)->dataNodeNum--;
		temp = dataHead;
		dataHead = dataHead->next;
		free(temp);
	}
	if (dataHead == NULL && (*listHead)->dataNodeNum == 0)//У��ɾ��
	{
		free(*listHead);
		*listHead = NULL;
		cout << "delAllList Successful!" << endl;//��ʾ�ɹ�
	}
	else
	{
		cout << "delAllList_Error!"<<endl;//�׳�����
		exit(-1);
	}
}