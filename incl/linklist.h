#ifndef _LINKLIST_H_
#define _LINKLIST_H_

//
// 链表的一般实现
//

struct node {
	void *item;
	struct node *link;
};

struct list {
	struct node* list;
	int num;
};

#endif
