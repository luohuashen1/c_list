#include<stdlib.h>
#include<iostream>
#include"list.h"
using namespace std;

/*
* 初始化头节点
* @head 头节点指针的地址
*/
void initHeadNode(List** head)
{
	List* t = (List*)malloc(sizeof(List));
	if (t == NULL)
	{
		cout << "initHeadNode_Error:Memory allocation failure!" << endl;//当内存分配错误，抛出错误。
		exit(-1);
	}
	t->dataHead = NULL;//初始化数据链表均为空
	t->dataTail = NULL;
	t->dataNodeNum = 0;
	*head = t; //修改地址传回head
}

/*
* 头插法插入数据
* @listHead 头节点指针
* @val 待插入数据
* return 头节点指针
*/
List* headInsert(List* listHead, int val)
{
	if (listHead == NULL)//当头节点为空时，抛出错误。
	{
		cout << "headInsert_Error:The header node has not been initialized!";
		return listHead;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));//产生待插入的节点
	if (newNode == NULL)
	{
		cout << "headInsert_Error:Memory allocation failure!" << endl;//当内存分配错误，抛出错误。
		exit(-1);
	}
	newNode->val = val;//填充新节点数据域
	newNode->next = listHead->dataHead;
	listHead->dataHead = newNode;
	if (listHead->dataTail == NULL)//当数据链为空时，让newNode成为数据链尾。
		listHead->dataTail = newNode;
	listHead->dataNodeNum++;//记录数据链节点数
	return listHead;
}

/*
* 尾插法插入数据
* @listHead 头节点指针
* @val 待插入数据
* return 头节点指针
*/
List* tailInsert(List* listHead, int val)
{
	if (listHead == NULL)//当头节点为空时，抛出错误。
	{
		cout << "tailInsert_Error:The header node has not been initialized!";
		return listHead;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));//产生待插入的节点
	if (newNode == NULL)
	{
		cout << "tailInsert_Error:Memory allocation failure!" << endl;//当内存分配错误，抛出错误。
		exit(-1);
	}
	newNode->val = val;//填充新节点数据域
	newNode->next = NULL;
	if (listHead->dataTail == NULL)//当数据链为空时，让newNode成为数据链头。
	{
		listHead->dataHead = newNode;
		
	}
	else//当数据链不为空时，在数据链尾增加新节点
	{
		listHead->dataTail->next = newNode;
	}
	listHead->dataTail = newNode;//新节点成为新链尾
	listHead->dataNodeNum++;//记录数据链节点数
	return listHead;
}

/*
* 打印数据链的所有数据
* @listHead 头节点指针
*/
void showDataList(List* listHead)
{
	if (listHead == NULL)//当头节点为空时，抛出错误。
	{
		cout << "showDataList_Error:The header node has not been initialized!";
		return ;
	}
	Node* temp = listHead->dataHead;//备份数据链头节点
	if (temp == NULL)//当数据链为空时，抛出错误
	{
		cout << "showDataList_Error:Data_list is a void_list!";
		return;
	}
	cout << "showDataList:";
	//遍历数据链，并打印其中存储数据
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

/*
* 删除数据链中第一个值为val的节点
* @listHead头节点指针
* @val 待删除值
* 
*/
void delDataListNode_Val(List* listHead, int val)
{
	if (listHead == NULL)//当头节点为空时，抛出错误。
	{
		cout << "delDataListNode_Val_Error:The header node has not been initialized!";
		return;
	}
	Node* head = listHead->dataHead;//备份数据链头节点
	if (head == NULL)//当数据链为空时，抛出错误
	{
		cout << "delDataListNode_Val_Error:Data_list is a void_list!";
		return;
	}
	listHead->dataNodeNum--;
	if (head->val == val)//当第一个节点为待删除的节点时
	{
		cout << "delDataList_Val:" << val << endl;
		listHead->dataHead = head->next;//换头
		free(head);
		return;
	}
	//当数据链第一个节点不是待删除节点
	Node* betemp = NULL;//产生一个临时变量，用来储存待删除节点的上一个节点信息
	int flag = 1;//产生一个标志，记录是否发生删除操作
	//遍历数据链寻找待删除的节点
	while (head->val != val)
	{
		betemp = head;
		if (head->next == NULL && head->val != val)//当遍历到数据链最后仍未发生删除操作
		{
			flag = 0;//清空标志位，表示未发生删除操作
			break;//跳出循环
		}
		head = head->next;
	}
	if (flag)//当找到了待删除节点
	{
		cout << "delDataList_Val:" << val << endl;
		betemp->next = head->next;//重新指向
		if (betemp->next == NULL)//当待删除节点为尾节点时
			listHead->dataTail = betemp;
		free(head);//删除节点
	}
	else
	{//当遍历完数据链未发生删除操作时
		listHead->dataNodeNum++;
		cout << "delDataListNode_Val_Error:The val no found of list!" << endl;//抛出错误
	}
}


/*
* 删除数据链中所有值为val的节点
* @listHead 头节点指针
* @val 待删除的值
* 
*/
void delDataListAllNode_Val(List* listHead, Ele_t val)
{
	if (listHead == NULL)//当头节点为空时，抛出错误。
	{
		cout << "delDataListAllNode_Val_Error:The header node has not been initialized!";
		return;
	}
	Node* head = listHead->dataHead;//备份数据链头节点
	if (head == NULL)//当数据链为空时，抛出错误
	{
		cout << "delDataListAllNode_Val_Error:Data_list is a void_list!";
		return;
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
			listHead->dataNodeNum--;
			head = head->next;//让head指向head的下一个节点
			listHead->dataHead = head;//换头
			free(temp);//释放head这个节点
			temp = head;//让temp指向新head节点
			continue;//跳过本次循环，防止新head节点仍为待删除节点未删除
		}

		//当待删除节点不为第一个时
		if (temp->val == val)
		{
			flag++;
			listHead->dataNodeNum--;
			behead->next = temp->next;//让前驱节点指向待删除节点的下一个节点
			free(temp);
			temp = behead->next;//重新指向
			if (temp == NULL)//当删除的节点为尾节点时
			{
				listHead->dataTail = behead;//换尾
			}
			continue;//删除节点后behead不需要在备份temp
		}
		behead = temp;//前驱节点备份temp
		temp = behead->next;//从前驱节点获得temp的下一个节点

	}
	if (flag)
	{
		cout << "delDataListAllNode_Val:This run deletes " << flag << " val = "<<val<<" nodes from the list!" << endl;//打印删除了几个节点
	}
	else
	{
		cout << "delDataListAllNode_Val_Error:The val no found of list!" << endl;//当未发生删除时，抛出错误
	}
}

/*
* 删除整个链表，包括头节点和数据链
* @listHead 待删除的链表的地址指针
*/
void delAllList(List** listHead)
{
	Node* dataHead = (*listHead)->dataHead;//备份数据链头节点
	Node* temp;
	//遍历删除数据链
	while (dataHead != NULL)
	{
		(*listHead)->dataNodeNum--;
		temp = dataHead;
		dataHead = dataHead->next;
		free(temp);
	}
	if (dataHead == NULL && (*listHead)->dataNodeNum == 0)//校验删除
	{
		free(*listHead);
		*listHead = NULL;
		cout << "delAllList Successful!" << endl;//提示成功
	}
	else
	{
		cout << "delAllList_Error!"<<endl;//抛出错误
		exit(-1);
	}
}