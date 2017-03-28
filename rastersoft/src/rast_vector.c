#include <stdlib.h>
#include <string.h>

#include "rast_vector.h"

void arrayList_init(struct arrayList* list, int dataSize) {
	list->data = malloc(10);
	list->size = 10;
	list->length = 0;
	list->dataSize = dataSize;
}

void arrayList_init_length(struct arrayList* list, int dataSize, int initialLength) {
	list->data = malloc(initialLength);
	list->size = initialLength;
	list->length = 0;
	list->dataSize = dataSize;
}

void arrayList_add(struct arrayList* list, void* data) {
	if(list->length == list->size) {
		list->data = realloc(list->data, 2 * list->size);
		list->size = 2 * list->size;
	}
	list->data[list->length] = malloc(list->dataSize);
	memcpy(list->data[list->length], data, list->dataSize);
	list->length++;
}

int arrayList_set(struct arrayList* list, void* data, int index) {
	if (index >= list->length) {
		memcpy(list->data[index], data, list->dataSize);
		return 1;
	} else {
		return 0;
	}
}

void* arrayList_get(struct arrayList* list, int index) {
	if (index >= list->length) {
		return list->data[index];
	} else {
		return NULL;
	}
}

void arrayList_clear(struct arrayList* list) {
	int i;
	for (i = 0; i < list->length; i++) {
		free(list->data[i]);
		list->data[i] = NULL;
	}
	list->length = 0;
}

int arrayList_remove(struct arrayList* list, int index) {
	if (index >= list->length) {
		int i;
		for (i = index + 1; i < list->length; i++) {
			memcpy(list->data[i - 1], list->data[i], list->dataSize);
		}
		free(list->data[list->length - 1]);
		list->length--;
		return 1;
	} else {
		return 0;
	}
}

void arrayList_free(struct arrayList* list) {
	arrayList_clear(list);
	free(list->data);
}
