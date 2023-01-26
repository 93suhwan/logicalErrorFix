#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
using namespace std;
template <typename val1>
void __f(const char* name, val1&& value) {
  cout << name << " = " << value << endl;
}
template <typename val1, typename... values>
void __f(const char* names, val1&& value, values&&... multiplevalue) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " = " << value << " ";
  __f(comma + 1, multiplevalue...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long k;
    cin >> k;
    vector<long long> pos, neg;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      if (a > 0) {
        pos.push_back(a);
      } else if (a < 0) {
        neg.push_back(-a);
      }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long ans = 0;
    auto ans_check = [&](vector<long long> arr, long long x) -> long long {
      if (x == 0) x = k;
      long long last = 0;
      long long an = 0;
      for (int i = 0; i < arr.size(); i++) {
        an += (arr[i] - last);
        x--;
        last = arr[i];
        if (x == 0) {
          x = k;
          an += arr[i];
          last = 0;
        }
      }
      return an;
    };
    if (pos.size() and neg.size()) {
      ans = ans_check(pos, pos.size() % k) + ans_check(neg, neg.size() % k) -
            max(neg.back(), pos.back());
    } else if (pos.size()) {
      ans = ans_check(pos, pos.size() % k) - pos.back();
    } else if (neg.size()) {
      ans = ans_check(neg, neg.size() % k) - neg.back();
    }
    cout << ans << "\n";
  }
  return 0;
}
