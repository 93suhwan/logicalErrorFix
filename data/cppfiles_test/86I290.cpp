#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

int mex(set<int>& st){
    for(int i = 0; i <= 2; i++){
        if(!st.count(i)){
            return i;
        }
    }
    assert(false);
}
void solve(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    set<int> st;
    for(int i = 0; i < n; i++){
        st.clear();
        st.insert(s[i]-'0');
        st.insert(t[i]-'0');
        int premex = mex(st);
        if(premex == 2){
            ans += 2;
            continue;
        }
        if(premex == 1){
            if(i == n-1){
                ans += 1;
                break;
            }
            st.insert(s[i+1]-'0');
            st.insert(t[i+1]-'0');
            int nxtmex = mex(st);
            if(nxtmex == 1){
                ans += 1;
            }else{ // == 2
                ans += 2;
                i++;
            }
            continue;
        }
        i++;
        while(i < n){
            st.insert(s[i]-'0');
            st.insert(t[i]-'0');
            if(mex(st) == 2){
                break;
            }
            i++;
        }
        ans += mex(st);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
}
