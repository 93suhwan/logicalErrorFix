/*
Problem link:

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
  Simple



Notes:



*/

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,        // key
             null_type,  // value
             less<int>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;
/*
  How to use ordered_set:
  ordered_set X;
  X.insert(1);
  X.erase(1);
  X.find_by_order(1); // This gives an iterator.
  X.order_of_key(-5); // Lower bound, 0 based position.
 */

//#define DB
#ifdef DB
#define el cerr << "\n";
#define db(...) cerr << " [" << #__VA_ARGS__ << " : " << __VA_ARGS__ << "] ";
#else
#define el
#define db(...)
#endif // DB

#define double long double
#define ll long long
#define ii pair<int, int>
#define i3 tuple<int, int, int>

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
int n;
string s;
void solve() {
    cin >> n >> s;
    for (int i = n / 2; i < n; ++i) {
        if (s[i] == '0') {
            cout << "1 " << i << " 1 " << i + 1 << "\n";
            return;
        }
    }
    cout 
    << ((n + 1) / 2) << " " 
    << n << " " 
    << ((n - 1) / 2) << " " 
    << (s[((n - 1) / 2)] == '0' ? n : n - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    // cout << t;
    // assert(divMod(1, 2) == (MOD + 1) / 2);
    for (int i = 1; i <= t; ++i) {
        solve();
        // cout << solve() <<< "\n";
        // cout << "Case #" << i << ": " << solve() << "\n";
        
    }
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
