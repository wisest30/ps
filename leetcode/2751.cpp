class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> order(positions.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](auto l, auto r) { return positions[l] < positions[r]; });
        
        vector<int> survive, st;
        for(auto o : order) {
            if(directions[o] == 'R') {
                st.push_back(o);
            } else {
                while(!st.empty() && healths[st.back()] < healths[o]) {
                    st.pop_back();
                    healths[o]--;
                }
                
                if(st.empty())
                    survive.push_back(o);
                else if(healths[st.back()] == healths[o])
                    st.pop_back();
                else
                    healths[st.back()]--;
            }
        }
        
        survive.insert(survive.end(), st.begin(), st.end());
        sort(survive.begin(), survive.end());
        for(auto& i : survive)
            i = healths[i];
        
        return survive;
    }
};
