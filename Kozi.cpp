#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool AllBoolTrue(int n, bool* arr){
    for(int i = 0; i < n ; i++){
        if(arr[i] == false)
            return false;
    }
    return true;
}

bool Ipos(int n, int m, int* arr, int l){
    bool IPassed[n] = {false};
    int travels = 0;
    for(int i = n - 1; i >= 0; i--){
        if(!IPassed[i]){
            int teglo = 0;
            for(int j = i; j >= 0; j--){
                if(teglo + arr[j] <= l && !IPassed[j]){
                   IPassed[j] = true;
                   teglo += arr[j];
                    //cout<<j<<" "<<teglo<<endl;
                }
            }
            travels ++;
            if(travels > m){
                return false;
            }
            if(AllBoolTrue(n, IPassed)){
                return true;
            }
        }
    }
};

int main()
{
    
    int n, m;
    cin>>n>>m;
    int arr[n], sum = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    sort(arr, arr + n);
    float avg = ( (float)sum / n );
    long long endavg = floor (avg * (n / m));
    
    //endavg = 42;
    //cout<<Ipos(n, m, arr, endavg);
    
    while(true){
        if(Ipos(n, m, arr, endavg)){
            cout<<endavg;
            return 0;
        }
        endavg++;
    }
    
    
    return 0;
}
