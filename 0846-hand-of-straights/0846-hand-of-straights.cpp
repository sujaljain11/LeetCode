class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        unordered_map<int, int> cardCount;
        for(int card: hand) {
            cardCount[card]++;
        }
        for(int i = 0; i <= n - 1; i++) {
            int currentCard = hand[i];
            if(cardCount[currentCard] == 0) continue;
            int startCard = currentCard;
            while(cardCount[startCard - 1]) startCard--;
            while(startCard <= currentCard) {
                while(cardCount[startCard]){
                    for(int i = startCard; i <= startCard + groupSize - 1; i++) {
                        if(cardCount[i] == 0) return false;
                        cardCount[i]--;
                    }
                }
                startCard++;
            }
        }
        return true;
    }
};