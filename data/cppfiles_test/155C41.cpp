#include <bits/stdc++.h>
using namespace std;
long int bina(long int value, vector<long int> a) {
  long int l = 0;
  long int r = a.size() - 1;
  long int soln = r + 1;
  while (l <= r) {
    long int mid = (l + r) / 2;
    if (a[mid] > value) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return soln;
}
long int bin2(long int val, vector<long int> a) {
  long int l = 0, r = a.size() - 1;
  while (l <= r) {
    long int mid = (l + r) / 2;
    if (a[mid] > val) {
      r = mid - 1;
    } else if (a[mid] < val) {
      l = mid + 1;
    } else {
      return mid + 1;
    }
  }
}
void solve() {
  long int n;
  cin >> n;
  vector<pair<long int, long int>> a(n);
  for (long int i = 0; i < n; i += 1) {
    cin >> a[i].first;
    a[i].second = i;
  }
  set<pair<long int, long int>> ones, zeros;
  vector<long int> rate;
  long int num;
  string s;
  cin >> s;
  for (long int i = 0; i < n; i += 1) {
    if (s[i] == '0') {
      num = 0;
    } else {
      num = 1;
    }
    rate.push_back(num);
    if (num) {
      ones.insert(a[i]);
    } else {
      zeros.insert(a[i]);
    }
  }
  vector<pair<long int, long int>> one(ones.begin(), ones.end()),
      zero(zeros.begin(), zeros.end());
  if (zero.empty() || one.empty()) {
    for (long int i = 0; i < n; i += 1) {
      cout << a[i].first << " ";
    }
  } else {
    long int val = zeros.size();
    long int val2;
    long int zeroind = 0, oneind = 0;
    long int oneval = one[0].first;
    long int zeroval = zero[0].first;
    vector<long int> finval(n);
    while (true) {
      while (zeroval > oneval && oneind < one.size()) {
        finval[one[oneind].second] = one[oneind].first + val;
        oneind++;
        oneval = one[oneind].first;
      }
      while (zeroval < oneval && zeroind < zero.size()) {
        finval[zero[zeroind].second] = zeroind + 1;
        zeroind++;
        zeroval = zero[zeroind].first;
        val--;
      }
      if (zeroind == zero.size()) {
        while (oneind < one.size()) {
          finval[one[oneind].second] = one[oneind].first + val;
          oneind++;
        }
        break;
      }
      if (oneind == one.size()) {
        while (zeroind < zero.size()) {
          finval[zero[zeroind].second] = zeroind + 1;
          zeroind++;
        }
        break;
      }
    }
    for (long int i = 0; i < n; i += 1) {
      cout << finval[i] << " ";
    }
  }
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long int t, n;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
