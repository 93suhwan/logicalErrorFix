#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long n, m, q;
multiset<pair<long long, pair<long long, long long> > > med[100010], alled;
multiset<pair<long long, long long> > vt[100010];
multiset<long long> allv;
long long calc3(long long x) {
  long long res = 0;
  multiset<pair<long long, pair<long long, long long> > >::iterator it =
      med[x].begin();
  res += (*it).first;
  it++;
  res += (*it).first;
  it++;
  res += (*it).first;
  return res;
}
long long calc1() {
  if (allv.empty()) {
    return 1000000000000000000;
  }
  return (*allv.begin());
}
long long calc2() {
  long long ret, x, y, cnt;
  bool fd = false;
  set<long long> vis;
  ret = (*alled.begin()).first;
  x = (*alled.begin()).second.first;
  y = (*alled.begin()).second.second;
  cnt = 0;
  for (multiset<pair<long long, pair<long long, long long> > >::iterator it =
           alled.begin();
       it != alled.end(); it++, cnt++) {
    if ((*it).second.first == x || (*it).second.first == y ||
        (*it).second.second == x || (*it).second.second == y) {
      continue;
    }
    if (cnt > 10) {
      break;
    }
    fd = true;
    ret += (*it).first;
    break;
  }
  if (!fd) {
    ret = 1000000000000000000;
  }
  cnt = 0;
  for (multiset<pair<long long, pair<long long, long long> > >::iterator it =
           med[x].begin();
       it != med[x].end(); it++, cnt++) {
    if ((*it).second.first == y || (*it).second.second == y) {
      continue;
    }
    if (cnt > 5) {
      break;
    }
    for (multiset<pair<long long, pair<long long, long long> > >::iterator it2 =
             med[y].begin();
         it2 != med[y].end(); it2++) {
      if ((*it2).second.first == x || (*it2).second.second == x ||
          (*it2).second.first == (*it).second.first ||
          (*it2).second.second == (*it).second.first ||
          (*it2).second.first == (*it).second.second ||
          (*it2).second.second == (*it).second.second) {
        continue;
      }
      ret = min(ret, (*it).first + (*it2).first);
      break;
    }
  }
  return ret;
}
int main() {
  long long i, x, y, w, tp;
  scanf("%lld%lld", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%lld%lld%lld", &x, &y, &w);
    x--;
    y--;
    vt[x].insert(make_pair(y, w));
    vt[y].insert(make_pair(x, w));
    alled.insert(make_pair(w, make_pair(x, y)));
    if (med[x].size() >= 3) {
      allv.erase(allv.lower_bound(calc3(x)));
    }
    med[x].insert(make_pair(w, make_pair(x, y)));
    if (med[x].size() >= 3) {
      allv.insert(calc3(x));
    }
    if (med[y].size() >= 3) {
      allv.erase(allv.lower_bound(calc3(y)));
    }
    med[y].insert(make_pair(w, make_pair(y, x)));
    if (med[y].size() >= 3) {
      allv.insert(calc3(y));
    }
  }
  scanf("%lld", &q);
  printf("%lld\n", min(calc1(), calc2()));
  while (q--) {
    scanf("%lld", &tp);
    if (tp == 0) {
      scanf("%lld%lld", &x, &y);
      x--;
      y--;
      multiset<pair<long long, long long> >::iterator it =
          vt[x].lower_bound(make_pair(y, 0));
      w = (*it).second;
      vt[x].erase(it);
      vt[y].erase(vt[y].lower_bound(make_pair(x, w)));
      if (alled.find(make_pair(w, make_pair(x, y))) != alled.end()) {
        alled.erase(alled.find(make_pair(w, make_pair(x, y))));
      } else {
        alled.erase(alled.find(make_pair(w, make_pair(y, x))));
      }
      if (med[x].size() >= 3) {
        allv.erase(allv.lower_bound(calc3(x)));
      }
      med[x].erase(med[x].lower_bound(make_pair(w, make_pair(x, y))));
      if (med[x].size() >= 3) {
        allv.insert(calc3(x));
      }
      if (med[y].size() >= 3) {
        allv.erase(allv.lower_bound(calc3(y)));
      }
      med[y].erase(med[y].lower_bound(make_pair(w, make_pair(y, x))));
      if (med[y].size() >= 3) {
        allv.insert(calc3(y));
      }
    } else {
      scanf("%lld%lld%lld", &x, &y, &w);
      x--;
      y--;
      vt[x].insert(make_pair(y, w));
      vt[y].insert(make_pair(x, w));
      alled.insert(make_pair(w, make_pair(x, y)));
      if (med[x].size() >= 3) {
        allv.erase(allv.lower_bound(calc3(x)));
      }
      med[x].insert(make_pair(w, make_pair(x, y)));
      if (med[x].size() >= 3) {
        allv.insert(calc3(x));
      }
      if (med[y].size() >= 3) {
        allv.erase(allv.lower_bound(calc3(y)));
      }
      med[y].insert(make_pair(w, make_pair(y, x)));
      if (med[y].size() >= 3) {
        allv.insert(calc3(y));
      }
    }
    printf("%lld\n", min(calc1(), calc2()));
  }
  return 0;
}
