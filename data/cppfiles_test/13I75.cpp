#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ctime>
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <random>
#include <cmath>
#include <cassert>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <bitset>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using ll = long long;

//constexpr int MOD = 998244353;// // //;
constexpr int MOD = 1000000000 + 7;
constexpr ll powm(ll x, ll n, ll mod)
{
	ll r = 1; 
	while (n) 
	{
		if (n & 1) r = r * x % mod; 
		x = x * x % mod; 
		n = n / 2;
	}
	return r;
} 
 
bool check(int n, int m, int k)
{
	assert(n >= 1 && n <= 100);
	assert(m >= 1 && m <= 100);
	assert((n * m) % 2 == 0);
	assert(k >= 0 && k <= (n * m) / 2);

	
	if (n % 2 == 1) {
		k = (n*m) / 2 - k;
		std::swap(n, m);
	}

	assert(n % 2 == 0);
	return k % 2 == 0 && k <= (m / 2) *n;
}


int solve()
{ 
	int n, m, k;
	std::cin >> n >> m >> k;
	
	if (check(n, m, k))
	{
		std::cout << "YES\n";

		int a = k, b = (n*m) / 2 - k;
		bool flag = false;
		if (n % 2 == 1) {
			flag = true;
			std::swap(n, m);
			std::swap(a, b);
		}

		char s[200][200]{};
		int cnt = 1;
		for (int j = 0; j + 1 < m; j += 2)
		{
			for (int i = 0; i < n; ++i)
			{
				if (cnt <= a)
				{
					s[i][j] = s[i][j + 1] = 'a' + (j / 2 + i) % 16;
					++cnt;
				}
			}
		}

		for (int i = 0; i + 1 < n; i += 2)
		{
			for (int j = 0; j < m; ++j) {
				if (!s[i][j])
					s[i][j] = s[i + 1][j] = 'c' + (i / 2 + j) % 16;
			}
		}

		if (flag)
		{
			for (int j = 0; j < m; ++j)
			{
				for (int i = 0; i < n; ++i)
					std::cout << s[i][j];
				std::cout << std::endl;
			}
		}
		else {
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
					std::cout << s[i][j];

				std::cout << std::endl;
			}

		}

	}
	else
	{
		std::cout << "NO\n";
	}
 	 


	return 0;
}


int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
	std::ios::sync_with_stdio(false); std::cin.tie(0);std::cout.tie(0);	
//	precalc();
	int tc = 1;
	std::cin >> tc;
	for (int ic = 1; ic <= tc; ++ic)
	{
		solve();
	}

	return 0;
}
