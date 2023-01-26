#include <bits/stdc++.h>
using namespace std;
int tc;
void foo() {
  long long n, k, x, a[200100];
  unordered_map<int, vector<int>> m;
  queue<int> q;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = x;
    m[x].push_back(i);
  }
  long long max_c = 0;
  for (auto &[_, v] : m) {
    for (int i = 0; i < min(k, (long long)v.size()); i++) {
      q.push(v[i]);
    }
    max_c = max((long long)v.size(), max_c);
  }
  long long c[200100] = {};
  long long cur = 0;
  while (q.size()) {
    long long e = q.front();
    q.pop();
    c[e] = cur + 1;
    if (cur == k - 1) {
      if (q.size() < k) break;
    }
    cur = (cur + 1) % k;
  }
  for (int i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> tc;
  while (tc--) {
    foo();
  }
}
