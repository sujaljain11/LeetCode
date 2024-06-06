class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int, int> cardCount;
        if(n % groupSize != 0) return false;
        for(int card: hand) {
            cardCount[card]++;
        }
        while(!cardCount.empty()) {
            int currentCard = cardCount.begin() -> first;
            for(int i = 0; i <= groupSize - 1; i++) {
                if(cardCount[currentCard + i] == 0) return false;
                cardCount[currentCard + i]--;
                if(cardCount[currentCard + i] == 0){
                    cardCount.erase(currentCard + i);
                }
            }
        }
        return true;
    }
};