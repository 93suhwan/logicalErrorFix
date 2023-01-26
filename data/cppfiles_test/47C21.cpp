#include <bits/stdc++.h>
using namespace std;
std::vector<long long int> v;
long long int n, k;
void pr(long long int a, long long int b, long long int c) {
  if (a == 1) {
    cout << "and"
         << " " << b << " " << c << endl;
  } else
    cout << "or"
         << " " << b << " " << c << endl;
}
void calc(string &as, string &bs, string &cs, long long int anb,
          long long int anc, long long int bnc, long long int aob,
          long long int aoc, long long int boc) {
  if (anb + anc + bnc == 3) {
    as.append("1");
    bs.append("1");
    cs.append("1");
  } else if (anb + anc + bnc == 1) {
    if (anb == 1) {
      as.append("1");
      bs.append("1");
      cs.append("0");
    } else if (anc == 1) {
      as.append("1");
      bs.append("0");
      cs.append("1");
    } else {
      as.append("0");
      bs.append("1");
      cs.append("1");
    }
  } else {
    if (aoc == 0) {
      if (aob == 1) {
        as.append("0");
        bs.append("1");
        cs.append("0");
      } else {
        as.append("0");
        bs.append("0");
        cs.append("0");
      }
    } else if (aob == 0) {
      if (aoc == 1) {
        as.append("0");
        bs.append("0");
        cs.append("1");
      } else {
        as.append("0");
        bs.append("0");
        cs.append("0");
      }
    } else {
      if (aob == 1) {
        as.append("1");
        bs.append("0");
        cs.append("0");
      } else {
        as.append("0");
        bs.append("0");
        cs.append("0");
      }
    }
  }
}
string sss(long long int a) {
  string s = "";
  for (long long int i = 0; i < 33; i++) {
    s.append(to_string(a % 2));
    a /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long int bini(string s) {
  long long int num = 0;
  for (long long int i = 32; i >= 0; i--) {
    long long int a = s[i] - '0';
    num += (long long int(pow(2, 32 - i)) * a);
  }
  return num;
}
void pro(long long int a, long long int b, long long int c) {
  long long int anb, anc, bnc, aob, aoc, boc;
  string sanb, sanc, sbnc, saob, saoc, sboc;
  pr(1, a, b);
  cin >> anb;
  pr(1, a, c);
  cin >> anc;
  pr(1, b, c);
  cin >> bnc;
  pr(0, a, b);
  cin >> aob;
  pr(0, a, c);
  cin >> aoc;
  pr(0, b, c);
  cin >> boc;
  sanb = sss(anb);
  sanc = sss(anc);
  sbnc = sss(bnc);
  saob = sss(aob);
  saoc = sss(aoc);
  sboc = sss(boc);
  string as = "", bs = "", cs = "";
  for (long long int i = 0; i < 33; i++) {
    calc(as, bs, cs, sanb[i] - '0', sanc[i] - '0', sbnc[i] - '0', saob[i] - '0',
         saoc[i] - '0', sboc[i] - '0');
  }
  v.push_back(bini(as));
  v.push_back(bini(bs));
  v.push_back(bini(cs));
}
long long int newnum(long long int a, long long int d) {
  long long int ann;
  pr(1, 1, d);
  cin >> ann;
  long long int orr;
  pr(0, 1, d);
  cin >> orr;
  string s = sss(a);
  string ds = sss(ann);
  string dos = sss(orr);
  string ans = "";
  for (long long int i = 0; i < 33; i++) {
    if (ds[i] - '0' == 1)
      ans.append("1");
    else if ((s[i] - '0') == 1)
      ans.append("0");
    else {
      if (dos[i] - '0' == 0) {
        ans.append("0");
      } else
        ans.append("1");
    }
  }
  return bini(ans);
}
void solve() {
  cin >> n >> k;
  for (long long int i = 0; i < n / 3; i++) {
    pro(3 * i + 1, 3 * i + 2, 3 * i + 3);
  }
  if (n % 3 == 0) {
  } else if (n % 3 == 1) {
    v.push_back(newnum(v[0], n));
  } else {
    v.push_back(newnum(v[0], n - 1));
    v.push_back(newnum(v[0], n));
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
