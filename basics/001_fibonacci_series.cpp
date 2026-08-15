int main(){
    int n;
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    cout<<"enter the no. of terms";
    cin>>n;

    cout<<"the fibonacci series is : ";

    for(int i = 0; i<=n; i++){
        cout<<t1<<"";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
//input : n = 5
//output : 0 1 1 2 3 5