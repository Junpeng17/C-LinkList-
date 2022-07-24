#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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
		printf("insert next addr = %p\n", (*list)->next);
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
	remove(head, 5);

	printf("%d\n", get(head, 1));
	printf("size = %d\n", length(head));

	return 0;
}
