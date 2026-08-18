class solution{
    public:
    vector<int> asteroidcollision(vector<int>& asteroids){
        stack<int> st;

        for(int ast: asteroids){
            bool destroyed = false;

            // only collision if last asteroid moving right and current moving left
            while(!st.empty() && st.top()> 0 && ast <0){
                if(abs(st.top()) <abs(ast)){
                    st.pop();//smaller asteroid explodes, continue checking for more collisions with the next asteroid in the stack
                    continue;//keep checking for more collisions with the next asteroid in the stack

                }
                else if(abs(st.top()) == abs(ast)){
                    st.pop();//both explode
                    destroyed = true;// current asteroid destroyed
                    break;
                }
            }
            if(!destroyed){
                st.push(ast);
            }
        }
        // convert stack to vector in reverse order
        vector<int> result(st.size());

        for(int i = st.size()-1; i >= 0; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
}
// input: asteroids = [5,10,-5]
// output: [5,10]