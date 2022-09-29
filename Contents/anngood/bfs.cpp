#include<bits/stdc++.h>
using namespace std;
int a[500][500]={0};
int used[500][500] = {0};

int moveI[4]={-1, 0, 1, 0};
int moveJ[4]={0, 1, 0, -1};
struct node{
    int I, J, now;
    node(int I, int J, int now):I(I), J(J), now(now){};
};
int main(){
    int N;
    cin>>N;
    while(N--){
        memset(a, 0, sizeof(a));
        memset(used, 0, sizeof(used));
        int n, m, sn, sm, en, em;
        cin>>n>>m>>sn>>sm>>en>>em;

        for(int i=0; i < n+2; i++){ //建牆壁 若不用可跳過 
            a[i][0] = 1;
            a[i][m+1] = 1;
        } 
        for(int i=0; i < m+2; i++){
            a[0][i] = 1;
            a[n+1][i] = 1;
        }

        for(int i=1;i<=n;i++){ // 用char輸入 因為輸入無空格 
            for(int j=1;j<=m;j++){
                char t;
                cin >> t;
                a[i][j] = t-'0';
            }
        }
        
        queue<node> q;
        q.push(node(sn, sm, 1));  //定義起點為1步 
        int flag = 0;
        while(!q.empty()){
            node F=q.front(); //取最優先那個
            q.pop();   //取完丟掉 
            if(F.I == en && F.J == em){
                flag = 1;
                cout << F.now << '\n';
                break;
            }
            for(int i = 0; i < 4; i++){
                int nowi = F.I+moveI[i];   // 找I上下左右 
                int nowj = F.J+moveJ[i];   // 找J上下左右 
                if(a[nowi][nowj] == 0 && used[nowi][nowj] == 0){    // 如果可走且沒走過 
                    used[nowi][nowj]=1;
                    q.push(node(nowi, nowj, F.now+1));  // 放到queue裡面(最不優先) 
                }
            }
        }

        if(!flag) cout << 0 << '\n';    //如果找不到路輸出0;
    }
    return 0;
}