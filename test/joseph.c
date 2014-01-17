#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
	link next;
	int item;
};

//
// 求解约瑟夫环问题(N > M):
//  N : 人数
//  M : 每次跳过的人数
//

void
print_list(link list) {
	link t = list;
	do {
		printf("[#%p] : %d - [#%p]", t, t->item, t->next);
		t = t->next;				// 注意, 此处应该是t->next而非list->next
	} while (t != list);
	printf("\n");
}

int 
main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);

	link t = (link)malloc(sizeof(*t)), x = t;
	t->next = t; t->item = 1;

	// 初始化链表环
	for (i=2; i<=N; ++i) {
		x = (x->next = (link)malloc(sizeof(*x)));
		x->item = i; x->next = t;
	}

	print_list(t);

	// 执行选人, 直至最后一人剩余
	x = t;
	while (x->next != x) {
		// 在即将选择该人时, 停在前一节点, 用t暂存以便删除
		for (i=1; i<M; ++i) x = x->next;
		t = x->next;
		x->next = x->next->next; --N;				// 这里不应该是x = x->next->next, 而应该是x->next指向next->next
		free(t);
	}

	printf("--> left %d, last person ID : %d\n", N, x->item);

	return 0;
}


