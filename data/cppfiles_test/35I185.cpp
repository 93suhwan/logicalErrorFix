#include <bits/stdc++.h>
using namespace std;
long long int mod(long long int x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long int add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
bool cmp(const int &a, const int &b) { return a > b; }
bool comp2(pair<long long int, long long int> a,
           pair<long long int, long long int> b) {
  if (b.first > a.first) {
    return true;
  }
  if (b.first == a.first) {
    if (b.second > a.second)
      return true;
    else
      return false;
  } else
    return false;
}
bool isPowerOfTwo(int x) { return (x && !(x & (x - 1))); }
int count_one(int n) {
  long long int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}
bool check_set(int N, int i) {
  if (N & (1 << i))
    return true;
  else
    return false;
}
void possibleSubsets(char A[], int N) {
  for (int i = 0; i < (1 << N); ++i) {
    for (int j = 0; j < N; ++j)
      if (i & (1 << j)) cout << A[j];
    cout << endl;
  }
}
vector<long long int> v[100005];
long long int vis[100005];
void dfs(long long int node) {
  vis[node] = 1;
  for (auto child : v[node]) {
    if (vis[child] == 0) {
      dfs(child);
    }
  }
}
long long int solve() {
  long long int n;
  cin >> n;
  ;
  long long int m;
  cin >> m;
  ;
  long long int ma = 0;
  for (int i = 32; i >= 0 && n < m + 1; i--) {
    if ((m + 1) >> (i & 1)) {
      ma = ma | 1 << i;
      n = n | 1 << i;
    }
  }
  return ma;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long int t;
  cin >> t;
  ;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
