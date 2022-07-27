/* 
 * 万能版单向链表，支持在一个链表里添加多种类型数据
 * 在 VS 2022 上测试通过
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct linklist {
	void *data;
	struct linklist* next;
}LinkList;

int length(LinkList* list);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

void append(LinkList** list, void *data)
{
	LinkList* list2 = (LinkList*)malloc(sizeof(LinkList*));
	
	if (list == NULL) {
		*list = create();
	}
	else {
		printf("添加链表数据！\n");
		list2->data = data;
		list2->next = NULL;
		(*list)->next = list2;
		*list = list2;
	}
}

void append(LinkList** list, int data)
{
	LinkList* list2 = (LinkList*)malloc(sizeof(LinkList*));
	int x = data;
	void* np = &x;

	if (list == NULL) {
		*list = create();
	}
	else {
		printf("添加链表数据！int\n");
		void* p = malloc(sizeof(void*));
		memcpy(p, np, sizeof(np));
		list2->data = p;
		list2->next = NULL;
		(*list)->next = list2;
		*list = list2;
	}
}

void append(LinkList** list, const char *data)
{
	LinkList* list2 = (LinkList*)malloc(sizeof(LinkList*));
	void* p = (void*)data;

	if (list == NULL) {
		*list = create();
	}
	else {
		printf("添加链表数据！int\n");
		list2->data = p;
		list2->next = NULL;
		(*list)->next = list2;
		*list = list2;
	}
}

void append(LinkList** list, double data)
{
	LinkList* list2 = (LinkList*)malloc(sizeof(LinkList*));
	double d = data;
	void* np = &d;

	if (list == NULL) {
		*list = create();
	}
	else {
		printf("添加链表数据！int\n");
		void* p = malloc(sizeof(void*));
		memcpy(p, np, sizeof(np));
		list2->data = p;
		list2->next = NULL;
		(*list)->next = list2;
		*list = list2;
	}
}

void *get(LinkList* list, int pos)
{
	int i = 0;
	void *ret = malloc(sizeof(void*));
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
	*(*l).next = *(*l).next->next;

}

void insert(LinkList* list, void *data, int pos)
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

	const char* str = "Hello world!";
	int n1 = 56;
  
	append(&linkList, 68);
	append(&linkList, 99);
	append(&linkList, str);
	append(&linkList, 27);
	append(&linkList, 0.993);
	append(&linkList, 27.682546);
	remove(head, 4);
	insert(head, &n1, 4);
	
	printf("%d\n", *(int*)(get(head, 1)) );
	printf("%d\n", *(int*)get(head, 2));
	printf("%s\n", (char*)get(head, 3));
	printf("%d\n", *(int*)get(head, 4));
	printf("%.3lf\n", *(double*)get(head, 5));
	printf("%.8lf\n", *(double*)get(head, 6));
	printf("length = %d\n", length(head));

	return 0;
}
