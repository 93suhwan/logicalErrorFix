#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
bool isPo2(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int toint(const string &s) {
  stringstream second;
  second << s;
  int x;
  second >> x;
  return x;
}
string tostring(int number) {
  stringstream second;
  second << number;
  return second.str();
}
long long xorUptoN(long long n) {
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  return 0;
}
long long modExpo(long long x, long long y, int p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_Inv(long long a, long long p) { return modExpo(a, p - 2, p); }
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> pref = arr;
    for (int i = 1; i < n; i++) {
      pref[i] += pref[i - 1];
    }
    if (pref[n - 1] < k) {
      cout << 0 << "\n";
    } else {
      int cnt = 0;
      long long ans = pref[n - 1] - k;
      for (int i = n - 1; i > 0; i--) {
        cnt++;
        int reqSum = k - (pref[i - 1] - pref[0]);
        int eachVal = reqSum / (cnt + 1);
        if ((reqSum < 0) and ((reqSum % (cnt + 1)) != 0)) eachVal--;
        long long temp = cnt;
        if (arr[0] > eachVal) temp += (arr[0] - eachVal);
        ans = min(ans, temp);
      }
      cout << ans << "\n";
    }
  }
}
