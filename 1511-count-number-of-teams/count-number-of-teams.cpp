class Solution {
public:
    int numTeams(vector<int>& rating) {
        int totalTeams = 0;
        int soldierCount = rating.size();

        for (int currentSoldier = 0; currentSoldier < soldierCount;
             currentSoldier++) {
            totalTeams += countTeams(rating, currentSoldier, soldierCount);
        }

        return totalTeams;
    }

private:
    int countTeams(const vector<int>& rating, int currentSoldier,
                   int soldierCount) {
        auto leftCounts = countSmallerAndLarger(rating, 0, currentSoldier,
                                                rating[currentSoldier]);
        auto rightCounts = countSmallerAndLarger(
            rating, currentSoldier + 1, soldierCount, rating[currentSoldier]);

        int ascendingTeams = leftCounts.first * rightCounts.second;
        int descendingTeams = leftCounts.second * rightCounts.first;

        return ascendingTeams + descendingTeams;
    }

    pair<int, int> countSmallerAndLarger(const vector<int>& rating, int start,
                                         int end, int reference) {
        int smaller = 0, larger = 0;

        for (int i = start; i < end; i++) {
            if (rating[i] < reference) {
                smaller++;
            } else if (rating[i] > reference) {
                larger++;
            }
        }

        return {smaller, larger};
    }
};