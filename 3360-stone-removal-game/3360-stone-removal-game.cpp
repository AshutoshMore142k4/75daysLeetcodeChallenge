class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10 ;
        bool aliceturn = true ;
        while( n >= remove){
            n -= remove ;

            remove--;

            aliceturn = !aliceturn;

        }
        return !aliceturn;
    }
}; /*



Start with remove = 10 and set aliceTurn = true.
While enough stones are left:
Remove the required number of stones.
Decrease remove by 1.
Switch to the other player's turn.
When a player cannot make the move, they lose.
Return !aliceTurn to check whether Alice wins.*/