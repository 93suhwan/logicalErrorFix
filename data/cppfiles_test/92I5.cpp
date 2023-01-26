#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
int n, c;
vector<int> guessed;
const int N = 1000007;
vector<int> allp[N];
vector<int> ask(vector<int> queries) {
  int q = queries.size();
  for (auto first : queries) cout << first << " ";
  cout << endl;
  vector<int> ans(q);
  for (auto& first : ans) cin >> first;
  return ans;
}
int main() {
  cin >> c >> n;
  for (int i = 2; i < N; ++i) {
    if (!allp[i].size()) {
      for (int j = i; j < N; j += i) allp[j].push_back(i);
    }
  }
  vector<int> queries;
  vector<bool> good;
  vector<int> pos(c, -1);
  int t = 0;
  for (int i = 1; i <= c; ++i) {
    bool take = true;
    for (auto first : allp[i]) {
      if ((long long)i % ((long long)first * first) == 0) take = false;
    }
    if (take) {
      queries.push_back(i);
      pos[i - 1] = t++;
    }
    good.push_back(take);
  }
  vector<int> ans = ask(queries);
  vector<int> want(c, -1);
  for (int i = c; i >= 1; --i) {
    if (want[i - 1] != -1) continue;
    if (!good[i - 1]) continue;
    vector<int> unknown;
    int first = 0;
    for (int j = i; j <= c; j += i) {
      if (want[j - 1] == -1)
        unknown.push_back(j);
      else if (want[j - 1] == 1)
        first ^= j;
    }
    for (int mask = 0; mask < (1 << allp[i].size()); ++mask) {
      int P = 1;
      for (int j = 0; j < allp[i].size(); ++j) {
        if ((1 << j) & mask) {
          P *= allp[i][j];
        }
      }
      first ^= ans[pos[P - 1]];
    }
    bool decided = false;
    for (int mask = 0; mask < (1 << unknown.size()); ++mask) {
      int t = 0;
      for (int j = 0; j < unknown.size(); ++j) {
        if ((1 << j) & mask) {
          t ^= unknown[j];
        }
      }
      if (t == first) {
        for (int j = 0; j < unknown.size(); ++j) {
          if ((1 << j) & mask) {
            want[unknown[j] - 1] = true;
          } else
            want[unknown[j] - 1] = false;
        }
        decided = true;
        break;
      }
    }
    assert(decided);
  }
  for (int i = 0; i < c; ++i)
    if (want[i]) cout << i + 1 << " ";
  cout << endl;
}
