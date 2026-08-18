int main(){
    int n;
    cout<<"enter a number";
    cin>>n;

    cout<<"the prime factors of "<<n<<" are : ";
    
    //divide by 2 as long as possible
    while(n%2 == 0){
        cout<<2<<" ";
        n = n/2;
    }
    //check odd factors
    for(int i =3; i<=sqrt(n); i+=2){
        while(n%i == 0){
            cout<<i<<" ";
            n = n/i;
        }
    }
    //if n is still > 2, then n is prime
    if(n>2){
        cout<<n;
    }
    return 0;
}
//input: n = 56
//output: the prime factors of 56 are : 2 2 2 7