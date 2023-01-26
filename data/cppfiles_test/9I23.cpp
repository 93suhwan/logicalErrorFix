#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include "windows.h"
#define ll long long
#define ld long double
#define ull unsigned ll

#define pii pair<int,int> 
#define pll pair<ll, ll>

#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vs vector<string>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
#define ford(it,from,to) for(int (it)=from; (it)>=to; (it)--)
#define fors(it,from,to,step) for(int (it)=from; (it)<to; (it)+=step)
#define fora(it,v) for(auto&(it) : v)

#define yes cout << "yes\n"
#define no cout << "no\n"

using namespace std;



int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(20);
		

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> v(n, vector<pair<int, int>>(m));

	forn(i, 0, n) {
		forn(j, 0, m) {
			int x;
			cin >> x;
			if (x == 2) {
				v[i][j] = { 1,0 };
			}
			else if (x == 1) {
				v[i][j] = { 0,1 };
			}
			else if (x == 3) {
				v[i][j] = { 0,-1 };
			}
		}
	}
	vector<int>p(m);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		pair<int, int>coord = { 0,x };
		coord.first = p[x];
		while (coord.first != n) {
			pair<int, int>pr = v[coord.first][coord.second];
			if (coord.first - 1 == p[coord.second]) {
				p[coord.second]++;
			}
			v[coord.first][coord.second] = { 1,0 };
			coord.first += pr.first;
			coord.second += pr.second;
		}
		cout << coord.second + 1 << " ";
	}



	return 0;

}