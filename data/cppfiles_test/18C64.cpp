#include <bits/stdc++.h>
using namespace std;
void kick(long long t) { cout << "Case #" << t << ": "; }
bool valid(long long i, long long j, long long n, long long m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
bool perfect_square(long long a) {
  long long num = sqrt(a);
  if (num * num == a) return true;
  return false;
}
long long digits(long long n) {
  long long cnt = 0;
  while (n > 0) {
    cnt++;
    n = n / 10;
  }
  return cnt;
}
long long modularExponentiation(long long x, long long n, long long mod) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      result = ((result % mod) * (x % mod)) % mod;
    }
    x = ((x % mod) * (x % mod)) % mod;
    n = n / 2;
  }
  return result % mod;
}
long long inv = 0;
void merge(long long arr[], long long s, long long mid, long long e) {
  vector<long long> a, b;
  for (long long i = s; i <= mid; i++) a.push_back(arr[i]);
  for (long long i = mid + 1; i <= e; i++) b.push_back(arr[i]);
  long long n = a.size();
  long long m = b.size();
  long long i = 0;
  long long j = 0;
  long long ind = s;
  while (i < n && j < m) {
    if (a[i] <= b[j]) {
      arr[ind++] = a[i++];
    } else {
      inv += n - i;
      arr[ind++] = b[j++];
    }
  }
  while (i < n) arr[ind++] = a[i++];
  while (j < m) arr[ind++] = b[j++];
}
void mergesort(long long arr[], long long s, long long e) {
  if (e == s) return;
  if (e > s) {
    long long mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, mid, e);
  }
}
void solve() {
  long long n, d;
  cin >> n >> d;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  vector<vector<long long>> chains;
  long long cnt = 0;
  unordered_map<long long, long long> mp;
  long long ind = -1;
  while (cnt < n) {
    vector<long long> temp;
    ind++;
    while (mp[ind] == 0 && cnt < n) {
      temp.push_back(arr[ind]);
      mp[ind] = 1;
      ind += d;
      ind = ind % n;
      cnt++;
    }
    if (temp.size()) chains.push_back(temp);
  }
  long long ans = 0;
  for (long long i = 0; i < chains.size(); i++) {
    vector<long long> temp = chains[i];
    long long x = temp.size();
    long long sol = 0;
    long long ma = 0;
    for (auto it : temp) {
      if (it == 1)
        sol++;
      else {
        ma = max(ma, sol);
        sol = 0;
      }
    }
    ma = max(ma, sol);
    if (ma == x) {
      cout << "-1" << endl;
      return;
    }
    if (sol) {
      for (auto it : temp) {
        if (it == 1)
          sol++;
        else
          break;
      }
      ma = max(ma, sol);
    }
    ans = max(ans, ma);
  }
  cout << ans << endl;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
