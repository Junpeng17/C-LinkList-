/* 
 * 万能版单向链表，支持在一个链表里添加多种类型数据
 * 在 VS 2022 上测试通过
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct linklist {
	void *data;
	struct linklist* next;
}LinkList;

int length(LinkList* list);
void appendCore(LinkList** list, void *data);

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

void appendCore(LinkList** list, void *data)
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

void append(LinkList** list, void *data)
{
	appendCore(list, data);
}

void append(LinkList** list, int data)
{
	int x = data;
	void* np = &x;
	void* p = malloc(sizeof(void*));

	memcpy(p, np, sizeof(np));
	appendCore(list, p);
}

void append(LinkList** list, const char *data)
{
	void* p = (void*)data;

	appendCore(list, p);
}

void append(LinkList** list, double data)
{
	double d = data;
	void* np = &d;
	void* p = malloc(sizeof(void*));

	memcpy(p, np, sizeof(np));
	appendCore(list, p);
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
	l->next = l->next->next;

}

void insertCore(LinkList* list, void *data, int pos)
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

void insert(LinkList* list, int data, int pos)
{
	int num = data;
	void* np = &num;
	void* p = malloc(sizeof(np)); 
	
	memcpy(p, np, sizeof(np));
	insertCore(list, p, pos);
}

void insert(LinkList* list, const char *data, int pos)
{
	void* p = (void*)data;

	insertCore(list, p, pos);
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

void invert(LinkList** list)
{
	int len = length(*list);
	char** lp = (char**)malloc(sizeof(LinkList) * len);
	LinkList *tmp = *list;
	
	for (int i=0; i<len; i++) {
		tmp = tmp->next;
		lp[i] = (char*)((void*)tmp->data);
	}
	
	int j = len-1;
	LinkList *list2 = create();
	*list = list2;

	while (j >= 0) {
		append(&list2, (void*)lp[j]);
		j--;
	}
	
}

int main()
{
	LinkList *head = NULL, *linkList = NULL;
	linkList = create();
	head = linkList;

	const char* str = "Hello world!";
	// int n1 = 56;
  
	append(&linkList, 68);
	append(&linkList, 99);
	append(&linkList, str);
	append(&linkList, 27);
	append(&linkList, 0.993);
	append(&linkList, 27.682546);
	remove(head, 4);
	insert(head, 56, 4);
	invert(&head);
	
	printf("%d\n", *(int*)get(head, 1));
	printf("%d\n", *(int*)get(head, 2));
	printf("%s\n", (char*)get(head, 3));
	printf("%d\n", *(int*)get(head, 4));
	printf("%.3lf\n", *(double*)get(head, 5));
	printf("%.8lf\n", *(double*)get(head, 6));
	printf("length = %d\n", length(head));

	return 0;
}
