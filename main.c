#include <stdio.h>
#include <stdlib.h>

typedef struct linklist {
	int data;
	struct linklist* next;
}LinkList;

int length(LinkList* list);
void deleteNode(LinkList** node);

LinkList* create()
{
	printf("创建链表！\n");
	LinkList* head = (LinkList*)malloc(sizeof(LinkList*));
	if (head == NULL) {
		printf("链表头节点内存分配失败！\n");
	}
	else {
		head->next = NULL;
		return head;
	}

	return NULL;
}

void append(LinkList** list, int num)
{
	LinkList* list2 = (LinkList*)malloc(sizeof(LinkList*));
	
	if (list == NULL) {
		*list = create();
	}
	else {
		printf("添加链表数据！\n");
		list2->data = num;
		list2->next = NULL;
		(*list)->next = list2;
		*list = list2;
	}
}

int get(LinkList* list, int pos)
{
	int i = 0;
	int ret = 0;
	LinkList* l = list->next;

	while (l != NULL && (i < pos)) {
		ret = l->data;
		l = l->next;
		i++;
	}

	return ret;
}

void remove(LinkList* list, int pos)
{
	int i = 1;
	LinkList* l = list;

	while (i<pos)
	{
		i++;
		l = l->next;
	}
	deleteNode(&l);
	printf("del: %d\n", l->data);
}

/*
 * 删除节点
 */
void deleteNode(LinkList** node)
{
	if ((*node)->next != NULL) {
		(*node)->next = (*node)->next->next;
	}
}

void insert(LinkList* list, int data, int pos)
{
	int i = 1;
	LinkList* l = list;
	LinkList* newlist = create();
	append(&newlist, data);
	
	while (i < pos)
	{
		i++;
		l = l->next;
	}
	newlist->next = l->next;
	(*l).next = newlist ;
}

void update(LinkList* list, int pos, int newdata)
{
	int i = 0;
	LinkList* l = list->next;
	
	while (l != NULL && (i < pos-1)) {
		l = l->next;
		i++;
	}
	l->data = newdata;
}

int length(LinkList* list)
{
	int length = 0;
	LinkList* l = list->next;

	while (l != NULL) {
	  l = l->next;
	  length++;
	}

	return length;
}

int main()
{
	LinkList* head;
	LinkList* linkList = NULL;
	linkList = create();
	head = linkList;

	append(&linkList, 67);
	append(&linkList, 2);
	append(&linkList, 89);
	append(&linkList, 30);
	append(&linkList, 27);
	append(&linkList, 103);
	update(head, 3, 99);
	remove(head, 5);
	insert(head, 33, 2);

	printf("%d\n", get(head, 1));
	printf("length = %d\n", length(head));

	return 0;
}
