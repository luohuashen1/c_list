#include<stdlib.h>
#include<iostream>
#include"LinkList.h"
using namespace std;


Node* headInsert(Node* head, int val)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		cout << "Error!";
		exit(-1);
	}
	
	temp->val = val;
	if (head == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = head;
	}
	head = temp;
	return head;
}

Node* tailInsert(Node* head, int val)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		cout << "Error!";
		exit(-1);
	}
	static Node* tail = head;

	if (tail!=NULL&&tail->next!=NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
	}
	temp->val = val; 
	temp->next = NULL;
	if (tail == NULL)
	{
		tail = temp;
		head = tail;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
	return head;
}

void showLinklist(Node* head)
{
	if (head == NULL)
	{
		cout << "showLinklist_Error:The list is a void_list!" << endl;
		return ;
	}
	Node* temp = head;
	cout << "showLinklist:";
	while (temp != NULL)
	{
		cout << temp->val<<" ";
		temp = temp->next;
	}
	cout << endl;
}

Node* delNode(Node* head, int val)
{
	if (head == NULL)
	{
		cout << "delNode_Error:The list is a void_list!" << endl;
		return head;
	}
	Node* temp = head;
	if (head->val == val)
		{
			temp = head;
			head = head->next;
			free(temp);
			return head;
		}
	Node* betemp = NULL;
	int flag = 1;
	while (temp->val != val)
	{
		betemp = temp;
		temp = temp->next;
		if (temp->next == NULL && temp->val != val)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		betemp->next = temp->next;
		free(temp);
		return head;
	}
	else
	{
		cout << "delNode_Error:The val no found of list!"<<endl;
			return head;
	}
}

/*
* ɾ������������ֵΪval�Ľڵ�
* @head ���������ͷָ��
* @val ��ɾ����ֵ
* return ɾ���������ͷָ��
*/
Node* delAllNode(Node* head, Ele_t val)
{
	if (head == NULL)//������Ϊ�յ�ʱ��
	{
		cout << "delAllNode_Error:The list is a void_list!" << endl;
		return head;//ֱ�ӷ���ͷָ�룬Ϊ���ݿ�ɾ��������ʾ������Ϣ
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
			head = head->next;//��headָ��head����һ���ڵ�
			free(temp);//�ͷ�head����ڵ�
			temp = head;//��tempָ����head�ڵ�
			continue;//��������ѭ������ֹ��head�ڵ���Ϊ��ɾ���ڵ�δɾ��
		}
		
		//����ɾ���ڵ㲻Ϊ��һ��ʱ
		if (temp->val == val)
		{
			flag++;
			behead->next = temp->next;//��ǰ���ڵ�ָ���ɾ���ڵ����һ���ڵ�
			free(temp);
			temp = behead->next;//����ָ��
			continue;//ɾ���ڵ��behead����Ҫ�ڱ���temp
		}
		behead = temp;//ǰ���ڵ㱸��temp
		temp = behead->next;//��ǰ���ڵ���temp����һ���ڵ�
		
	}
	if (flag)
	{
		cout << "delAllNode:This run deletes " << flag << " nodes from the list!" << endl;//��ӡɾ���˼����ڵ�
	}
	else
	{
		cout << "delAllNode_Error:The val no found of list!"<<endl;//��δ����ɾ��ʱ���׳�����
	}
	return head;
}

Node* delLinkList(Node* head)
{
	Node* temp ;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	if (head== NULL) return head;
	else exit(-1);

}

int nodeNum(Node* head)
{
	int cnt = 0;
	while (head != NULL)
	{
		head = head->next;
		cnt++;
	}
	return cnt;
}
/*
* ���������ÿһ��val
* @head �����ͷָ��
* @val �����������
* return ���ز����������ͷָ��
*/
Node* upInsert(Node* head, int val)
{
	Node* temp = (Node*)malloc(sizeof(Node));//newNode
	if (temp == NULL)//���ڴ����ʧ��ʱ���׳�����kill����������
	{
		cout << "Error!";
		exit(-1);
	}
	temp->val = val;
	temp->next = NULL;
	
	//��headΪ������ʱ
	if (head == NULL)
	{
		return temp;//ֱ�ӷ����½ڵ�Ϊͷ�ڵ�
	}
	//������������Ϊ����������Сֵʱ
	if (head->val >= val)
	{
		temp->next = head;
		return temp;//���½ڵ���뵽��ǰ���Ϊͷ�ڵ�
	}
	Node* behead = NULL;//head�ڵ��ǰ�ýڵ�
	Node* newhead = head;//copyͷָ�룬������������Լ����س�ʼͷָ��
	//���������ҵ�����λ��
	while (newhead != NULL&&newhead->val <= val)
	{
		behead = newhead;
		newhead = newhead->next;
	}
	//�����������ֵvalΪ���������ֱ�Ӳ�����β��
	if (newhead == NULL)
	{
		behead->next = temp;
	}
	else//����β�����룬��ǰ�ýڵ�behead��nextָ���½ڵ㣬�½ڵ��nextָ��newhead
	{
		behead->next = temp;
		temp->next = newhead;
	}
	return head;//������ɣ���󷵻�ͷָ��ڵ�
}

