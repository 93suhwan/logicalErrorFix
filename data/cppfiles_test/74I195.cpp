#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(a) cerr<<#a<<" --> "<<(a)<<endl;
#define int long long
#define pii make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1LL<<pos); }
int turnon(int pos, int mask) { return mask|(1LL<<pos); }
const int N=1005;
//int ar[N];

main()
{
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        set<int>st;
        cin>>a>>b;
        int tot=a+b;
        int serve=ceil(tot, 2);//alice serve
        int bs=tot-serve;
        for(int i=serve; i>=0; i--) {
            if(a<serve) {
                //debug(i-a);
                int baki=serve-i;
                st.insert(i-a+baki);
            }
            else {
                int baki=a-i;
                if(baki>bs) break;
                int bakis=serve-i;
                //debug(baki+bakis);
                st.insert(baki+bakis);
            }
        }
        serve=tot/2;
        bs=tot-serve;
        for(int i=serve; i>=0; i--) {
            if(a<serve) {
                //debug(i-a);
                int baki=serve-i;
                st.insert(i-a+baki);
            }
            else {
                int baki=a-i;
                if(baki>bs) break;
                int bakis=serve-i;
                //debug(baki+bakis);
                st.insert(baki+bakis);
            }
        }
        cout<<st.size()<<endl;
        for(auto i:st) cout<<i<<" ";
        cout<<endl;
    }
}