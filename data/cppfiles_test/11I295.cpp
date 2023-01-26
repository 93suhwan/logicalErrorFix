#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define m7 1000000007
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<b; i++)
#define For(n) for(int i=0; i<n; i++)

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool pof2(int n){	//Check whether a number is a power of 2.
    if(n & n-1)
        return false;
    return true;
}

vector<string> w;

bool cmp(pi a, pi b){
    if(a.ff == b.ff)
        return w[a.ss].size() < w[b.ss].size();
    return a.ff > b.ff;
}

int main() {

    fastIO();

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        w.resize(n);
        For(n)  
            cin >> w[i];

        char c[5] = {'a','b','c','d','e'};
        int max_cnt = 0;
        for(int i=0; i<5; i++){
        
            char cc = c[i];
            pi ccnt[n] = {};
            rep(j,0,n){
                int cnt = 0;
                rep(k,0,w[j].size())
                    if(w[j][k] == c[i])
                        cnt++; 
                ccnt[j].ff = cnt;
                ccnt[j].ss = j;
            }
            sort(ccnt, ccnt+n, cmp);
    
            int cnt = 0;
            int tc = 0;
            int sz = 0;
            rep(j,0,n){
                tc += ccnt[j].ff;
                sz += w[ccnt[j].ss].size();
                if(2*tc - sz > 0)
                    cnt++;
                else{
                    tc -= ccnt[j].ff;
                    sz -= w[ccnt[j].ss].size();
                }
            }
            max_cnt = max(max_cnt, cnt);
        }
        cout << max_cnt << endl;
    }
}