#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <immintrin.h>
#include <cassert>

#define MOD 1'000'000'007

int32_t bin_pow(int32_t base, int32_t power) {
	if(power == 0)
		return 1;
	if(power == 1)
		return base;
	int32_t prev = bin_pow(base, power / 2);
	prev = ((int64_t)prev * prev) % MOD;
	if(power % 2 == 1)
		prev = ((int64_t)prev * base) % MOD;
	return prev;
}

int32_t* fact, *inv_fact;
int32_t cnk(int32_t n, int32_t k) {
	int32_t res = ((int64_t)fact[n] * inv_fact[k]) % MOD;
	return ((int64_t)res * inv_fact[n - k]) % MOD;
}

int main() {
	fact = new int32_t[200];
	inv_fact = new int32_t[200];
	fact[0] = 1;
	inv_fact[0] = 1;
	for(int32_t i = 1; i < 200; i++) {
		fact[i] = ((int64_t)fact[i - 1] * i) % MOD;
		inv_fact[i] = bin_pow(fact[i], MOD - 2);
	}

	int32_t num_tests;
	std::cin >> num_tests;

	for(int32_t t = 0 ;t < num_tests; t++) {
		int32_t n, k;
		std::cin >> n >> k;

		std::vector<int32_t>* tree = new std::vector<int32_t>[n];
		int32_t** dist = new int32_t*[n];
		for(int32_t i = 0; i < n; i++) {
			dist[i] = new int32_t[n];
			for(int32_t j = 0 ;j  < n; j++)
				dist[i][j] = 1'000'000;
			dist[i][i] = 0;
		}
		for(int32_t i = 0; i < n - 1; i++) {
			int32_t src, dst;
			std::cin >> src >> dst;
			src--;
			dst--;

			tree[src].push_back(dst);
			tree[dst].push_back(src);
			dist[src][dst] = 1;
			dist[dst][src] = 1;
		}

		for(int32_t p = 0; p < n; p++)
			for(int32_t i = 0; i < n; i++)
				for(int32_t j = 0; j < n; j++)
					dist[i][j] = std::min(dist[i][j], dist[i][p] + dist[p][j]);

		if(k == 2) {
			std::cout << n * (n - 1) / 2 << "\n";
			continue;
		}

		int32_t answer = 0;
		for(int32_t d = 1; d <= n - 1; d++) {
			for(int32_t i = 0; i < n; i++) {
				int32_t choices = 0;
				for(int32_t j = 0; j < n; j++)
					if(dist[i][j] == d)
						choices++;
				if(choices >= k) {
					answer += cnk(choices, k);
					answer %= MOD;
				}
			}
		}

		std::cout << answer << "\n";
	}
	return 0;
}