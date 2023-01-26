#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x)
      return x < p.x;
    else
      return y < p.y;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int tl, tr;
  vector<int> l(n, -1), r(n, -1), p(n, -1);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &tl, &tr);
    l[i] = tl - 1;
    r[i] = tr - 1;
    if (tl > 0) {
      p[tl - 1] = i;
    }
    if (tr > 0) {
      p[tr - 1] = i;
    }
  }
  int ancDist = sqrt(n);
  vector<int> anc(n, -1);
  vector<bool> ancR(n);
  vector<int> toVisit;
  vector<int> chInd;
  vector<int> label;
  vector<int> ancRct;
  toVisit.push_back(0);
  chInd.push_back(0);
  ancRct.push_back(0);
  while (toVisit.size() > 0) {
    int ind = toVisit.back();
    if (chInd.back() == 0) {
      chInd[chInd.size() - 1]++;
      if (l[ind] >= 0) {
        toVisit.push_back(l[ind]);
        chInd.push_back(0);
        ancRct.push_back(max(0, ancRct.back() - 1));
      }
    } else if (chInd.back() == 1) {
      if (toVisit.size() > ancDist) {
        anc[ind] = toVisit[toVisit.size() - 1 - ancDist];
      }
      ancR[ind] = ancRct.back() == 0;
      label.push_back(ind);
      chInd[chInd.size() - 1]++;
      if (r[ind] >= 0) {
        toVisit.push_back(r[ind]);
        chInd.push_back(0);
        ancRct.push_back(ancDist);
      }
    } else {
      toVisit.pop_back();
      chInd.pop_back();
      ancRct.pop_back();
    }
  }
  char suf = 'a' - 1;
  vector<bool> dup(n);
  vector<bool> duped(n);
  for (int i = n - 1; i >= 0; --i) {
    if (s[label[i]] < suf) {
      dup[label[i]] = true;
    }
    if (i > 0 && s[label[i]] != s[label[i - 1]]) {
      suf = s[label[i]];
    }
  }
  for (int i = 0; i < n; ++i)
    if (k > 0) {
      if (dup[label[i]] && !duped[label[i]]) {
        int ct = 1;
        int ind = label[i];
        bool pos = true;
        while (pos && anc[ind] >= 0 && !duped[anc[ind]]) {
          if (ct + ancDist <= k && ancR[ind]) {
            ct += ancDist;
            ind = anc[ind];
          } else {
            pos = false;
          }
        }
        while (pos && p[ind] >= 0 && !duped[p[ind]]) {
          if (ct + 1 <= k && l[p[ind]] == ind) {
            ct += 1;
            ind = p[ind];
          } else {
            pos = false;
          }
        }
        if (pos) {
          k -= ct;
          ind = label[i];
          do {
            duped[ind] = true;
            ind = p[ind];
          } while (ind >= 0 && !duped[ind]);
        }
      }
    }
  for (int i = 0; i < n; ++i) {
    cout << s[label[i]];
    if (duped[label[i]]) {
      cout << s[label[i]];
    }
  }
  cout << endl;
  return 0;
}
