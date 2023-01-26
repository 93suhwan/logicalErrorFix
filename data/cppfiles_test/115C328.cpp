#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}
bool cmpl(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}
template <typename T>
string itos(T i) {
  stringstream s;
  s << i;
  return s.str();
}
int isprime(long long int x) {
  int count = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      if (i * i == x)
        count++;
      else
        count += 2;
    }
  }
  if (count == 2)
    return 1;
  else
    return 0;
}
bool possible(long long int x, long long int n, vector<long long int> v,
              long long int h) {
  long long int sum = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (x > v[i + 1] - v[i])
      sum += v[i + 1] - v[i];
    else {
      sum += x;
    }
  }
  sum += x;
  if (sum >= h) {
    return true;
  } else {
    return false;
  }
}
void tests() {
  long long int n, h;
  cin >> n >> h;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int lo = 1, hi = 1e18, mid;
  sort(a.begin(), a.end());
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (possible(mid, n, a, h)) {
      hi = mid;
    } else {
      lo = mid + 1LL;
    }
  }
  if (possible(lo, n, a, h))
    cout << lo << "\n";
  else if (possible(hi, n, a, h))
    cout << hi << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    tests();
  }
  return 0;
}
