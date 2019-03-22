//
//  main.cpp
//  aaa
//
//  Created by pebble8888 on 2018/08/13.
//  Copyright © 2018年 pebble8888. All rights reserved.
//

#include <iostream>
#include <vector>

/*
void print_binary(int decimal){
	int binary = 0;
	int base = 1;
	
	while (decimal > 0){
		binary += (decimal % 2) * base;
		decimal = decimal / 2;
		base *= 10;
	}
	printf("0b%d", binary);
}
 */

int main(int argc, const char * argv[]) {
	
	std::vector<uint32_t> leaves;
	leaves.push_back(1);
	leaves.push_back(2);
	leaves.push_back(4);
	leaves.push_back(8);
	leaves.push_back(16);
	/*
	leaves.push_back(32);
	leaves.push_back(64);
	leaves.push_back(128);
	 */
	/*
	leaves.push_back(256);
	leaves.push_back(512);
	leaves.push_back(1024);
	leaves.push_back(2048);
	leaves.push_back(4096);
	leaves.push_back(8192);
	leaves.push_back(16384);
	leaves.push_back(32768);
	 */
	
	uint32_t inner[32];
	memset(inner, 0, sizeof(inner));
	uint32_t count = 0;
	while (count < leaves.size()) {
		uint32_t h = leaves[count];
		count++;
		int level = 0;
		printf("count: %d\n", count);
		printf("    h (%d) <- leaves\n", h);
		while (true) {
			if ((count & ((uint32_t)1) << level) != 0) {
				break;
			}
			printf("    h (%d) = inner[%d] (%d) + h (%d)\n",
				   inner[level] + h, level, inner[level], h);
			h = inner[level] + h;
			++level;
		}
		printf("  inner[%d] = h (%d)\n", level, h);
		inner[level] = h;
	}

	for (int i = 0; i < 32; ++i){ printf("%d,", inner[i]); }
	printf("\n");
	
	int level = 0;
	while ((count & (((uint32_t)1) << level)) == 0){
		++level;
	}
	printf("---\n");
	/*
	printf("level:%d\n", level);
	printf("count:%d\n", count);
	 */
	
	uint32_t h = inner[level];
	while (count != (((uint32_t)1) << level)){
		// copy same value
		printf("    h (%d) = h + h (%d) \n", 2*h, h);
		h = h + h;
		count += (((uint32_t)1) << level);
		printf("count: %d\n", count);
		++level;
		while ( (count & (((uint32_t)1) << level)) == 0){
			printf("    h (%d) = inner[%d] (%d) + h (%d)\n", inner[level] + h, level, inner[level], h);
			h = inner[level] + h;
			++level;
		}
	}
	
	for (int i = 0; i < 32; ++i){ printf("%d,", inner[i]); }
	printf("\n");
	printf("count:%d\n", count);
	printf("h:%d\n", h);
	return 0;
}
