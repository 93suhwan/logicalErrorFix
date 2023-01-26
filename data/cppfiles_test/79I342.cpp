#include <bits/stdc++.h>
using namespace std;
long long int mod(long long int x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long int add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
bool cmp(const int &a, const int &b) { return a > b; }
bool comp2(pair<long long int, long long int> a,
           pair<long long int, long long int> b) {
  if (b.first > a.first) {
    return true;
  }
  if (b.first == a.first) {
    if (b.second > a.second)
      return true;
    else
      return false;
  } else
    return false;
}
bool isPowerOfTwo(int x) { return (x && !(x & (x - 1))); }
int count_one(int n) {
  long long int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}
bool check_set(int N, int i) {
  if (N & (1 << i))
    return true;
  else
    return false;
}
void possibleSubsets(char A[], int N) {
  for (int i = 0; i < (1 << N); ++i) {
    for (int j = 0; j < N; ++j)
      if (i & (1 << j)) cout << A[j];
    cout << endl;
  }
}
vector<long long int> v[100005];
long long int vis[100005];
void dfs(long long int node) {
  vis[node] = 1;
  for (auto child : v[node]) {
    if (vis[child] == 0) {
      dfs(child);
    }
  }
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int flag = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      flag = 0;
      cout << 1 << "\n";
      cout << 1 << "\n";
      return;
    }
  }
  int check = 0;
  if (flag) {
    int ans;
    for (int i = 0; i < s.length(); i++) {
      int r = s[i] - '0';
      if (isPrime(r)) {
        check = 1;
      } else {
        check = 0;
        ans = r;
        break;
      }
    }
    if (!check) {
      cout << 1 << "\n";
      cout << ans << "\n";
      return;
    } else {
      int k1 = 0;
      int k2 = 0;
      int k3 = 0;
      int k4 = 0;
      int i1 = 0;
      int i2 = 0;
      int i3 = 0;
      int i4 = 0;
      for (int i = 0; i < s.length(); i++) {
        int r = s[i] - '0';
        if (r == 3) {
          k1++;
          i1 = i;
        }
        if (r == 5) {
          k2++;
          i2 = i;
        }
        if (r == 7) {
          k3++;
          i3 = i;
        }
        if (r == 2) {
          k4++;
          i4 = i;
        }
      }
      if (k1 >= 2) {
        cout << 2 << endl;
        cout << 33 << endl;
        return;
      }
      if (k2 >= 2) {
        cout << 2 << endl;
        cout << 55 << endl;
        return;
      }
      if (k3 >= 2) {
        cout << 2 << endl;
        cout << 77 << endl;
        return;
      }
      if (k4 >= 2) {
        cout << 2 << endl;
        cout << 22 << endl;
        return;
      }
      if (k2 >= 1 && (k1 >= 1) && (i1 < i2)) {
        cout << 2 << endl;
        cout << 35 << endl;
        return;
      }
      if (k2 >= 1 && (k3 >= 1) && (i3 < i2)) {
        cout << 2 << endl;
        cout << 75 << endl;
        return;
      }
      if (k2 >= 1 && (k4 >= 1) && (i4 < i2)) {
        cout << 2 << endl;
        cout << 25 << endl;
        return;
      }
      if (k4 >= 1 && (k3 >= 1) && (i4 < i3)) {
        cout << 2 << endl;
        cout << 27 << endl;
        return;
      }
    }
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
