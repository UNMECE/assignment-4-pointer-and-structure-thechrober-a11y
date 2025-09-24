#ifndef ITEM_H
#define ITEM_H

#include <cstring>

struct _Item {
    double price;
		char *sku;
		char *name;
		char *category;
};

typedef struct _Item Item;

								#endif

