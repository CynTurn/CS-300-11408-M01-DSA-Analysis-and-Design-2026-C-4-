# Project One - Data Structure Analysis

## Run-Time and Memory Analysis

The following comparison analyzes the run-time performance, memory usage, and implementation considerations of the Vector, Hash Table, and Binary Search Tree data structures evaluated in Project One.

### Data Structure Comparison

| Feature | Vector | Hash Table | Binary Search Tree |
|---|---|---|---|
| Search | O(n) | O(1) average | O(log n) average |
| Insert | O(1) at end | O(1) average | O(log n) average |
| Sorted Output | Requires sorting | Requires sorting | In-order traversal |
| Memory Usage | Low | Moderate | Moderate |
| Implementation Complexity | Easy | Moderate | Moderate |

### Advantages and Disadvantages

**Vector**

Advantages:
- Simple to implement
- Low memory overhead
- Efficient for sequential processing

Disadvantages:
- Linear search time
- Requires sorting before displaying courses alphabetically
- Performance decreases as the number of courses grows

**Hash Table**

Advantages:
- Very fast average search time
- Efficient lookups by course number
- Handles large datasets efficiently

Disadvantages:
- Does not maintain sorted order
- Requires collision handling
- Uses more memory than a vector

**Binary Search Tree**

Advantages:
- Efficient searching and insertion
- Naturally stores courses in sorted order
- In-order traversal prints courses alphabetically

Disadvantages:
- Can become unbalanced
- Worst-case search time becomes O(n)
- More complex to implement than a vector

### Recommendation

I recommend using the Binary Search Tree for the final implementation. Although the Hash Table provides the fastest average search performance, the Binary Search Tree offers an effective balance between search efficiency and maintaining the courses in sorted order. Because the project requires displaying the complete course list in alphanumeric order, the Binary Search Tree can perform this naturally using an in-order traversal without requiring an additional sorting step. This makes it the most appropriate data structure for the final project because it supports efficient searching while also meeting the display requirements.
