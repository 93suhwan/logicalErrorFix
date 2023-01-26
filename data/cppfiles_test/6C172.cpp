#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const int N = (int)2e5 + 100;
int cnt[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a, b, res = 0;
  while (m--) {
    cin >> a >> b;
    if (a < b) swap(a, b);
    cnt[b]++;
    if (cnt[b] == 1) res++;
  }
  int q;
  cin >> q;
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      cin >> a >> b;
      if (a < b) swap(a, b);
      cnt[b]++;
      if (cnt[b] == 1) res++;
    } else if (c == 2) {
      cin >> a >> b;
      if (a > b) swap(a, b);
      cnt[a]--;
      if (cnt[a] == 0) res--;
    } else {
      cout << (n - res) << '\n';
    }
  }
  return 0;
}
