#include <bits/stdc++.h>
using namespace std;
vector<long long> primes, fact, facti;
pair<long long, long long> hashstr(string& s, long long l = 0,
                                   long long r = -1) {
  long long p = 31, q = 53, pt = 1, qt = 1;
  pair<long long, long long> hash = {0, 0};
  if (r == -1) r = s.length() - 1;
  for (int i = l; i <= r; i++) {
    hash.first = (hash.first + (s[i] - 'a') * pt) % 1000000007;
    hash.second = (hash.second + (s[i] - 'a') * qt) % 1000000007;
    pt = (pt * p) % 1000000007;
    qt = (qt * q) % 1000000007;
  }
  return hash;
}
long long binpow(long long a, long long b, long long m = -1) {
  if (m == -1) m = 1000000007;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long modi(long long a, long long m = -1) {
  if (m == -1) m = 1000000007;
  return binpow(a, 1000000007 - 2);
}
vector<long long> gen_prime(long long n) {
  vector<long long> prime;
  if (n < 2) return prime;
  prime.push_back(2);
  if (!(n & 1)) n--;
  vector<bool> is_prime(n / 2, true);
  for (long long i = 3; i * i <= n; i += 2) {
    if (!is_prime[(i - 3) / 2]) continue;
    for (long long j = i * i; j <= n; j += i + i) {
      is_prime[(j - 3) / 2] = false;
    }
  }
  for (int i = 0; i < is_prime.size(); i++) {
    if (is_prime[i]) prime.push_back(i * 2 + 3);
  }
  return prime;
}
void gen_factorial(long long n, bool invert) {
  fact.push_back(1);
  if (invert) facti.push_back(modi(1));
  long long f;
  for (long long i = 1; i <= n; i++) {
    f = (fact[i - 1] * i) % 1000000007;
    fact.push_back(f);
    if (invert) {
      facti.push_back(modi(f));
    }
  }
}
void vlInput(vector<long long>& a) {
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
}
long long factorial(long long n) {
  if (n == 0) return 1ll;
  return (n * factorial(n - 1)) % 1000000007;
}
struct triplet {
  long long next, val, last;
};
struct custom {
  long long x, y, z;
};
class minComp {
 public:
  bool operator()(custom& a, custom& b) const {
    long long ad = abs(a.x - a.y), bd = abs(b.x - b.y);
    if (ad == bd) {
      return a.x > b.x;
    }
    return ad < bd;
  }
};
long long factor_count(long long n) {
  long long cnt = 0;
  while (n % 2 == 0) {
    cnt++;
    n = n / 2;
  }
  for (int i = 0; primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      cnt++;
      n = n / primes[i];
    }
  }
  if (n > 2) cnt++;
  return cnt;
}
long long lis(vector<long long>& a) {
  vector<long long> dp(a.size() + 1, 1000000007);
  long long mxl = -1, l;
  dp[0] = -1000000007;
  for (long long i = 0; i < a.size(); i++) {
    long long l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    mxl = max(mxl, l);
    if (dp[l - 1] < a[i] && a[i] < dp[l]) dp[l] = a[i];
  }
  return mxl;
}
void build_segment(vector<long long>& a, long long l, long long r,
                   vector<long long>& segment, long long pos) {
  if (l == r) {
    segment[pos] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build_segment(a, l, mid, segment, pos * 2);
  build_segment(a, mid + 1, r, segment, pos * 2 + 1);
  segment[pos] = max(segment[pos * 2], segment[pos * 2 + 1]);
}
long long operateSegment(vector<long long>& segment, long long l, long long r,
                         long long tl, long long tr, long long pos) {
  if (l > r) return -1;
  if (l == tl && r == tr) return segment[pos];
  long long mid = (l + r) / 2;
  long long ans, t1;
  if (mid >= tl) {
    t1 = operateSegment(segment, l, mid, tl, min(mid, tr), pos * 2);
  }
  if (mid < tr) {
    ans =
        operateSegment(segment, mid + 1, r, max(mid + 1, tl), tr, pos * 2 + 1);
  }
  ans = max(ans, t1);
  return ans;
}
void updateSegment(vector<pair<long long, long long> >& segment, long long l,
                   long long r, long long up, long long uv, long long p) {
  if (l == r && l == up) {
    segment[p].first = uv;
    return;
  }
  long long mid = (l + r) / 2;
  if (up <= mid) {
    updateSegment(segment, l, mid, up, uv, p * 2);
  } else {
    updateSegment(segment, mid + 1, r, up, uv, p * 2 + 1);
  }
  segment[p].first = segment[p * 2].first + segment[p * 2 + 1].first;
  segment[p].second = segment[p * 2].second;
  if (segment[p * 2 + 1].first > 0)
    segment[p].second = segment[p * 2 + 1].second;
}
bool sort_input(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
bool myComp(char& a, char& b) { return a > b; }
int getUniqueUserIdSum(vector<int> arr) {
  int mx = 6000, n = arr.size();
  vector<int> cnt(mx, 0);
  for (auto i : arr) {
    cnt[i]++;
  }
  int ans = 0;
  int left = 0;
  for (int i = 0; i < mx; i++) {
    if (cnt[i] > 0) {
      cnt[i]--;
      left += cnt[i];
      ans += i;
    } else if (left > 0) {
      ans += i;
      left--;
    }
  }
  return ans;
}
long carParkingRoof(vector<long> a, long k) {
  sort(a.begin(), a.end());
  long INF = 1e9 + 7;
  long n = a.size();
  long ans = INF, sum = 0;
  for (int i = k - 1; i < n; i++) {
    sum = a[i] - a[i - k + 1] + 1;
    ans = min(ans, sum);
  }
  if (ans == INF) ans = 0;
  return ans;
}
int finalInstances(int n, vector<int> a) {
  int watch = 0;
  int mx = 1e8;
  for (auto i : a) {
    if (watch > 0) {
      watch--;
      continue;
    }
    if (i > 60 && n <= mx) {
      n *= 2;
      watch = 10;
    } else if (i < 25 && n > 1) {
      n = (n + 1) / 2;
      watch = 10;
    }
  }
  return n;
}
int exam(vector<int> a) {
  int n = a.size();
  vector<int> p(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    p[i] = p[i + 1];
    if (a[i] == 1)
      p[i]++;
    else
      p[i]--;
  }
  int yr = 0;
  for (int i = 0; i < n; i++) {
    if (yr > p[i]) return i;
    if (a[i] == 1)
      yr++;
    else
      yr--;
  }
  return -1;
}
vector<string> extract(string a) {
  vector<string> ans;
  string w;
  for (auto i : a) {
    if (i == ' ') {
      ans.push_back(w);
      w = "";
    } else {
      w.push_back(i);
    }
  }
  return ans;
}
vector<string> pl(vector<string> l, long long t) {
  map<string, long long> m;
  for (auto i : l) {
    vector<string> v = extract(i);
    m[v[0]]++;
    if (v[0] != v[1]) m[v[1]]++;
  }
  vector<string> ans;
  for (auto i : m) {
    if (i.second >= t) {
      ans.push_back(i.first);
    }
  }
  return ans;
}
void solve() {
  long long n;
  char k;
  string s;
  cin >> n >> k >> s;
  vector<long long> r;
  for (long long i = 0; i < n; i++) {
    if (s[i] == k) {
      r.push_back(i + 1);
    }
  }
  if (r.size() == n) {
    cout << "0\n";
    return;
  }
  vector<bool> iwd(n + 1, true);
  for (int m = r.size() - 1; m >= 0; m--) {
    long long i = r[m];
    iwd[i] = false;
    for (long long j = i + i; j <= n; j += i) {
      if (iwd[j]) {
        iwd[i] = true;
        break;
      }
    }
  }
  long long isOne = -1;
  for (auto i : r) {
    if (!iwd[i]) {
      isOne = i;
      break;
    }
  }
  if (isOne != -1)
    cout << "1\n" << isOne << "\n";
  else
    cout << "2\n" << n - 1 << " " << n << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i = 0;
  cin >> t;
  for (i = 1; i <= t; i++) solve();
  return 0;
}
