#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node {
	int item;
	link next;
};

//
// 先选出要处理的结点y; 处理y->next指针指向r; 移动指针r, y
//
link reverse_list(link list) {
	link r = NULL, y = list, t = NULL;
	while (y != NULL) {
		t = y->next; y->next = r;
		r = y; y = t;
	}

	return r;
}

void
print_list(link list) {
	link t = list;
	while (t != NULL) {
		printf("%d - ", t->item);
		t = t->next;				// 注意, 此处应该是t->next而非list->next
	}
	printf("\n");
}

int
main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]);
	if (N < 3 ) { N = 3; }

	link t = (link)malloc(sizeof(*t)); link x = t;
	t->item = 1; t->next = NULL;

	for (i=2; i<=N; ++i) {
		x = (x->next = (link)malloc(sizeof(*x)));
		x->item = i; x->next = NULL;
	}

	print_list(t);
	print_list(reverse_list(t));

	return 0;
}


