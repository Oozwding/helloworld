#include <iostream>

using namespace std;

int main()
{
    int a[1001];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){ 
        int m;
        cin >> m;
        for(int j=0;j<m;j++)
            cin >> a[j];
        for(int k=0;k<m-1;k++){
            for(int l=k+1;l<m;l++){
                if(a[k]>a[l]){
                    int temp = a[k];
                    a[k] = a[l];
                    a[l] = temp;
                }
            }
        }
        for(int j=0;j<m-1;j++)
            cout << a[j] << " ";
        cout << a[m-1] << endl;
    }
    return 0;
}
