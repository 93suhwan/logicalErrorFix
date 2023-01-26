#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         long long int a[n];
         for(int i=0;i<n;i++){
             cin>>a[i];
         } 
         long long int ecd=a[0];
         long long int ocd=a[1];
         for(int i=0;i<n;i=i+2){
             ecd=__gcd(ecd,a[i]);
         }
         for(int i=1;i<n;i=i+2){
             ocd=__gcd(ocd,a[i]);
         } 
         int f=0;
        for(int i=1;i<n;i=i+2){
            if(a[i]%ecd==0 && ecd!=1){
                f=1;
                break;
            }
        } int g=0;
        for(int i=0;i<n;i=i+2){
            if(a[i]%ocd==0 && ocd!=1){
                g=1;
                break;
            }
        }
        if(f==1 && g==1){
            cout<<"0"<<"\n";
        } else if(ocd==1 && ecd==1){
            cout<<"0"<<"\n";
        } else {
            if(ocd > ecd && g==0){
                cout<<ocd<<"\n";
            } else if(ecd>ocd && f==0){
                cout<<ecd<<"\n";
            } else cout<<"0"<<"\n";
        }
     }

     
}
