#include <bits/stdc++.h>
using namespace std;
inline void RI(long long &i) { scanf("%lld", &(i)); }
inline void RVI(vector<long long> &v) {
  for (long long i = 0; i < long long((v).size()); ++i) {
    RI(v[i]);
  }
}
inline void RVVI(vector<vector<long long> > &vv) {
  for (long long i = 0; i < long long((vv).size()); ++i) {
    RVI(vv[i]);
  }
}
inline void WI(const long long &i) { printf("%lld\n", i); }
inline void WVI(const vector<long long> &v, char sep = ' ') {
  for (long long i = 0; i < long long((v).size()); ++i) {
    if (i != 0) {
      printf("%c", sep);
    }
    printf("%lld", v[i]);
  }
  printf("\n");
}
inline void WS(const string &s) { printf("%s\n", s.c_str()); }
inline void WB(bool b, const string &yes, const string &no) {
  if (b) {
    WS(yes);
  } else {
    WS(no);
  }
}
inline void YESNO(bool b) { WB(b, "YES", "NO"); }
inline void RS(string &s) {
  static char buf[1000000];
  scanf("%s", buf);
  s = buf;
}
template <typename T>
inline bool IN(T &S, const typename T::key_type &key) {
  return S.find(key) != S.end();
}
int main(int argc, char *argv[]) {
  long long i, j, k;
  long long t, T;
  RI(T);
  for (t = (0); t < (T); ++t) {
    long long n;
    RI(n);
    vector<long long> a(n);
    RVI(a);
    long long m = max_element((a).begin(), (a).end()) - a.begin();
    long long ans = -1;
    if (m != 0) {
      ans = max(ans, a[m] * a[m - 1]);
    }
    if (m != n - 1) {
      ans = max(ans, a[m] * a[m + 1]);
    }
    WI(ans);
  }
  return 0;
}
