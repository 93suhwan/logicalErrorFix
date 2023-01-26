#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
long long n, a[1000006], ret;
char str[1000006];
vector<long long> b[1000006], v[1000006];
stack<long long> s;
void pre() {
  for (long long i = 2; i < 1000006; i++) {
    if (b[i].empty()) {
      for (long long j = i; j < 1000006; j *= i) {
        for (long long k = j; k < 1000006; k += j) {
          b[k].push_back(i);
        }
      }
    }
  }
}
signed main() {
  pre();
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  scanf("%s", str + 1);
  for (long long i = 1; i <= n; i++) {
    char c = str[i];
    s.push(i);
    for (long long j : b[a[i]]) {
      if (c == '*') {
        v[j].push_back(i);
      } else {
        while (!s.empty() && (v[j].empty() || s.top() > v[j].back())) {
          s.pop();
        }
        if (!v[j].empty()) v[j].pop_back();
      }
    }
    ret += s.size();
  }
  cout << ret << endl;
  return 0;
}
