#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long mod = 1e9 + 7;
const long double eps = 1e-12;
const long double PI = acos(-1.0);
void test_case() {
  int n = 0;
  cin >> n;
  vector<priority_queue<int>> h(5);
  for (int j = 0; j < n; ++j) {
    int c[5];
    fill(c, c + 5, 0);
    string a;
    cin >> a;
    for (int i = 0; i < (long long)(a).size(); ++i) {
      c[a[i] - 'a']++;
    }
    for (int i = 0; i < 5; ++i) {
      h[i].push(c[i] - ((int)(long long)(a).size() - c[i]));
    }
  }
  int max_c = 0;
  for (int i = 0; i < 5; ++i) {
    int d = 0, j = 0;
    while (!h[i].empty() && d + h[i].top() > 0) {
      d += h[i].top();
      h[i].pop();
      j++;
    }
    if (max_c < j) max_c = j;
  }
  cout << max_c << '\n';
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 0;
  cin >> t;
  while (t--) test_case();
  return 0;
}
