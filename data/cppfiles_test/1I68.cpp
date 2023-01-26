/*
Problem link:

1. Understand
  Input:
  Output:
  Conditions:
    Separate various parts of the condition:

2. Plan
  Connection between data and unknown:
    Subproblem / Simpler problem:
  Related problem:
  Restate the problem:
  Restate again:
  Drop part of the condition:
  Use all data?
  Use the whole condition?

Problems tags:
  Case Analysis
  Classic
    DP
  Math
  Combinatorics
  Data Structure
  Graph
  Tree
  Flows
  Greedy (or not?)
  Implementation
    Date time
    Ordered set
    Fast io
  String
  Visualization
  Simple



Notes:



*/

#include<bits/stdc++.h>
using namespace std;

// //#define DB
// #ifdef DB
// #define el cerr << "\n";
// #define db(...) cerr << " [" << #__VA_ARGS__ << " : " << __VA_ARGS__ << "] ";
// #else
// #define el
// #define db(...)
// #endif // DB

// DEBUG
#define format(x) << #x << ": " << (x)
#define com << ", "
#define ndl << "\n"
#define debug1(x) cerr format(x) ndl;
#define debug2(x, y) cerr format(x) com format(y) ndl;
#define debug3(x, y, z) cerr format(x) com format(y) com format(z) ndl;
#define debug4(x, y, z, w) cerr format(x) com format(y) com format(z) com format(w) ndl;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T> 
void debug_out(H h, T... t) { cerr << " " << (h); debug_out(t...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define el cerr << "\n";
//

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
// define double long double will mess up the debug code
// #define double long double
template <typename T, typename U>
pair<T, U> operator + (const pair<T, U> &L, const pair<T, U> &R) {
  return {L.first + R.first, L.second + R.second};
}
template <typename T, typename U>
pair<T, U> operator - (const pair<T, U> &L, const pair<T, U> &R) {
  return {L.first - R.first, L.second - R.second};
}


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<
	int, // key // if multiset, use pair<T, int> as the key where the int is time when added
	null_type, // value
	less<int>, // comparator (less --> normal set)
	rb_tree_tag,
	tree_order_statistics_node_update
> ordered_set;
/*
  How to use ordered_set:
ordered_set os;
os.insert(x);
os.erase(x);
os.find_by_order(k)  returns iterator to kth element starting from 0;
os.order_of_key(x) returns count of elements strictly smaller than x; (Lower bound, 0 based position)
  
  erase, insert same as normal set
*/

//const int MOD = 998244353;
const int MOD = 1e9 + 7;

// Assume: MOD is coprime with a
ll invMod(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (MOD + u) % MOD;
}

ll mul(ll a, ll b) {
    // return ((a % MOD) * (b % MOD)) % MOD;  // Safer but slower
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    // return ((a % MOD) + (b % MOD)) % MOD;  // Safer but slower
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    // return ((a - b) % MOD + MOD) % MOD;  // Safer but slower
    return (a - b + MOD) % MOD;
}

ll divMod(ll a, ll b) {
    return mul(a, invMod(b));
}

ll powMod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

const int N = 1e6 + 5;

ll fact[N];
ll invf[N];
void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invf[i] = mul(invf[i - 1], invMod(i));
    }
}
ll C(int k, int n) {
    return mul(fact[n], mul(invf[k], invf[n - k]));
}

void solve() {

}

/**
 * Frequent bugs:
 *   - Overflows: Are limits on static arrays enough?? Double-check!!
 *      Input is N but we need N * 2? N * 4 (segment tree)?
 *      Is N upto 10^7?
 *   - 1-off errors:
 *      Is indexing 0-based or 1-based?
 *   - Corner cases:
 *      N == 0?
 *      N == 1?
 *      Impossible?
 *   - Output format:
 *      Special characters? Long 'minus' signs? Copy-and-paste from statement to be sure
 *      New-lines?
 *   - Casting problems:
 *      Function calculates long long but return int --> WA?
 *      Provide long long as argument but the parameter is int --> WA?
 *      Use #define int long long if memory limit is high
 *   - Problem definition: read the statement correctly:
 *      'y' is vowel?
 **/
#define double long double
const double EPS = 1e-9;
const double PI = acos(-1.0L);
bool eq(double a, double b) {
  return abs(a - b) < EPS;
}
bool les(double a, double b) {
  return (b - a) > EPS;
}
struct Pt {
  int x, y;
  double a, d;
};
Pt a[N];
double pyth(double dx, double dy) {
  return sqrt(dx * dx + dy * dy);
}

