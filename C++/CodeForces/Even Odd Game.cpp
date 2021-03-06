#include<bits/stdc++.h>
using namespace std;
//#pragma gcc optimize("O3")
//#pragma gcc optimize("unroll-loops")
#ifdef EVAH
    #define _WIN32_WINNT 0x0500
    //#include<windows.h>
#endif
#define openFile(n) ShellExecute(nullptr,"open",n,nullptr,nullptr,SW_SHOWNORMAL);
#define closeP(n) system((string("taskkill /im ")+n+" /f").c_str());
#define closeConsole PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
#define opf "output.txt"
#define ipf "input.txt"
#define mem(n,x) memset(n,x,sizeof(n));
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define pb push_back
#define PII pair<int,int>
#define For(x,n) for(int i=x; i<n; i++)
#define stv v+2*(mid-tl+1)
#define LL long long int
#define N 100000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef EVAH
        //freopen(ipf,"r",stdin);
        //openFile(ipf);
        //closeConsole;
        //freopen(opf,"w",stdout);
    #endif

    int t,n,temp;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        LL alice=0,bob=0;
        vector<int> odd,even;
        For(0,n) {
            cin >> temp;
            if(temp&1) odd.pb(temp);
            else even.pb(temp);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        For(0,n) {
            if(i%2==0) {
                if(odd.size()>0 && even.size()>0) {
                    if(odd[odd.size()-1] > even[even.size()-1]) {
                        odd.pop_back();
                    } else {
                        alice += even[even.size()-1];
                        even.pop_back();
                    }
                } else if(odd.size()>0) {
                    odd.pop_back();
                } else {
                    alice += even[even.size()-1];
                    even.pop_back();
                }
            } else {
                if(odd.size()>0 && even.size()>0) {
                    if(odd[odd.size()-1] > even[even.size()-1]) {
                        bob += odd[odd.size()-1];
                        odd.pop_back();
                    } else {
                        even.pop_back();
                    }
                } else if(odd.size()>0) {
                    bob += odd[odd.size()-1];
                    odd.pop_back();
                } else {
                    even.pop_back();
                }
            }
            //cout << "bob = " << bob << " alice = " << alice << "\n";
        }
        //cout << "End result bob = " << bob << " alice = " << alice << "\n";
        if(bob==alice) {
            cout << "Tie\n";
        } else if(bob>alice) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    #ifdef EVAH
        //openFile(opf);
        //Sleep(3000);
        //closeP("notepad.exe");
        //closeConsole;
    #endif
}
