#include <iostream> // Include the input-output stream library
#include <algorithm> // Include the algorithm library for sorting

// Structure to store item details
struct Item {
    float weight; // Weight of the item
    float profit; // Profit of the item
    float ratio;  // Profit-to-weight ratio
};

// Comparator function to sort items by their profit-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Return true if a's ratio is greater than b's ratio
}

// Function to solve the fractional knapsack problem
void knapSack(int n, Item items[], float capacity) {
    float x[20] = {0}; // Array to store fractions of items, initialized to 0
    float totalProfit = 0.0; // Total profit initialized to 0
    int i; // Loop variable
    float remainingCapacity = capacity; // Remaining capacity of the knapsack initialized to the input capacity

    // Iterate through the items and add to knapsack
    for (i = 0; i < n; i++) {
        if (items[i].weight > remainingCapacity) {
            break; // Break if the current item can't fit entirely in the remaining capacity
        } else {
            x[i] = 1.0; // Take the whole item
            totalProfit += items[i].profit; // Add the profit of the whole item to the total profit
            remainingCapacity -= items[i].weight; // Subtract the weight of the whole item from the remaining capacity
        }
    }

    // If there's remaining capacity, take the fraction of the next item
    if (i < n) {
        x[i] = remainingCapacity / items[i].weight; // Calculate the fraction of the item that can fit
        totalProfit += (x[i] * items[i].profit); // Add the profit of the fraction of the item to the total profit
    }

    std::cout << "\nCumulative Benefit: " << totalProfit << std::endl; // Print the total profit
}

// Main function
int main() {
    Item items[20]; // Array to store up to 20 items
    float capacity; // Variable to store the capacity of the knapsack
    int num, i; // Variables to store the number of items and loop variable

    std::cout << "\nEnter the number of objects: "; // Prompt user to enter the number of items
    std::cin >> num; // Read the number of items

    std::cout << "\nEnter the capacity of the knapsack: "; // Prompt user to enter the capacity of the knapsack
    std::cin >> capacity; // Read the capacity of the knapsack

    std::cout << "\nEnter weight and profit for each item:\n"; // Prompt user to enter weight and profit for each item

    for (i = 0; i < num; i++) { // Loop to read the details of each item
        std::cout << "Item " << i + 1 << ":\n"; // Print item number
        std::cout << "\tWeight: "; // Prompt user to enter the weight of the item
        std::cin >> items[i].weight; // Read the weight of the item
        std::cout << "\tProfit: "; // Prompt user to enter the profit of the item
        std::cin >> items[i].profit; // Read the profit of the item
        items[i].ratio = items[i].profit / items[i].weight; // Calculate the profit-to-weight ratio of the item
    }

    // Sort items by profit-to-weight ratio in descending order
    std::sort(items, items + num, compare); // Sort the items array using the compare function

    // Solve the knapsack problem
    knapSack(num, items, capacity); // Call the knapSack function with the number of items, items array, and knapsack capacity

    getchar(); // Wait for user input before closing
    return 0; // Return 0 to indicate successful execution
}

/*Detailed Explanation:
Libraries:

#include <iostream>: Used for input and output operations.
#include <algorithm>: Used for sorting the items based on their profit-to-weight ratio.
Item Structure:

Defines a structure Item to store the weight, profit, and profit-to-weight ratio of each item.
Comparator Function:

compare(Item a, Item b): A function to compare two items based on their profit-to-weight ratio. This is used for sorting the items in descending order of their ratios.
knapSack Function:

void knapSack(int n, Item items[], float capacity): Function to solve the fractional knapsack problem.
float x[20] = {0}: Array to store fractions of items to be taken, initialized to 0.
float totalProfit = 0.0: Variable to keep track of the total profit.
float remainingCapacity = capacity: Variable to track the remaining capacity of the knapsack.
The for loop iterates through the items. If an item can fit entirely, it is added to the knapsack. Otherwise, the loop breaks.
If the loop breaks and there is remaining capacity, a fraction of the next item is taken.
The total profit is printed at the end.
main Function:

Item items[20]: Array to store up to 20 items.
Prompts the user to enter the number of items and the capacity of the knapsack.
Reads the weight and profit for each item and calculates the profit-to-weight ratio.
Sorts the items based on their profit-to-weight ratio in descending order.
Calls the knapSack function to solve the problem.
Waits for user input before closing the program. */