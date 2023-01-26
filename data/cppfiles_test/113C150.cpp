#include <bits/stdc++.h>
using namespace std;
bool func(unsigned long long n) {
  unsigned long long x = n;
  int i;
  vector<int> v;
  while (x > 0) {
    if (x % 10 != 0) v.push_back(x % 10);
    x = x / 10;
  }
  for (i = 0; i < v.size(); i++) {
    if (n % (v[i]) != 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int k, mid = 0, x, m, flag = 0, o, n, l;
  int i, j;
  int sum = 0;
  string b, a;
  cin >> n >> m;
  cin >> l >> k;
  x = n;
  i = l;
  while (x > 0) {
    sum++;
    x /= 10;
  }
  while (i > 0) {
    i /= 10;
    mid++;
  }
  if (sum > mid) {
    j = sum - mid;
    for (i = 0; i < j; i++) {
      l *= 10;
      k--;
    }
    if (m > k) {
      cout << ">" << endl;
      return;
    } else if (k > m) {
      cout << "<" << endl;
      return;
    } else {
      if (n > l) {
        cout << ">" << endl;
        return;
      } else if (l > n) {
        cout << "<" << endl;
        return;
      } else {
        cout << "=" << endl;
        return;
      }
    }
  } else if (mid > sum) {
    j = mid - sum;
    for (i = 0; i < j; i++) {
      n *= 10;
      m--;
    }
    if (m > k) {
      cout << ">" << endl;
      return;
    } else if (k > m) {
      cout << "<" << endl;
      return;
    } else {
      if (n > l) {
        cout << ">" << endl;
        return;
      } else if (l > n) {
        cout << "<" << endl;
        return;
      } else {
        cout << "=" << endl;
        return;
      }
    }
  } else {
    if (m > k) {
      cout << ">" << endl;
      return;
    } else if (k > m) {
      cout << "<" << endl;
      return;
    } else {
      if (n > l) {
        cout << ">" << endl;
        return;
      } else if (l > n) {
        cout << "<" << endl;
        return;
      } else {
        cout << "=" << endl;
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
