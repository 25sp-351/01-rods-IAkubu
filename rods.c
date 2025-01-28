// Ian Akubu
// 2021-10-06
// This program takes in a rod length and a list of possible cuts with their respective values and finds the optimal way to cut the rod to maximize the total value using recursion.

#include <stdio.h>
#include <stdlib.h>

#define MAX_CUTS 100 // Maximum number of possible cuts

// Dictionary struct to store the length and value of each cut because I am dependent on them
typedef struct {
    int length;
    int value;
} length_value_pair;

// Recursive method to find the optimal solution also will be used in print_solution
int rod_cutting_recursive(int rod_length, length_value_pair cuts[], int num_cuts, int *best_cut) {
    if (rod_length == 0) {
        return 0;
    }

    int max_value = 0;
    int best_cut_choice = -1;

    // Recursively try all possible cuts
    for (int i = 0; i < num_cuts; i++) {
        if (cuts[i].length <= rod_length) {
            int sub_value = rod_cutting_recursive(rod_length - cuts[i].length, cuts, num_cuts, best_cut);
            int possible_value = cuts[i].value + sub_value;

            if (possible_value > max_value) {
                max_value = possible_value;
                best_cut_choice = cuts[i].length;
            }
        }
    }

    *best_cut = best_cut_choice;
    return max_value;
}

// Helper to print the optimal solution
void print_solution(int rod_length, length_value_pair cuts[], int num_cuts) {
    int remaining_length = rod_length;
    int total_value = 0;
    int cut_counts[MAX_CUTS] = {0};

    // Find the best cuts using recursion
    while (remaining_length > 0) {
        int best_cut = -1;
        int max_value = rod_cutting_recursive(remaining_length, cuts, num_cuts, &best_cut);

        if (best_cut == -1) {
            break;  // No valid cut found
        }

        cut_counts[best_cut]++;
        remaining_length -= best_cut;
        total_value += max_value;
    }

    // Calculate total value
    total_value = rod_cutting_recursive(rod_length, cuts, num_cuts, &(int){-1});

    // Print the cut list in the required format
    for (int i = 0; i < num_cuts; i++) {
        if (cut_counts[cuts[i].length] > 0) {
            printf("%d @ %d = %d\n", cut_counts[cuts[i].length], cuts[i].length, 
                   cut_counts[cuts[i].length] * cuts[i].value);
        }
    }

    // Print the remainder and final total value
    printf("Remainder: %d\n", remaining_length);
    printf("Value: %d\n", total_value);
}

int main() {
    // Initialize the rod length and cut information
    int rod_length;
    printf("Enter the rod length: \n");
    scanf("%d", &rod_length);

    length_value_pair cuts[MAX_CUTS];
    int num_cuts = 0;

    // Take length-value pairs as input
    printf("Enter the cut length and value as 'length, value':\n");
    while (num_cuts < MAX_CUTS && scanf("%d, %d", &cuts[num_cuts].length, &cuts[num_cuts].value) == 2) {
        num_cuts++;
    }

    // Print the results
    print_solution(rod_length, cuts, num_cuts);

    return 0;
}
