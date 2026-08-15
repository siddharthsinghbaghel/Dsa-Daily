int main(){
    int n,i;
    bool isprime = true;
    cout<<"enter a number";
    cin>>n;

    if(n<=1){
        isprime = false;
    }
    else{
        for(i=2; i<=n/2; i++){
            if(n%i == 0){
                isprime = false;
                break;
            }
        }
    }
    if(isprime){
        cout<<n<<" is a prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }
    return 0;
}

// 2nd way to check prime number

bool isprime(int n){
    if(n<=1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;

    for(int i =3; i<=sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
        
    }
    return true;
}
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;

    if(isprime(n)){
        cout<<n<<" is a prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }
    return 0;
}

// input: n = 7
// output: 7 is a prime number


// 3rd way to check prime number upto n

bool isprime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2 == 0) return false;

    for(int i =3; i<=sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n ;
    cout<<"enter a limit";
    cin>>n;

    cout<<"prime numbers upto"<<n<<" are : ";
    for(int i =2; i<=n; i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }
    return 0;
}
// input: n = 10
// output: prime numbers upto 10 are : 2 3 5 7