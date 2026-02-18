# 0/1 Knapsack - Greedy Approach
# Note: Greedy approach doesn't always give optimal solution for 0/1 knapsack
# It sorts items by value/weight ratio and picks items greedily

def knapsack_greedy(weights, values, capacity):
    """
    Solves 0/1 Knapsack using greedy approach
    
    Args:
        weights: list of item weights
        values: list of item values
        capacity: maximum capacity of knapsack
    
    Returns:
        total_value: maximum value obtained
        selected_items: list of selected item indices
    """
    n = len(weights)
    
    # Create a list of items with index, weight, value, and ratio
    items = []
    for i in range(n):
        if weights[i] > 0:  # Avoid division by zero
            ratio = values[i] / weights[i]
            items.append((i, weights[i], values[i], ratio))
    
    # Sort items by value/weight ratio in descending order
    items.sort(key=lambda x: x[3], reverse=True)
    
    total_value = 0
    total_weight = 0
    selected_items = []
    
    # Greedily select items
    for item in items:
        index, weight, value, ratio = item
        
        # If item fits in remaining capacity, take it
        if total_weight + weight <= capacity:
            selected_items.append(index)
            total_weight += weight
            total_value += value
    
    return total_value, selected_items


def main():
    print("=" * 50)
    print("0/1 Knapsack - Greedy Approach")
    print("=" * 50)
    
    # Input number of items
    n = int(input("\nEnter number of items: "))
    
    weights = []
    values = []
    
    # Input weights and values
    print("\nEnter weight and value for each item:")
    for i in range(n):
        w = int(input(f"Item {i+1} - Weight: "))
        v = int(input(f"Item {i+1} - Value: "))
        weights.append(w)
        values.append(v)
    
    # Input knapsack capacity
    capacity = int(input("\nEnter knapsack capacity: "))
    
    # Solve using greedy approach
    max_value, selected = knapsack_greedy(weights, values, capacity)
    
    # Display results
    print("\n" + "=" * 50)
    print("RESULTS")
    print("=" * 50)
    print(f"\nMaximum value obtained: {max_value}")
    print(f"\nSelected items (0-indexed): {sorted(selected)}")
    
    print("\nDetails of selected items:")
    print(f"{'Item':<10} {'Weight':<10} {'Value':<10} {'Ratio':<10}")
    print("-" * 40)
    
    total_weight = 0
    for idx in sorted(selected):
        ratio = values[idx] / weights[idx]
        print(f"{idx:<10} {weights[idx]:<10} {values[idx]:<10} {ratio:<10.2f}")
        total_weight += weights[idx]
    
    print("-" * 40)
    print(f"Total weight used: {total_weight}/{capacity}")
    
    print("\n" + "=" * 50)
    print("Note: Greedy approach may not always give")
    print("the optimal solution for 0/1 Knapsack problem")
    print("=" * 50)


if __name__ == "__main__":
    main()