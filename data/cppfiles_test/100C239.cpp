#include <bits/stdc++.h>
using namespace std;
const unsigned int ev = 0xAAAAAAAA;
const unsigned int od = 0x55555555;
const long long MOD2 = 1000000007;
const long long MOD1 = 998244353;
void kmp(long long n, long long a[], long long s[]) {
  a[0] = 0;
  for (auto i = 1; i < n; i++) {
    long long j = a[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = a[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    a[i] = j;
  }
}
void dfsUtil(vector<vector<long long>> &adj, long long s, long long par,
             long long b[], long long a[]) {
  for (auto pro : adj[s]) {
    if (pro != par) {
      dfsUtil(adj, pro, s, b, a);
    }
  }
  b[s] = a[s];
  for (auto pro : adj[s]) {
    b[s] += b[pro];
  }
}
long long fp(long long x, long long n, long long MOD) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans *= x;
    x *= x;
    ans %= MOD;
    x %= MOD;
    n /= 2;
  }
  return ans;
}
void mobiusmu(long long n, long long vals[], bool comps[]) {
  vals[1] = 1;
  vector<long long> primevec;
  for (auto i = 2; i <= n; i++) {
    if (!comps[i]) {
      primevec.push_back(i);
      vals[i] = -1;
    }
    for (auto j = 0; j < primevec.size() && (primevec[j]) * i <= n; j++) {
      if (i % (primevec[j]) == 0) {
        vals[i * (primevec[j])] = 0;
        break;
      } else {
        vals[i * (primevec[j])] = vals[i] * vals[primevec[j]];
      }
    }
  }
}
void makesegtree(vector<long long> &segtree, long long n, long long a[]) {
  for (auto i = n; i <= 2 * n - 1; i++) {
    segtree[i] = a[i - n];
  }
  for (long long i = n - 1; i > 0; i--) {
    segtree[i] = min(segtree[2 * i], segtree[2 * i + 1]);
  }
}
void update(vector<long long> &segtree, long long n, long long l,
            long long al) {
  l -= 1;
  l += n;
  segtree[l] = al;
  while (l / 2 > 0) {
    if (l % 2) {
      segtree[l / 2] = max(segtree[l - 1], segtree[l]);
    } else {
      segtree[l / 2] = max(segtree[l], segtree[l + 1]);
    }
    l /= 2;
  }
}
long long operate(vector<long long> &segtree, long long n, long long x1,
                  long long x2) {
  long long maax = 1000000000000000;
  long long i1 = x1 - 1;
  long long i2 = x2 - 1;
  i1 += n;
  i2 += n;
  while (i1 <= i2) {
    if (i1 % 2) {
      maax = min(maax, segtree[i1++]);
    }
    if (i2 % 2 == 0) {
      maax = min(maax, segtree[i2--]);
    }
    i1 /= 2;
    i2 /= 2;
  }
  return maax;
}
long long eugcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    long long temp = a;
    a = b;
    b = temp % a;
  }
  return a;
}
long long fensum(long long arr[], long long i) {
  long long res = 0;
  while (i >= 0) {
    res += arr[i];
    i = (i & (i + 1)) - 1;
  }
  return res;
}
void fenupdate(long long arr[], long long i, long long del, long long n) {
  while (i < n) {
    arr[i] += del;
    i |= (i + 1);
  }
}
long long fact[600001];
long long invfact[600001];
long long nck(long long n, long long k) {
  long long ans = 1;
  ans *= fact[n];
  ans *= invfact[k];
  ans %= 998244353;
  ans *= invfact[n - k];
  ans %= 998244353;
  return ans;
}
long long answer(vector<vector<long long>> &adj, long long n, long long s,
                 long long a[], long long b[]) {
  if (adj[s].size() == 0) {
    return b[s];
  } else {
    long long maax = 0;
    long long ind = -1;
    for (auto pro : adj[s]) {
      maax = max(maax, b[pro]);
      if (maax == b[pro]) {
        ind = pro;
      }
    }
    for (auto pro : adj[s]) {
      if (a[s] >= maax - b[pro]) {
        a[s] -= (maax - b[pro]);
        b[pro] = maax;
      }
    }
    if (a[s]) {
      long long siz = adj[s].size();
      for (auto pro : adj[s]) {
        b[pro] += a[s] / siz;
        ind = pro;
      }
      if (a[s] % siz) {
        for (auto pro : adj[s]) {
          b[pro] += 1;
          ind = pro;
          break;
        }
      }
    }
    return answer(adj, n, ind, a, b);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (auto i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long negsig = 0;
    long long ans = a[0];
    for (auto i = 0; i < n; i++) {
      a[i] -= negsig;
      ans = max(ans, a[i]);
      negsig += a[i];
    }
    cout << ans << endl;
  }
}
