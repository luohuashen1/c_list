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
* 删除链表中所有值为val的节点
* @head 传入链表的头指针
* @val 待删除的值
* return 删除后链表的头指针
*/
Node* delAllNode(Node* head, Ele_t val)
{
	if (head == NULL)//当链表为空的时候
	{
		cout << "delAllNode_Error:The list is a void_list!" << endl;
		return head;//直接返回头指针，为内容可删除，并提示错误信息
	}
	Node* temp = head;//产生一个临时变量代替头指针进行删除操作
	Node* behead = NULL;//head的前驱节点
	int flag = 0;//创建一个标志，记录是否发生删除
	//遍历链表所有节点，并删除所有值为val的节点
	while (temp != NULL)
	{
		//当第一个节点为待删除节点时
		if (head->val == val)
		{
			flag++;
			head = head->next;//让head指向head的下一个节点
			free(temp);//释放head这个节点
			temp = head;//让temp指向新head节点
			continue;//跳过本次循环，防止新head节点仍为待删除节点未删除
		}
		
		//当待删除节点不为第一个时
		if (temp->val == val)
		{
			flag++;
			behead->next = temp->next;//让前驱节点指向待删除节点的下一个节点
			free(temp);
			temp = behead->next;//重新指向
			continue;//删除节点后behead不需要在备份temp
		}
		behead = temp;//前驱节点备份temp
		temp = behead->next;//从前驱节点获得temp的下一个节点
		
	}
	if (flag)
	{
		cout << "delAllNode:This run deletes " << flag << " nodes from the list!" << endl;//打印删除了几个节点
	}
	else
	{
		cout << "delAllNode_Error:The val no found of list!"<<endl;//当未发生删除时，抛出错误
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
* 按升序插入每一个val
* @head 链表的头指针
* @val 待插入的数据
* return 返回插入后的链表的头指针
*/
Node* upInsert(Node* head, int val)
{
	Node* temp = (Node*)malloc(sizeof(Node));//newNode
	if (temp == NULL)//当内存分配失败时，抛出错误，kill掉整个程序
	{
		cout << "Error!";
		exit(-1);
	}
	temp->val = val;
	temp->next = NULL;
	
	//当head为空链表时
	if (head == NULL)
	{
		return temp;//直接返回新节点为头节点
	}
	//当待插入数据为整个链表最小值时
	if (head->val >= val)
	{
		temp->next = head;
		return temp;//将新节点插入到最前面成为头节点
	}
	Node* behead = NULL;//head节点的前置节点
	Node* newhead = head;//copy头指针，方便遍历链表以及返回初始头指针
	//遍历链表找到插入位置
	while (newhead != NULL&&newhead->val <= val)
	{
		behead = newhead;
		newhead = newhead->next;
	}
	//遍历后待插入值val为所有中最大，直接插入在尾部
	if (newhead == NULL)
	{
		behead->next = temp;
	}
	else//不在尾部插入，让前置节点behead的next指向新节点，新节点的next指向newhead
	{
		behead->next = temp;
		temp->next = newhead;
	}
	return head;//插入完成，最后返回头指针节点
}

/*
* 判断一个单链表是否为升序(一个数据默认为升序)
* @head 待判断的链表
* return 结果
*/
bool isUpList(Node* head)
{
	if (head == NULL)//当链表为空时
	{
		cout << "isUpList_Error:The list is a void_list!" << endl;
		return 0;//提示错误信息并返回
	}
	if (head->next == NULL)//当链表为一个元素时默认升序
		return 1;
	//遍历整个链表
	while (head->next != NULL)
	{
		if (head->val > head->next->val)//当当前节点val大于下一个节点val时，链表不为升序链表，直接退出函数
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
* 将一个链表反转
* @head 链表的头指针
* return 反转后的链表
*/
Node* inversionAllList(Node* head)
{
	if (head == NULL)//当链表为空时
	{
		cout << "inversionList_Error:The list is a void_list!" << endl;
		return head;//提示错误信息并返回
	}
	if (head->next == NULL)//当链表只有一个节点时，反转后为本身
		return head;
	Node* t_n = head->next;//t_n备份head指向的节点
	Node* t = NULL;//t备份head的前置节点；
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
* 求链表中所有数据的最大值
* @head 待求链表
* return 链表中的最大值
*/
int maxList(Node* head)
{
	if (head == NULL)//当链表为空时
	{
		cout << "maxList_Error:The list is a void_list!" << endl;
		return -1;//提示错误信息并返回
	}
	if (head->next == NULL)//当链表只有一个数据时，最大值为此数据
		return head->val;
	int max = head->val;//初始化为链表的第一个值，存储链表中的最大值
	//遍历链表，找到最大值并返回。
	while (head->next != NULL)
	{
		head = head->next;//让head指向head的下一个节点(max被初始化为head->val)
		if (max < head->val)//当max小于head->val时max存储新的最大值
			max = head->val;
	}
	return max;
}

/*
* 求链表中所有数据之和
* @head 待求链表
* return 数据之和
*/
int sumList(Node* head)
{
	if (head == NULL)//当链表为空时
	{
		cout << "sumList_Error:The list is a void_list!" << endl;
		return -1;//提示错误信息并返回
	}
	if (head->next == NULL)//当链表只有一个数据时，链表和为此数据
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
* 求指向此链表中间节点的指针
* @head 待求链表
* return 指向中间节点的指针
*/
Node* listMidPoint(Node* head)
{
	if (head == NULL)//当链表为空时
	{
		cout << "listMidPoint_Error:The list is a void_list!" << endl;
		return head;//提示错误信息并返回
	}
	if (head->next == NULL||head->next->next==NULL)//当链表只有一个或两个节点时，链表指向中间节点为指向此节点的指针
		return head;
	int num = nodeNum(head);
	int flag = (num % 2 ? num / 2  : num / 2-1);//计算标志位
	num = 1;//重置计数器
	//再次遍历链表，找到标志位
	while (flag != num)
	{
		num++;
		head = head->next;
	}
	return head->next;//temp->next指向的即是链表的中间节点
}


/*
* 创建一个无数据长度为n的链表
* @n 需要创建的节点数
*/
Node* initList(unsigned int n)
{
	if (n == 0)//当n为0时，创建一个空链表
		return NULL;
	Node* newNode = NULL;
	Node* newhead = NULL;
	//遍历n次，采用头插法每次产生的新节点为新头节点
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