class solution{
    public:

    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char ch = 'a';

        for(char c : key){
            if(c != ' ' && mp.find(c) == mp.end()){
                mp[c] = ch;
                ch++;
            }
        }

        string decodedMessage = "";
        for(char c : message){
            if(c == ' '){
                decodedMessage += ' ';
            } else {
                decodedMessage += mp[c];
            }
        }

        return decodedMessage;
    }
}

//input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
//output: "this is a secret"