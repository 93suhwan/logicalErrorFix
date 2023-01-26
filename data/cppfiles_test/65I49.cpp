#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T neg = 0;
  while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (neg) x = (~x) + 1;
}
template <typename T>
void recursive_print(T x) {
  return (!x) ? void() : (recursive_print(x / 10), putc(x % 10 ^ 48), void());
}
template <typename T>
void print(T x) {
  (!x) && (putc('0'), 0);
  (x < 0) && (putc('-'), x = ~x + 1);
  recursive_print(x);
}
template <typename T>
void print(T x, char c) {
  print(x);
  putc(c);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 2e5;
int n, a[MAXN + 5];
char s[MAXN + 5];
long long lft, rit;
int main() {
  scanf("%d", &n);
  multiset<long long> st;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), st.insert(a[i]);
  scanf("%s", s + 1);
  vector<pair<int, int> > res;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L') {
      if (lft > rit) {
        multiset<long long>::iterator it = st.lower_bound(lft - rit);
        if (it != st.begin()) {
          --it;
          int val = *it;
          rit += val;
          res.push_back(make_pair(val, 1));
          st.erase(st.find(val));
        } else {
          int val = (*st.begin());
          lft += val;
          res.push_back(make_pair(val, 0));
          st.erase(st.find(val));
        }
      } else {
        multiset<long long>::iterator it = st.upper_bound(lft - rit);
        if (it == st.end()) return puts("-1"), 0;
        int val = (*it);
        lft += val;
        res.push_back(make_pair(val, 0));
        st.erase(st.find(val));
      }
    } else {
      if (rit > lft) {
        multiset<long long>::iterator it = st.lower_bound(rit - lft);
        if (it != st.begin()) {
          --it;
          int val = *it;
          lft += val;
          res.push_back(make_pair(val, 0));
          st.erase(st.find(val));
        } else {
          int val = (*st.begin());
          rit += val;
          res.push_back(make_pair(val, 1));
          st.erase(st.find(val));
        }
      } else {
        multiset<long long>::iterator it = st.upper_bound(rit - lft);
        if (it == st.end()) return puts("-1"), 0;
        int val = (*it);
        rit += val;
        res.push_back(make_pair(val, 1));
        st.erase(st.find(val));
      }
    }
  }
  for (int i = 0; i < res.size(); i++) {
    printf("%d ", res[i].first);
    if (res[i].second)
      printf("R\n");
    else
      printf("L\n");
  }
  return 0;
}
