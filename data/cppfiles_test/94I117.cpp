#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int bin(long long int a) {
  long long int cnt = 0;
  while (a != 0) {
    cnt += a % 10;
    a = a / 10;
  }
  return cnt;
}
int main() {
  long long int a, b, c, i, t, j, e, d, k, m, r;
  long long int n, q, l, x, y;
  long long int mod = 1000000007;
  long long int temp;
  bool flag, fl, fla;
  string s1, s2, prs2;
  bool visited[27];
  long long int cnt, gc, sum, start, end, pre;
  set<long long int> po;
  vector<pair<long long int, long long int>> v;
  vector<pair<long long int, long long int>> v1;
  vector<long long int> v3;
  vector<long long int> v2;
  long long int mini, maxi, mi;
  priority_queue<long long int> pq;
  unordered_map<long long int, int> mp;
  unordered_map<long long int, long long int> mp1;
  multimap<long long int, long long int> mp2;
  long long int o, ans;
  long long int mat[1001][1001];
  long long int rt[20001];
  long long int w[200001];
  long long int pmax[200001];
  long long int smax[200001];
  long long int h[200001];
  sum = 0;
  cnt = 0;
  long long int result = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    b = n;
    while (n % 2 == 0) {
      n = n / 2;
    }
    if (n == 1)
      cout << b - 1 << "\n";
    else if ((sqrt(b) * sqrt(b)) == b)
      cout << sqrt(b) - 1 << "\n";
    else if (b % 2 == 1) {
      cout << sqrt(b) << "\n";
    } else {
      cout << sqrt(b) + 1 << "\n";
    }
  }
}
