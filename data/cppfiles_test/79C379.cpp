#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr auto mod = 1000000007;
constexpr size_t sz = 200000;
int k, res;
string s;
vector<int> cnt(10);
inline int isComposite(int plate) {
  int num = 0, mask = 1 << (k - 1);
  for (int i = 0; mask; ++i, mask >>= 1) {
    if (mask bitand plate) {
      num *= 10;
      num += s[i] - '0';
    }
  }
  for (int i = 2; i < num; ++i)
    if (num % i == 0) return num;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    fill(begin(cnt), end(cnt), 0);
    cin >> k >> s;
    for (auto& c : s) {
      ++cnt[c - '0'];
      if (c != '2' and c != '3' and c != '5' and c != '7') {
        cout << "1\n" << c << '\n';
        goto end_case;
      }
    }
    cout << "2\n";
    for (int i = 0; i < 10; ++i)
      if (cnt[i] > 1) {
        cout << i << i << '\n';
        goto end_case;
      }
    for (int i = 1; i < (1 << k); ++i)
      if (res = isComposite(i)) {
        cout << res << '\n';
        break;
      }
  end_case:;
  }
}
