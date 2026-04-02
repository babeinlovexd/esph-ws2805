#include <esp_heap_caps.h>
#include <cstdint>

int main() {
    uint32_t caps = MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT | MALLOC_CAP_DMA;
    return 0;
}
