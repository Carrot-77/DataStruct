/*************************************************************************
    > File Name: 13.3stack.cpp
    > Author: 冲鸭！小星星
    > Mail: N0 Mail! 
    > Created Time: 2020年02月13日 星期四 22时08分31秒
 ************************************************************************/
//队列queue
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
	int* data;
	int head, tail, size, cnt;
} Queue;

Queue* init(int n) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (int*)malloc(sizeof(int) * n);
	q->head = q->tail = q->cnt = 0;
	q->size = n;
	return q;
}

int empty(Queue* q) {
	return q->cnt == 0;
}

int front(Queue* q) {
	if (empty(q)) return 0;
	return q->data[q->head];
}

int push(Queue* q, int val) {
	if (q == NULL) return 0;
	if (q->cnt == q->size) return 0;
	q->data[q->tail] = val;
	q->tail += 1;
	if (q->tail == q->size) q->tail -= q->size;
	q->cnt += 1;
	return 1;
}

int pop(Queue* q) {
	if (q == NULL) return 0;
	if (empty(q)) return 0;
	q->head += 1;
	if (q->head == q->size) q->head -= q->size;
	q->cnt -= 1;
	return 1;
}

void output(Queue* q) {
	printf("Queue(%d) = [", q->cnt);
	for (int i = q->head, j = 0; j < q->cnt; j++) {
		j && printf(", ");
		printf("%d", q->data[(i + j) % (q->size)]);
	}
	printf("]\n");
	return;
}

void clear(Queue* q) {
	if (q == NULL) return;
	free(q->data);
	free(q);
	return;
}

int main() {
#define maxop 20
	srand(time(0));
	Queue* q = init(maxop);
	int op, val;
	for (int i = 0; i < maxop; i++) {
		op = rand() % 4;
		val = rand() % 100;
		switch (op) {
		case 0:
		case 1:
		case 2: {
			printf("push %d to Queue = %d\n", val, push(q, val));
		} break;
		case 3: {
			printf("pop %d from Queue = %d\n", front(q), pop(q));
		} break;
		}
		output(q);
		printf("\n");
	}
	clear(q);
	return 0;
}

