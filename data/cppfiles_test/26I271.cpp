#include<bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
// #define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rep1(i,a,b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ss second
#define mod 1e+7
#define i_can_do_it ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);

int gcd(int m, int n) {
    return __gcd(m,n);
}

void solve(){

    string s; cin >> s;
    int n = 10;
    string s1,s2;
    rep(i,0,n){
        if((i+1)%2 != 0) s1 += s[i];
        else s2 += s[i];
    }
    // cout << s1 << " " << s2 << endl;
    int p1 = 0, p2 = 0;
    int ans = 10;
    int i = 0, j = 0, k = 0;
    while(k < 10){
        if((k+1)%2 == 0){
            if(s2[j] != '0') p2++;
            if(p1 + (4-i) < p2){
                ans = min(ans,i+j+2);
            }
            j++;
        }else if((k+1)%2 != 0){
            if(s1[i] == '1')p1++;
            if(p2 + (4-j) < p1) ans = min(ans,i+j+2);
            i++;
        }
        k++;
    }
    i = 0, j = 0, k = 0;
    p1 = 0, p2 = 0;
    while(k < 10){
        if((k+1)%2 == 0){
            if(s2[j] == '1') p2++;
            if(p1 + (4-i) < p2){
                ans = min(ans,i+j+2);
            }
            j++;
        }else if((k+1)%2 != 0){
            if(s1[i] != '0')p1++;
            if(p2 + (4-j) < p1) ans = min(ans,i+j+2);
            i++;
        }
        k++;
    }

    cout << ans << endl;
    
}


int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    i_can_do_it
    int t = 1;
    cin>>t;
    while (t--) {
        clock_t z = clock();
        {
            solve();
            //IGNORE
        #ifndef ONLINE_JUDGE
        cout << "---------------------------------------" << endl;
        #endif
        // IGNORE
        }
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }

    return 0;
}