class TopVotedCandidate {
public:
    map<int,int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int zC = 0;
        int oC = 0;
        int lead = -1;
        map<int,int> votes;
        for(int i = 0; i < persons.size(); i++)
        {
            votes[persons[i]]++;
            if(lead == -1 || votes[persons[i]] >= votes[lead]) lead = persons[i];
            mp[times[i]] = lead;
        }
    }
    
    int q(int t) {
        return (--mp.upper_bound(t))-> second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */