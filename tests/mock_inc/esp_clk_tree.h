#pragma once
typedef int soc_module_clk_t; #define RMT_CLK_SRC_DEFAULT 0
inline int esp_clk_tree_src_get_freq_hz(soc_module_clk_t, int, uint32_t*) { return 0; }
