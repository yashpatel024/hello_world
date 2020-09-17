#include <bits/stdc++.h>

using namespace std;

int main(){
    int M,N,m,n;
    
    cout<<"Dimension of Main matrix (M,N) =";
    cin>>M>>N;
    cout<<"Dimension of sub matrix (m,n) =";
    cin>>m>>n;

    int mainMat[M*N];
    int subMat[m*n];

    int k=0;
    cout<<"Enter value for main matrix:"<<endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<"["<<i<<"]["<<j<<"] =";cin>>mainMat[k++];
        }
    }
    k=0;
    cout<<"Enter value for sub matrix:"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"["<<i<<"]["<<j<<"] =";cin>>subMat[k++];
        }
    }

    int mainSize = M*N;
    int subSize = m*n;
    int flag;

    //Pattern checking
    for(int i=0; i<mainSize-subSize+1; i++){
        if(mainMat[i] == subMat[0]){
            int tempI = i;
            flag=0;
            int spaceCount=0;
            int digCount=0;

            for(int j=0; j<subSize;){
                if(digCount%n == 0 && digCount != 0){
                    if(spaceCount < (N-n)){
                        tempI++;
                        spaceCount++;
                    }else{
                        digCount=0;
                    }
                }else{
                    if(mainMat[tempI] == subMat[j] && digCount < n){
                        tempI++;
                        digCount++;
                        flag=1;
                        j++;
                    }else{
                        flag=0;
                        break;
                    }
                }
            }
            if(flag == 1){
                break;
            }
        }
    }

    if(flag == 1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

}