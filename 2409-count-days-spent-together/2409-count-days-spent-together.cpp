class Solution {
public:
    int dayOfYear(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int total = day;

        for (int i = 1; i < month; i++) {
            total += days[i];
        }

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int aliceStart = dayOfYear(arriveAlice);
        int aliceEnd   = dayOfYear(leaveAlice);

        int bobStart = dayOfYear(arriveBob);
        int bobEnd   = dayOfYear(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if (start > end)
            return 0;

        return end - start + 1;
    }
};