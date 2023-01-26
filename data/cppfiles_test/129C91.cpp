#include <bits/stdc++.h>
using namespace std;
vector<int> v1[200005];
bool visit[200005];
bool color[200005];
int parent[200005];
int zz, zz1;
vector<int> vv;
void solve() {
  long long int n, m;
  cin >> n;
  vector<long long int> v1(n), store;
  set<long long int> set1;
  for (long long int x = 1; x < n + 1; ++x) set1.insert(x);
  for (long long int x = 0; x < n; ++x) {
    cin >> m;
    if (set1.count(m) > 0)
      set1.erase(m);
    else
      store.push_back(m);
  }
  sort(store.begin(), store.end());
  long long int count = 0, f1 = 1;
  for (long long int x = 0; x < store.size(); ++x) {
    long long int a = store[x];
    auto it = set1.begin();
    long long int pehla_ele = *it;
    long long int garaj = (a - 1) / 2;
    if (pehla_ele > garaj) {
      cout << -1 << endl;
      return;
    } else {
      set1.erase(pehla_ele);
      count++;
    }
  }
  cout << count << endl;
}
void test_case() {
  long long int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
int main() { test_case(); }
