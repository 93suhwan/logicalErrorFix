#include <bits/stdc++.h>
using namespace std;
void solve1() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  int c = a[n - 1];
  int cnt = 0;
  for (long long int i = n - 2; i >= 0; i--) {
    if (a[i] > c) {
      c = a[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}
void solve3() {
  long long int n, k, i;
  cin >> n >> k;
  long long int arr[n], ans = 0;
  map<long long int, long long int> mp;
  long long int maxi = 0;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]]++;
    if (mp[arr[i]] % k == 0) {
      ans += 2 * arr[i];
      mp[arr[i]] = mp[arr[i]] % k;
    }
    maxi = max(maxi, abs(arr[i]));
  }
  long long int posi[n], p = 0;
  long long int negi[n], neg = 0;
  map<long long int, long long int>::iterator itr;
  for (itr = mp.begin(); itr != mp.end(); itr++) {
    if (itr->first < 0) {
      ans += itr->second / k;
      ans += itr->second / k;
      for (i = 0; i < itr->second % k; i++) negi[neg++] = itr->first * -1;
    } else if (itr->first > 0) {
      ans += itr->second / k;
      ans += itr->second / k;
      for (i = 0; i < itr->second % k; i++) posi[p++] = itr->first;
    }
  }
  sort(posi, posi + p);
  sort(negi, negi + neg);
  for (i = 0; i + k < p; i += k) {
    ans += posi[i + k - 1] * 2;
  }
  if (p == 0 && neg == 0) {
    cout << ans - maxi << endl;
    return;
  }
  if (p == 0) {
    ans += negi[neg - 1] * 2;
  } else if (neg == 0) {
    ans += posi[p - 1] * 2;
  } else if (p != 0 && neg != 0) {
    ans += posi[p - 1] * 2 + negi[neg - 1] * 2;
  }
  for (i = 0; i + k < neg; i += k) {
    ans += negi[i + k - 1] * 2;
  }
  ans -= maxi;
  cout << ans << endl;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  int score = 0;
  int idx = k, i;
  for (i = 0; i + idx < n && i < k; i++) {
    score += a[i + idx] / a[i];
  }
  for (int j = 2 * i; j < n; j++) {
    score += a[j];
  }
  cout << score << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    solve();
  }
}
