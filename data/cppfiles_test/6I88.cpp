#include <bits/stdc++.h>
using namespace std;
vector<set<long long>> v1(2e5), v2(2e5);
void solve() {
  long long n, m;
  cin >> n >> m;
  for (auto i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    v1[min(a, b)].insert(max(a, b));
  }
  v2 = v1;
  long long q;
  cin >> q;
  for (auto i = 0; i < q; i++) {
    long long a;
    cin >> a;
    if (a != 3) {
      long long b, c;
      cin >> b, c;
      b--;
      c--;
      if (a == 1) {
        v1[min(a, b)].insert(max(a, b));
      } else {
        v1[min(a, b)].erase(max(a, b));
      }
    } else {
      long long count = 0;
      for (auto j = 0; j < n; j++) {
        if (v1[j].size() == 0) {
          count++;
        }
      }
      cout << count << '\n';
      v1 = v2;
    }
  }
}
int main() { solve(); }
