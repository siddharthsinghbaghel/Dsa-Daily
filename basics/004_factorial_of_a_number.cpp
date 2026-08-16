int main(){
    int n;
    long long fact =1;
    cout<<"enter a number";
    cin>>n;

    for(int i =1; i<=n; i++){
        fact = fact * i;
    }
    cout<<"the factorial of "<<n<<" is : "<<fact;
    return 0;
    
}