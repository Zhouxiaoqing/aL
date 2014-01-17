#ifndef _INTERNAL_SORT_H_
#define _INTERNAL_SORT_H_

typedef int (*cmp) (void *lf, void *rt);

void bubble_sort(void *array, cmp);




#endif /* _INTERNAL_SORT_H_ */
