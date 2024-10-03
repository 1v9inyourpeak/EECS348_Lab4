/*
Drew franke
3131934
Lab session: Wednesday 1:00pm
Lab Assignment: 04-1
Description: Given an integer representing a score in a National Football League (NFL) game, the program
determines all possible combinations of scoring plays that can result in that score.
TDS = touchdowns, fgs / fg = field goals
*/


#include <stdio.h>

void find_combinations(int score) {
    // loop through all possible combinations of scoring plays
    for (int TDS_plus_2pt = 0; TDS_plus_2pt <= score / 8; TDS_plus_2pt++) {
        for (int TDS_plus_fg = 0; TDS_plus_fg <= score / 7; TDS_plus_fg++) {
            for (int TDS = 0; TDS <= score / 6; TDS++) {
                for (int FGS = 0; FGS <= score / 3; FGS++) {
                    for (int safeties = 0; safeties <= score / 2; safeties++) {
                        int total_score = (TDS_plus_2pt * 8) + (TDS_plus_fg * 7) + (TDS * 6) + (FGS * 3) + (safeties * 2);

                        // check if the total score matches the desired score
                        if (total_score == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   TDS_plus_2pt, TDS_plus_fg, TDS, FGS, safeties);
                        }
                    }
                }
            }
        }
    }
}

// main loop to prompt for input and process scores
int main() {
    int score;
    
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        find_combinations(score);
    }

    return 0;
}
