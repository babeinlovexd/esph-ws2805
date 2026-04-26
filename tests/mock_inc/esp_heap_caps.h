#pragma once
#define MALLOC_CAP_INTERNAL 0
#define MALLOC_CAP_8BIT 0
inline void* heap_caps_malloc(size_t, uint32_t) { return nullptr; } inline void heap_caps_free(void*) {}
