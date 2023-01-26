#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 1;
int n;
int ans[MAXN];
vector<int> a;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ti;
const int MOD = (1 << 22) - 1;
struct HASH_TABLE {
  int tp[MOD];
  vector<int> nex;
  vector<bitset<26> > val;
  vector<pair<int, int> > is;
  HASH_TABLE() { fill(tp, tp + MOD, -1); }
  void insert(pair<int, int> p, bitset<26> v) {
    int se = (p.first << 2) ^ p.second ^ (p.first >> 10);
    se &= MOD;
    nex.push_back(tp[se]);
    tp[se] = nex.size() - 1;
    val.push_back(v);
    is.push_back(p);
  }
  bool find(pair<int, int> p) {
    int se = (p.first << 2) ^ p.second ^ (p.first >> 10);
    se &= MOD;
    for (int now = tp[se]; now != -1; now = nex[now]) {
      if (is[now] == p) return true;
    }
    return false;
  }
  bitset<26> query(pair<int, int> p) {
    int se = (p.first << 2) ^ p.second ^ (p.first >> 10);
    se &= MOD;
    for (int now = tp[se]; now != -1; now = nex[now]) {
      if (is[now] == p) return val[now];
    }
    return val[0];
  }
} ht;
void noans() {
  vector<int> A, B;
  while (clock() - ti < 980) {
    bitset<26> Tmp;
    pair<int, int> P = make_pair(0, 0);
    for (int i = 0; i < min(n, 26); ++i) {
      if (rng() % 2) {
        Tmp.set(i);
        P.first += a[i];
        P.second++;
      }
    }
    if (ht.find(P)) {
      if (ht.query(P) != Tmp) {
        bitset<26> AA, BB;
        AA = ht.query(P);
        BB = AA & Tmp;
        AA ^= BB;
        Tmp ^= BB;
        for (int i = 0; i < min(n, 26); ++i)
          if (AA[i])
            A.push_back(a[i]);
          else if (Tmp[i])
            B.push_back(a[i]);
        break;
      }
    } else {
      ht.insert(P, Tmp);
    }
  }
  if (A.empty()) {
    puts("NO");
    exit(0);
  }
  vector<int> Z;
  for (int i = 0; i < A.size(); ++i) Z.push_back(A[i]), Z.push_back(B[i]);
  ans[1] = 0;
  for (int i = 1; i <= A.size() + B.size() - 1; ++i)
    ans[i + 1] = Z[i - 1] - ans[i];
  sort(Z.begin(), Z.end());
  int now = A.size() * 2 + 1;
  for (auto it : a) {
    if (binary_search(Z.begin(), Z.end(), it))
      ;
    else {
      ans[now] = it - ans[now - 1];
      now++;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  exit(0);
}
int main() {
  scanf("%d", &n);
  ti = clock();
  a.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  if (a.size() != n) {
    ans[1] = 1;
    for (int i = 0; i < a.size(); ++i) {
      ans[i + 2] = a[i] - 1;
    }
  } else {
    int cnt[2] = {0, 0};
    for (auto it : a) cnt[it & 1]++;
    vector<int> A, B;
    if (cnt[0] >= 3) {
      cnt[0] = 0;
      for (auto it : a)
        if (it % 2 == 0) {
          cnt[0]++;
          if (cnt[0] <= 3) {
            A.push_back(it);
          } else {
            B.push_back(it);
          }
        } else
          B.push_back(it);
    } else {
      if (cnt[0] >= 1 && cnt[1] >= 2) {
        cnt[0] = 0;
        cnt[1] = 0;
        for (auto it : a) {
          if (it % 2 == 0) {
            cnt[0]++;
            if (cnt[0] <= 1) {
              A.push_back(it);
            } else {
              B.push_back(it);
            }
          } else {
            cnt[1]++;
            if (cnt[1] <= 2) {
              A.push_back(it);
            } else {
              B.push_back(it);
            }
          }
        }
      } else {
        noans();
      }
    }
    ans[1] = (A[2] - A[1] + A[0]) / 2;
    ans[2] = A[0] - ans[1];
    ans[3] = A[1] - ans[2];
    for (int i = 3; i <= n - 1; ++i) {
      ans[i + 1] = B[i - 3] - ans[1];
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
