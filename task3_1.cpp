#include <bits/stdc++.h>

using namespace std;

int main(){
    int M,N,m,n;
    int sub,flag;
    cout<<"Dimension of Main matrix (M,N) =";
    cin>>M>>N;
    cout<<"Dimension of sub matrix (m,n) =";
    cin>>m>>n;

    int mainMat[M][N];
    int subMat[m][n];

    cout<<"Enter value for main matrix:"<<endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<"["<<i<<"]["<<j<<"] =";cin>>mainMat[i][j];
        }
    }
    cout<<"Enter value for sub matrix:"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"["<<i<<"]["<<j<<"] =";cin>>subMat[i][j];
        }
    }

    for(int i=0;i<M-m+1;i++){
        for(int j=0;j<N-n+1;j++){
            flag=0;
            for(int k=0;k<m;k++){
                for(int l=0;l<n;l++){
                    if(mainMat[i+k][j+l]!=subMat[k][l]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag == 0){
                sub=1;
                break;
            }
        }
        if(sub==1)break;
    }
    if(sub == 1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

}