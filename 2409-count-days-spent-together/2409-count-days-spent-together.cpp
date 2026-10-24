class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>dcount = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < dcount.size(); i++) {
            dcount[i] += dcount[i - 1];
        }
        int a = 0, b = 0, c = 0, d = 0;

        a = dcount[stoi(arriveAlice.substr(0, 2))-1] + stoi(arriveAlice.substr(3, 2));
        b = dcount[stoi(leaveAlice.substr(0, 2))-1] + stoi(leaveAlice.substr(3, 2));

        c = dcount[stoi(arriveBob.substr(0, 2))-1] + stoi(arriveBob.substr(3, 2));
        d = dcount[stoi(leaveBob.substr(0, 2))-1] + stoi(leaveBob.substr(3, 2));

        int l = -1, r = -1;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

        if(a >= d) {
            swap(a, c);
            swap(b, d);
        }

        if(b >= c) {
            l = max(a, c);
            r = min(b, d);
        }
        else return 0;

        // cout<<l<<" "<<r;

        return r - l + 1;
    }
};