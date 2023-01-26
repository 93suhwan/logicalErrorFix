#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
void debugi(vector<int>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugd(vector<long double>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugl(vector<ll>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugmap(map<int, int>& mp) {
  for (auto x : mp) {
    cout << x.first << " " << x.second << " , ";
  }
  cout << endl;
}
void debugset(set<int>& st) {
  for (auto x : st) {
    cout << x << " ";
  }
  cout << endl;
}
void debugparri(vector<pair<int, int>>& arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    cout << "[" << arr[i].first << " : " << arr[i].second << "]"
         << " ";
  }
  cout << endl;
}
void debugpi(pair<int, int>& pi) {
  cout << pi.first << " " << pi.second << endl;
}
void debugq(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
bool check(int n, int i, int j) {
  if ((0 <= i & i < n) && (0 <= j & j < n)) {
    return true;
  }
  return false;
}
ll MOD = 1e9 + 7;
ll powab(ll a, ll b, ll mod) {
  if (b == 0) {
    return 1;
  }
  ll z = powab(a, b / 2, mod);
  ll res = (z * z * 1LL) % mod;
  if (b & 1) {
    res = (res * 1LL * a) % mod;
  }
  return res;
}
ll modinv(ll a, ll mod) {
  ll ans = powab(a, mod - 2, mod);
  return ans;
}
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void upd(int k, int x, vector<ll>& tree, int n) {
  if (k == 0) {
    return;
  }
  while (k <= n) {
    tree[k] += x;
    k += (k & -k);
  }
}
ll sum(int k, vector<ll>& tree, int n) {
  ll s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= (k & -k);
  }
  return s;
}
int lim = 2000005, cyc = 0;
vector<int> primes(lim, 0);
void fill() {
  for (int i = 0; i < lim; i++) primes[i] = i;
  for (int i = 2; i * i < lim; i++) {
    if (primes[i] == i) {
      for (int j = i * i; j < lim; j += i) {
        if (primes[j] == j) {
          primes[j] = i;
        }
      }
    }
  }
}
vector<vector<int>> g(lim);
vector<vector<int>> dp(30, vector<int>(30));
ll res = 1e15;
int b, c;
vector<int> vis(30);
void solve(int tt, int t) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n <= 1) {
    cout << "Alice" << endl;
    return;
  }
  int lastl = 0, lastr = n - 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      lastl = i;
    } else {
      break;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      lastr = i;
    } else {
      break;
    }
  }
  vector<int> left, right;
  for (int i = 0; i <= lastl; i++) left.push_back(a[i]);
  for (int i = n - 1; i >= lastr; i--) right.push_back(a[i]);
  int idxl = 0, idxr = 0, cnt = 0;
  int szl = left.size(), szr = right.size();
  while (idxl < szl && idxr < szr) {
    if (left[idxl] > right[idxr]) {
      if ((szl - idxl) % 2 != 0) {
        if (cnt % 2 == 0) {
          cout << "Alice" << endl;
          return;
        } else {
          cout << "Bob" << endl;
          return;
        }
      } else {
        idxr += 1;
        cnt += 1;
        continue;
      }
    }
    if (right[idxr] > left[idxl]) {
      if ((szr - idxr) % 2 != 0) {
        if (cnt % 2 == 0) {
          cout << "Alice" << endl;
          return;
        } else {
          cout << "Bob" << endl;
          return;
        }
      } else {
        idxl += 1;
        cnt += 1;
        continue;
      }
    }
    if ((szr - idxr) % 2 != 0) {
      if (cnt % 2 == 0) {
        cout << "Alice" << endl;
        return;
      } else {
        cout << "Bob" << endl;
        return;
      }
    }
    if ((szl - idxl) % 2 != 0) {
      if (cnt % 2 == 0) {
        cout << "Alice" << endl;
        return;
      } else {
        cout << "Bob" << endl;
        return;
      }
    }
    if (cnt % 2 == 0) {
      cout << "Bob" << endl;
      return;
    } else {
      cout << "Alice" << endl;
      return;
    }
  }
  cnt += (szl - idxl);
  cnt += (szr - idxr);
  if (cnt % 2 != 0) {
    cout << "Alice" << endl;
    return;
  } else {
    cout << "Bob" << endl;
    return;
  }
  return;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  for (int tt = 0; tt < t; tt++) {
    solve(tt, t);
  }
  return 0;
}
