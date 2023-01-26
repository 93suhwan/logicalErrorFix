#include <bits/stdc++.h>
using namespace std;
constexpr int MaxLen = 200000 + 5, Bit = 18, Null = 0;
constexpr long long Infinity = (1LL << 60) - 1;
struct SparseTable_List {
  int Log2[MaxLen];
  long long Min[Bit + 1][MaxLen], Max[Bit + 1][MaxLen];
  inline void Initalize(const int n) {
    Log2[0] = (-1);
    for (register int i = (1); i <= (n); ++i) Log2[i] = (Log2[i >> 1] + 1);
    for (register int lv = (1); lv <= (Bit); ++lv)
      for (register int i = (1); i <= (n - (1 << lv) + 1); ++i) {
        Min[lv][i] = min(Min[lv - 1][i], Min[lv - 1][i + (1 << (lv - 1))]);
        Max[lv][i] = max(Max[lv - 1][i], Max[lv - 1][i + (1 << (lv - 1))]);
      }
  }
  inline long long Query_Min(const int lef, const int rig) {
    const int lv = Log2[rig - lef + 1];
    return min(Min[lv][lef], Min[lv][rig - (1 << lv) + 1]);
  }
  inline long long Query_Max(const int lef, const int rig) {
    const int lv = Log2[rig - lef + 1];
    return max(Max[lv][lef], Max[lv][rig - (1 << lv) + 1]);
  }
};
SparseTable_List St;
long long a[MaxLen], b[MaxLen];
long long A[MaxLen], B[MaxLen];
int idx[MaxLen << 1];
struct Compare {
  inline bool operator()(const int u, const int v) {
    const long long tag_u = ((u >= 0) ? (a[u] + 1) : B[-u]);
    const long long tag_v = ((v >= 0) ? (a[v] + 1) : B[-v]);
    return (tag_u < tag_v);
  }
};
std::mt19937 Rand(Null);
struct Vertex {
  long long val;
  unsigned pri;
  int siz;
  int lch, rch;
};
Vertex vt[MaxLen << 3];
int Overall_Tot;
inline int Create_Vertex(const long long val) {
  const int idx = (++Overall_Tot);
  vt[idx].val = val;
  vt[idx].pri = Rand();
  vt[idx].siz = 1;
  return idx;
}
inline int push_up(const int idx) {
  vt[idx].siz = (vt[vt[idx].lch].siz + vt[vt[idx].rch].siz) + 1;
  return idx;
}
inline int Merge(const int tu, const int tv) {
  if (!tu) return tv;
  if (!tv) return tu;
  if (vt[tu].pri <= vt[tv].pri) {
    vt[tu].rch = Merge(vt[tu].rch, tv);
    return push_up(tu);
  } else {
    vt[tv].lch = Merge(tu, vt[tv].lch);
    return push_up(tv);
  }
}
inline void Split(const int idx, const long long val, int& tu, int& tv) {
  if (!idx) {
    tu = tv = Null;
    return;
  }
  if (vt[idx].val <= val)
    tu = idx, Split(vt[idx].rch, val, vt[idx].rch, tv);
  else
    tv = idx, Split(vt[idx].lch, val, tu, vt[idx].lch);
  push_up(idx);
}
inline void Insert(int& Root, const long long val) {
  int tx, ty;
  Split(Root, val, tx, ty);
  Root = Merge(Merge(tx, Create_Vertex(val)), ty);
}
inline int Query(int& Root, const long long stt, const long long ter) {
  int tx, ty, tz, temp;
  Split(Root, ter, tx, tz), Split(tx, stt, tx, ty);
  temp = vt[ty].siz, Root = Merge(Merge(tx, ty), tz);
  return temp;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  long long k;
  cin >> n >> m >> k, k = ((k + 1) << 40) - 1;
  for (register int i = (1); i <= (n); ++i) {
    cin >> a[i], a[i] = (a[i] << 40) | ((long long)i << 20),
                 idx[++idx[0]] = (+i);
    St.Min[0][i] = a[i], St.Max[0][i] = a[i], A[i] = (+Infinity);
  }
  St.Initalize(n);
  for (register int i = (1); i <= (n); ++i) {
    int beg, end, mid;
    if ((i != 1) && St.Query_Min(1, i - 1) <= a[i]) {
      beg = 1, end = i;
      while (beg < end) {
        mid = (beg + end) >> 1;
        if (St.Query_Min(mid, i) == a[i])
          end = mid;
        else
          beg = mid + 1;
      }
      if (beg == i)
        A[i] = (-(Infinity << 1));
      else
        A[i] = min(A[i], St.Query_Max(beg, i - 1));
    }
    if ((i != n) && St.Query_Min(i + 1, n) <= a[i]) {
      beg = i, end = n;
      while (beg < end) {
        mid = (beg + end + 1) >> 1;
        if (St.Query_Min(i, mid) == a[i])
          beg = mid;
        else
          end = mid - 1;
      }
      if (beg == i)
        A[i] = (-(Infinity << 1));
      else
        A[i] = min(A[i], St.Query_Max(i + 1, beg));
    }
  }
  for (register int i = (1); i <= (n); ++i)
    a[i] = (k - a[i]), A[i] = (k - A[i]);
  for (register int i = (1); i <= (m); ++i) {
    cin >> b[i], b[i] = (b[i] << 40) | i, idx[++idx[0]] = (-i);
    St.Min[0][i] = b[i], St.Max[0][i] = b[i], B[i] = (+Infinity);
  }
  St.Initalize(m);
  for (register int i = (1); i <= (m); ++i) {
    int beg, end, mid;
    if ((i != 1) && St.Query_Min(1, i - 1) <= b[i]) {
      beg = 1, end = i;
      while (beg < end) {
        mid = (beg + end) >> 1;
        if (St.Query_Min(mid, i) == b[i])
          end = mid;
        else
          beg = mid + 1;
      }
      if (beg == i)
        B[i] = (-(Infinity << 1));
      else
        B[i] = min(B[i], St.Query_Max(beg, i - 1));
    }
    if ((i != m) && St.Query_Min(i + 1, m) <= b[i]) {
      beg = i, end = m;
      while (beg < end) {
        mid = (beg + end + 1) >> 1;
        if (St.Query_Min(i, mid) == b[i])
          beg = mid;
        else
          end = mid - 1;
      }
      if (beg == i)
        B[i] = (-(Infinity << 1));
      else
        B[i] = min(B[i], St.Query_Max(i + 1, beg));
    }
  }
  sort(idx + 1, idx + idx[0] + 1, Compare());
  long long Answer = 0;
  int Root = 0;
  for (register int i = (idx[0]); i >= (1); --i) {
    if (idx[i] >= 0) {
      const int u = (+idx[i]);
      Answer += Query(Root, A[u], a[u]);
    } else {
      const int u = (-idx[i]);
      Insert(Root, b[u]);
    }
  }
  cout << Answer << endl;
  return 0;
}
