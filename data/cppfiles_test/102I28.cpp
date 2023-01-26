#include <bits/stdc++.h>
using namespace std;
const int mod = 998244352;
mt19937 rng(time(nullptr));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, a, h;
  cin >> k >> a >> h;
  vector<int> order;
  vector<int> PowA(17);
  PowA[0] = 1;
  auto add = [&](int a, int b) -> int {
    a += b;
    if (a >= mod) a -= mod;
    return a;
  };
  auto mul = [&](int a, int b) -> int { return 1LL * a * b % mod; };
  for (int i = 1; i <= 16; i++) {
    PowA[i] = mul(PowA[i - 1], a);
  }
  order.push_back(1);
  for (int i = 0; i <= k - 1; i++) {
    for (int t = 0; t < (1 << i); t++) {
      order.push_back((1 << i) + 1);
    }
  }
  clock_t Start = clock();
  while (true) {
    clock_t End = clock();
    if (End - Start >= CLOCKS_PER_SEC * 3.9) break;
    shuffle(order.begin(), order.end(), rng);
    int tot = 0;
    for (int i = 1; i <= (1 << k); i++) {
      tot = add(tot, mul(i, PowA[order[i - 1]]));
    }
    if (tot == h) {
      for (auto it : order) {
        cout << it << " ";
      }
      return 0;
    }
  }
  cout << -1;
  return 0;
}
