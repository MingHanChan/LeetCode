# Binary Indexed Tree (BIT) Explanation

A Binary Indexed Tree is a data structure that efficiently supports:
- Adding a value at a specific index
- Calculating prefix sums up to a specific index
## How BIT Works

Each index in the BIT is responsible for a specific range of elements in the original array:

1. The range an index `i` is responsible for is determined by its least significant bit (LSB)
2. The LSB of `i` can be calculated as `i & -i` in most programming languages
3. Index `i` is responsible for elements from `i - LSB(i) + 1` to `i`

For example:
- Index 1 (binary 001) has LSB=1, responsible for range [1]
- Index 2 (binary 010) has LSB=2, responsible for range [1-2]
- Index 4 (binary 100) has LSB=4, responsible for range [1-4]
- Index 5 (binary 101) has LSB=1, responsible for range [5]

### BIT Operations

1. **Update Operation**: To update index `i`, we update all indices that include `i` in their range:

   ```
   while i <= n:
       BIT[i] += value
       i += i & -i
   ```
When we insert a value at index 0 in the original array (which corresponds to index 1 in the 1-indexed BIT), we need to update all BIT indices that include this position in their responsibility range.

Here's why we update these specific indices:

a. **Start with BIT[1]** (binary 001):
   - We update BIT[1] because it's directly responsible for index 1
   - Next, we move to BIT[1 + LSB(1)] = BIT[1 + 1] = BIT[2]

b. **Update BIT[2]** (binary 010):
   - BIT[2] is responsible for the range [1-2], which includes our index
   - Next, we move to BIT[2 + LSB(2)] = BIT[2 + 2] = BIT[4]

c. **Update BIT[4]** (binary 100):
   - BIT[4] is responsible for the range [1-4], which includes our index
   - Next, we would move to BIT[4 + LSB(4)] = BIT[4 + 4] = BIT[8]

d. **Continue the pattern**:
   - If the BIT size is at least 8, we would update BIT[8], then BIT[16], and so on
   - We stop when we exceed the size of the BIT

This update pattern follows the "responsibility ranges" of the BIT, ensuring that all cumulative sums involving the updated index are correctly maintained.

2. **Query Operation**: To query the sum up to index `i`:

   ```
   result = 0
   while i > 0:
       result += BIT[i]
       i -= i & -i
   return result
   ```
