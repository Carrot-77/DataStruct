/*************************************************************************
    > File Name: 11.list.cpp
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年02月11日 星期二 19时07分50秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct ListNote {
	int data;
	struct ListNote *next;
} ListNode;

typedef struct List {
	ListNote head;
	int length;
} List;

ListNote *getNewNode(int val) {
	ListNode *p = (ListNote *)malloc(sizeof(ListNote));
	p->data = val;
	p->next = NULL;
	return p;
}

List *getLinkList() {
	List *l = (List *)malloc(sizeof(List));
	l->head.next = NULL;
	l->length = 0;
	return l;
}

int insert(List *l, int ind, int val) {
	if (l == NULL) return 0;
	if (ind < 0 || ind > l->length) return 0;
	ListNote *p = &(l->head), *node = getNewNode(val);
	while (ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
}

int erase(List *l, int ind) {
	if (l == NULL) return 0;
	if (ind < 0 || ind >= l->length) return 0;
	ListNote *p = &(l->head), *q;
	while (ind--) p = p->next;
	q = p->next;
	p->next = q->next;
	free(q);
	l->length -= 1;
	return 1;
}

void output(List *l) {
	printf("List(%d) = [", l->length);
	for (ListNote *p = l->head.next; p; p = p->next) {
		printf("%d->", p->data);
	}
	printf("NULL]\n");
	return ;
}

void rev(List *l) {
	if (l == NULL) return ;
	ListNote *p = l->head.next, *q;
	l->head.next = NULL;
	while (p) {
		q = p->next;
		p->next = l->head.next;
		l->head.next = p;
		p = q;
	}
	return ;
}

void clear_ListNode(ListNote *note) {
	if (note == NULL) return ;
	free(note);
	return ;
}

void clear_list(List *l) {
	if (l == NULL) return ;
	ListNote *p = l->head.next, *q;
	while (p) {
		q = p->next;
		clear_ListNode(p);
		p = q;
	}
	free(l);
	return ;
}

int main() {
	srand(time(0));
	#define maxop 20
	List *l = getLinkList();
	int op, ind, val;
	for (int i = 0; i < maxop; i++) {
		op = rand() % 4;
		ind = rand() % (l->length + 3) - 1;
		val = rand() % 100;
		switch(op) {
			case 0:
			case 1:
				printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
				break;
			case 2: {		
				printf("reverse the list\n");
				rev(l);
					} break;
			case 3:
				printf("erase item at %d from List = %d\n", ind, erase(l, ind));
				break;
		}
		output(l);
		printf("\n");
	}
	clear_list(l);
	return 0;
}
