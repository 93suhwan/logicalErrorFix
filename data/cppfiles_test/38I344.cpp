#include "bits/stdc++.h"

using namespace std;

#define tcT template <class T
#define tcTU tcT, class U

using i64 = int64_t;
tcT> using vt = vector<T>;
tcT> using vvt = vt<vt<T>>;
tcTU> using pr = pair<T, U>;
tcTU> using vpr = vt<pr<T, U>>;

#define sz(v) static_cast<int>((v).size())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct CustomHash {
  static uint64_t SplitMix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r = chrono::steady_clock::now().time_since_epoch().count();
    return SplitMix64(x + r);
  }
};

tcT> bool Max(T& a, const T& b) { return a < b && (a = b, true); }
tcT> bool Min(T& a, const T& b) { return a > b && (a = b, true); }

tcT> T FDiv(const T& a, const T& b) { return a / b - ((a ^ b) < 0 && (a % b) > 0); }
tcT> T CDiv(const T& a, const T& b) { return a / b + ((a ^ b) > 0 && (a % b) > 0); }

tcT> ostream& operator<<(ostream& out, const vt<T>& v) { for (auto& c : v) out << c << ' '; return out << '\n'; }
ostream& operator<<(ostream& out, const vvt<char>& v) { for (auto& r : v) { for (auto& c : r) out << c; out << '\n'; } return out << ""; }
tcT> ostream& operator<<(ostream& out, const vvt<T>& v) { for (auto& r : v) out << r; return out << ""; }
tcTU> ostream& operator<<(ostream& out, const pr<T, U>& p) { return out << p.first << ' ' << p.second; }
tcTU> ostream& operator<<(ostream& out, const vpr<T, U>& v) { for (auto& p : v) out << p; return out << ""; }

tcT> istream& operator>>(istream& in, vt<T>& v) { for (int i = 0; i < sz(v) - 1; ++i) in >> v[i]; return in >> v.back(); }
tcTU> istream& operator>>(istream& in, pr<T, U>& p) { return in >> p.first >> p.second; }
tcTU> istream& operator>>(istream& in, vpr<T, U>& v) { for (int i = 0; i < sz(v) - 1; ++i) in >> v[i]; return in >> v.back(); }

const int kMod0 = 1'000'000'007, kMod1 = 998'244'353, kMax0 = 200'005, kMax1 = 10'000'005;
const i64 kMax2 = 1'000'000'000'000'000'005;

const int kDi[] = { 0, -1, -1, -1,  0, +1, +1, +1};
const int kDj[] = {+1, +1,  0, -1, -1, -1,  0, +1};
//                  R  UR   U  UL   L  DL   D  DR

void Debug(const string& file_name_pfx) {
  freopen((file_name_pfx + ".in").c_str(), "r", stdin);
  freopen((file_name_pfx + ".out").c_str(), "w", stdout);
}

void Solve(int test_num) {
  int n, m;
  cin >> n >> m;
  vvt<char> grid(n, vt<char> (m));
  cin >> grid;
  vt<bool> bad(m);
  for (int j = 1; j < m; ++j)
    for (int i = 1; i < n; ++i)
      bad[j] = bad[j] || (grid[i - 1][j] == 'X' && grid[i][j - 1] == 'X');
  vt<int> psa(m);
  partial_sum(bad.begin(), bad.end(), psa.begin());
  int q;
  cin >> q;
  for (int i = 0, x1, x2; i < q; ++i) {
    cin >> x1 >> x2, --x1, --x2;
    cout << (psa[x2] - psa[x1] > 0 ? "no\n" : "yes\n");
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  // Debug("../test");
  int num_of_cases = 1;
  // cin >> num_of_cases;
  for (int test_num = 1; test_num <= num_of_cases; ++test_num)
    Solve(test_num);
}