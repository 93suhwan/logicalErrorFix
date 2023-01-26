#include <bits/stdc++.h>
using namespace std;
long long t;
struct node {
  long long index;
  long long num;
};
bool cmp(node a, node b) {
  if (a.num != b.num)
    return a.num < b.num;
  else
    return a.index < b.index;
}
void solve() {
  long long n;
  cin >> n;
  vector<node> v;
  for (long long i = 1; i <= n; i++) {
    long long b;
    cin >> b;
    v.push_back(node{i, b});
  }
  sort(v.begin(), v.end(), cmp);
  long long res = 0;
  res = v.back().num - v.back().index;
  cout << res << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
