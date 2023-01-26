#include<bits\stdc++.h>
using namespace std;
#define lli long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;

        lli ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='0' && s2[i]=='1') ans++;
        }


        lli a1=0;
        for(int i=1;i<n;i++){
            if(s1[i]=='1' && s2[i]=='1'){
                if(s1[i-1]=='1') a1++;
                else if(i!=n-1 && s1[i+1]=='1') a1++; 
            }
        }

        lli a2=0;
        for(int i=0;i<n-1;i++){
            if(s1[i]=='1' && s2[i]=='1'){
                if(s1[i+1]=='1') a2++; 
                else if(i!=0 && s1[i-1]=='1') a2++;
            }
        }

        ans+=max(a1,a2);
        cout<<ans<<"\n";
    }
}