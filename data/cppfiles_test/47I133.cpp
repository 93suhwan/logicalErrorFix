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
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    long long ans = 0;
    auto returnlen = [&](vector<long long> arr, long long x) -> long long {
      if (arr.size() == 0) return 0;
      long long an = arr[0];
      int last = arr[0];
      if (x == 0) x = k;
      for (int i = 0; i < arr.size(); i++) {
        an += abs(last - arr[i]);
        last = arr[i];
        x--;
        if (x == 0 and i < arr.size() - 1) {
          an += arr[i];
          x = k;
          last = 0;
        }
      }
      an += last;
      return an;
    };
    auto non_return = [&](vector<long long> arr, long long x) -> long long {
      long long an = 0;
      long long last = 0;
      if (x == 0) x = k;
      if (arr.size() == 0) return 0;
      for (long long i = arr.size() - 1; i >= 0; i--) {
        an += (arr[i] - last);
        x--;
        last = arr[i];
        if (x == 0 and i) {
          an += arr[i];
          x = k;
          last = 0;
        }
      }
      return an;
    };
    if (neg.size() and pos.size())
      ans =
          min(returnlen(pos, pos.size() % k) + non_return(neg, neg.size() % k),
              returnlen(neg, neg.size() % k) + non_return(pos, pos.size() % k));
    else if (neg.size())
      ans = non_return(neg, neg.size() % k);
    else if (pos.size())
      ans = non_return(pos, pos.size() % k);
    cout << ans << "\n";
  }
  return 0;
}
