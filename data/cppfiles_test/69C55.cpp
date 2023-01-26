#include <bits/stdc++.h>
using namespace std;
string N;
vector<string> v;
int dist(string& a, string& b) {
  int n = a.size();
  int m = b.size();
  int j = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[j])
      j++;
    else
      c++;
  }
  return c + m - j;
}
int main() {
  for (long long i = 0; i < 60; i++) {
    v.push_back(to_string(1LL << i));
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    cin >> N;
    int ans = 1e9;
    for (auto s : v) {
      ans = min(ans, dist(N, s));
    }
    printf("%d\n", ans);
  }
  return 0;
}
