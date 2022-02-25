#include <stddef.h>
#include "../btree.h"

// pointer_t --> always return pointer_t | void* -> void* , int64_t -> int64_t
#define node__get_asref(node_p, pointer_t) ( *(pointer_t*)(void*)(char*)node_p + offsetof(Node, value) )
// value_t --> always return value_t | int --> int
#define node__get(node_p, value_t) (*(value_t*)(char*)node_p + offsetof(Node, value))