int n, k;
typedef pair<double, bool> Event;
bool cmp2(const Event &e1, const Event &e2) {
  double a1, a2;
  int t1, t2;
  tie(a1, t1) = e1, tie(a2, t2) = e2;
  if (not eq(a1, a2)) return a1 < a2;
  return t1 < t2;
}
bool ok(double r) {
  double delta; // delta = acos(norm[p] / 2r)
  double L, R; // radial/angle segment
  double dif;
  vector<Event> events;
  for (int i = 0; i < n; ++i) {
    if (les(r, a[i].d)) continue;
    delta = acos(a[i].d / r);
    L = a[i].a - delta;
    R = a[i].a + delta;
    if (les(L, -PI)) {
      events.emplace_back(-PI, 0);
      events.emplace_back(R, 1);
      dif = -PI - L;
      L = PI - dif;
      R = PI;
    }
    if (les(PI, R)) {
      events.emplace_back(L, 0);
      events.emplace_back(PI, 1);
      dif = R - PI;
      R = -PI + dif;
      L = -PI;
    }
    events.emplace_back(L, 0);
    events.emplace_back(R, 1);
  }
  sort(events.begin(), events.end(), cmp2);
  double angle;
  bool type;
  int cnt = 0;
  for (auto &e : events) {
    tie(angle, type) = e;
    if (type == 0) {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt >= k) return true;
  }
  return false;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].x >> a[i].y;
      a[i].a = atan2(a[i].y, a[i].x);
      a[i].d = pyth(a[i].x, a[i].y) / 2;
    }
    double L = 0, R = 1e5, M;
    for (int i = 0; i < 50; ++i) {
      M = (L + R) / 2;
      if (ok(M)) {
        R = M;
      } else {
        L = M;
      }
    }
    cout << setprecision(10) << fixed << L;
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

/*
1. UNDERSTAND THE PROBLEM

 • *First.* You have to _understand_ the problem.

 • What is the unknown? The unknown is ...
 What are the data? The data are ...
 What is the condition? The condition is ...

 • Is it possible to satisfy the condition?
 Is the condition sufficient to determine the unknown? Or is it insufficient? Or redundant? Or contradictory?

 • Draw a figure. Introduce suitable notation.

 Let x be ...

 • Separate the various parts of the condition. Can you write them down?

 The condition can be separated into ... parts: ...



2. DEVISING A PLAN
 • *Second.* Find the connection between the data and the unknown.
 You may be obliged to consider auxiliary problems if an immediate connection cannot be found.
 You should obtain eventually a _plan_ of the solution.

 • Have you seen it before? Or have you seen the same problem in a slightly different form?

 • _Do you know a related problem?_ Do you know a theorem that could be useful?

 • _Look at the unknown!_ Try to think of a familiar problem having the same or a similar unknown.

 • _Here is a problem related to yours and solved before. Could you use it?_
 Could you use its result? Could you use its method?
 Should you _introduce some auxiliary element_ in order to make its use possible?

 • Could you restate the problem? Could you restate it still differently? Go back to definitions.

 The problem can be restated as follows: Given ...

 • If you cannot solve the proposed problem, try to solve first some related problem.
 Could you imagine a more accessible related problem?
 A more general problem? A more special problem? An analogous problem?
 Could you solve a part of the problem?
 Keep only a part of the condition, drop the other part; how far is the unknown then determined, how can it vary?

 Let's see what happens when condition ... is removed: ...

 Could you derive something useful from the data? Could you think of other data appropriate to determine the unknown?
 Could you change the unknown or data, or both if necessary, so that the new unknown and the new data are nearer to each other?

 • Did you use all the data? Did you use the whole condition?
 Have you taken into account all essential notions involved in the problem?




3 3. CARRYING OUT THE PLAN
 • *Third.* Carry out your plan.
 • Carrying out your plan of the solution, check each step.
 Can you see clearly that the step is correct? Can you prove that it is correct?

4. LOOKING BACK
 • *Fourth.* Examine the solution obtained.
 • Can you check the result? Can you check the argument?
 • Can you derive the solution differently? Can you see it at a glance?
 • Can you use the result, or the method, for some other problem?

 */
