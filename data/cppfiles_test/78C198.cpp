#include <bits/stdc++.h>
using namespace std;
int ramos = 1;
void comp1() {
  ramos++;
  ramos--;
}
long long power(long long n) {
  if (n == 0) return 1;
  long long ans = power(n / 2);
  return ans * ans % 1000000007ll * ((n % 2 == 1) ? 2 : 1) % 1000000007ll;
}
int isSubstring(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return i;
  }
  return -1;
}
void SieveOfEratosthenes(long long n, vector<long long> &v) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
}
int countPalindromicSubsequence(string s) {
  map<char, vector<int>> mp;
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]].push_back(i);
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second.size() < 2) {
      continue;
    } else {
      int n = it->second.size();
      unordered_map<char, int> m;
      for (int j = it->second[0] + 1; j < it->second[n - 1]; j++) {
        m[s[j]]++;
      }
      ans = ans + m.size();
    }
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  long long ans = -1;
  long long cur[5];
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      cur[0] = a[0][0];
      cur[1] = a[0][1];
      cur[2] = a[0][2];
      cur[3] = a[0][3];
      cur[4] = a[0][4];
      ans = i + 1;
    } else {
      long long ct = 0;
      if (a[i][0] < cur[0]) {
        ct++;
      }
      if (a[i][1] < cur[1]) {
        ct++;
      }
      if (a[i][2] < cur[2]) {
        ct++;
      }
      if (a[i][3] < cur[3]) {
        ct++;
      }
      if (a[i][4] < cur[4]) {
        ct++;
      }
      if (ct >= 3) {
        cur[0] = a[i][0];
        cur[1] = a[i][1];
        cur[2] = a[i][2];
        cur[3] = a[i][3];
        cur[4] = a[i][4];
        ans = i + 1;
      }
    }
  }
  bool flg = true;
  for (long long i = 0; i < n; i++) {
    if (i == ans - 1) {
      continue;
    } else {
      long long ct = 0;
      if (a[i][0] < cur[0]) {
        ct++;
      }
      if (a[i][1] < cur[1]) {
        ct++;
      }
      if (a[i][2] < cur[2]) {
        ct++;
      }
      if (a[i][3] < cur[3]) {
        ct++;
      }
      if (a[i][4] < cur[4]) {
        ct++;
      }
      if (ct >= 3) {
        flg = false;
        break;
      }
    }
  }
  if (!flg) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
void solve1() {
  long long l, r;
  cin >> l >> r;
  long long x = (r) / 2;
  if (r % 2 == 0) {
    x++;
  } else {
    x++;
  }
  if (r == l) {
    cout << 0 << "\n";
  } else if (x < l) {
    cout << r - l << "\n";
  } else {
    cout << r - (x) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  comp1();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve1();
  }
}
