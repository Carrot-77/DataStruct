/*************************************************************************
    > File Name: 17.UnionSet-1.cpp
    > Author: 冲鸭！小星星
    > Mail:OJ71
    > Created Time: 2020年02月22日 星期六 20时19分07秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
	u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
		u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
	return u->father[x] = find(u, u->father[x]);
	//return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
	int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
	if (u->size[fa] < u->size[fb]) swap(fa, fb);
	u->father[fb] = fa;
	u->size[fa] += u->size[fb];
	/*
	if (u->size[fa] > u->size[fb]) {
		u->father[fb] = fa;
		u->size[fa] += u->size[fb];
	} else {
		u->father[fa] = fb;
		u->size[fb] += u->size[fa];
	}
	*/
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
	free(u->size);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}