/*
* �ж�һ���������Ƿ�Ϊ����(һ������Ĭ��Ϊ����)
* @head ���жϵ�����
* return ���
*/
bool isUpList(Node* head)
{
	if (head == NULL)//������Ϊ��ʱ
	{
		cout << "isUpList_Error:The list is a void_list!" << endl;
		return 0;//��ʾ������Ϣ������
	}
	if (head->next == NULL)//������Ϊһ��Ԫ��ʱĬ������
		return 1;
	//������������
	while (head->next != NULL)
	{
		if (head->val > head->next->val)//����ǰ�ڵ�val������һ���ڵ�valʱ������Ϊ��������ֱ���˳�����
		{
			cout << "isUpList:The list is not a up_list!" << endl;
			return 0;
		}
		head = head->next;
	}
	cout << "isUpList:The list is a up_list!" << endl;
	return 1;
}

/*
* ��һ������ת
* @head �����ͷָ��
* return ��ת�������
*/
Node* inversionAllList(Node* head)
{
	if (head == NULL)//������Ϊ��ʱ
	{
		cout << "inversionList_Error:The list is a void_list!" << endl;
		return head;//��ʾ������Ϣ������
	}
	if (head->next == NULL)//������ֻ��һ���ڵ�ʱ����ת��Ϊ����
		return head;
	Node* t_n = head->next;//t_n����headָ��Ľڵ�
	Node* t = NULL;//t����head��ǰ�ýڵ㣻
	while (head->next != NULL)
	{
		t_n = head->next;
		head->next = t;
		t = head;
		head = t_n;
	}
	head->next = t;

	return head;
}
/*
* ���������������ݵ����ֵ
* @head ��������
* return �����е����ֵ
*/
int maxList(Node* head)
{
	if (head == NULL)//������Ϊ��ʱ
	{
		cout << "maxList_Error:The list is a void_list!" << endl;
		return -1;//��ʾ������Ϣ������
	}
	if (head->next == NULL)//������ֻ��һ������ʱ�����ֵΪ������
		return head->val;
	int max = head->val;//��ʼ��Ϊ����ĵ�һ��ֵ���洢�����е����ֵ
	//���������ҵ����ֵ�����ء�
	while (head->next != NULL)
	{
		head = head->next;//��headָ��head����һ���ڵ�(max����ʼ��Ϊhead->val)
		if (max < head->val)//��maxС��head->valʱmax�洢�µ����ֵ
			max = head->val;
	}
	return max;
}

/*
* ����������������֮��
* @head ��������
* return ����֮��
*/
int sumList(Node* head)
{
	if (head == NULL)//������Ϊ��ʱ
	{
		cout << "sumList_Error:The list is a void_list!" << endl;
		return -1;//��ʾ������Ϣ������
	}
	if (head->next == NULL)//������ֻ��һ������ʱ�������Ϊ������
		return head->val;
	int sum = 0;
	while (head != NULL)
	{
		sum += head->val;
		head = head->next;
	}
	return sum;
}

/*
* ��ָ��������м�ڵ��ָ��
* @head ��������
* return ָ���м�ڵ��ָ��
*/
Node* listMidPoint(Node* head)
{
	if (head == NULL)//������Ϊ��ʱ
	{
		cout << "listMidPoint_Error:The list is a void_list!" << endl;
		return head;//��ʾ������Ϣ������
	}
	if (head->next == NULL||head->next->next==NULL)//������ֻ��һ���������ڵ�ʱ������ָ���м�ڵ�Ϊָ��˽ڵ��ָ��
		return head;
	int num = nodeNum(head);
	int flag = (num % 2 ? num / 2  : num / 2-1);//�����־λ
	num = 1;//���ü�����
	//�ٴα��������ҵ���־λ
	while (flag != num)
	{
		num++;
		head = head->next;
	}
	return head->next;//temp->nextָ��ļ���������м�ڵ�
}


/*
* ����һ�������ݳ���Ϊn������
* @n ��Ҫ�����Ľڵ���
*/
Node* initList(unsigned int n)
{
	if (n == 0)//��nΪ0ʱ������һ��������
		return NULL;
	Node* newNode = NULL;
	Node* newhead = NULL;
	//����n�Σ�����ͷ�巨ÿ�β������½ڵ�Ϊ��ͷ�ڵ�
	while (n)
	{
		newNode = newhead;
		newhead = (Node*)malloc(sizeof(Node));
		if (newhead == NULL)
		{
			cout << "Error!";
			exit(-1);
		}
		newhead->next = newNode;
		n--;
	}
	return newhead;
}