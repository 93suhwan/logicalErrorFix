#include <bits/stdc++.h>
using namespace std;
int T, n, p[1100000], l[1100000], a[1100000], ans[1100000];
vector<int> v[1100000];
string s;
int main() {
  for (int i = 2; i <= 1000000; i++) {
    if (!p[i]) {
      p[i] = i;
      for (int j = 2; i * j <= 1000000; j++) {
        if (!p[i * j]) p[i * j] = i;
      }
    }
  }
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '*') {
      l[i] = i;
      while (a[i] != 1) {
        v[p[a[i]]].push_back(i);
        a[i] /= p[a[i]];
      }
    } else {
      l[i] = i;
      while (a[i] != 1) {
        if (v[p[a[i]]].empty())
          l[i] = -1;
        else
          l[i] = min(l[i], v[p[a[i]]].back()), v[p[a[i]]].pop_back();
        a[i] /= p[a[i]];
      }
    }
  }
  stack<int> s;
  long long sum = 0;
  for (int i = n; i >= 1; i--) {
    ans[i] = 1;
    while (!s.empty() && s.top() != -1 && l[s.top()] >= l[i])
      ans[i] += ans[s.top()], s.pop();
    s.push(i);
    if (l[i] == i) sum += ans[i];
  }
  cout << sum << endl;
  return 0;
}
