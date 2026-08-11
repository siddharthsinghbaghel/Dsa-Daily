class solution{
    public:
    int myAtoi(string s){
        int i = 0;
        while(i < s.length() && s[i] == ' '){
            i++;
        }
        // here we check for the sign of the number, if it is negative or positive
        int sign = 1;
        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long long result = 0;
        while(i < s.length() && isdigit(s[i])){
            result = result * 10 + (s[i] - '0');
            if(result * sign > INT_MAX){
                return INT_MAX;
            }
            if(result * sign < INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return (int)(result * sign);
    }
}