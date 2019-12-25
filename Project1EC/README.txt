Project1 Extra Credit
Author: Nicky Valdecanas

Instructions:
-To run type: python3 project1EC.python3
-It will first have the user select which graph they want to see. 
The selections are Bubble Sort (1), Insertion Sort (2), and Selection 
Sort (3)

Bubble Sort Complexity Analysis
- The number of key comparisions is always going to be theta(n^2) because
in the algorithm it will always be comparing inside the inner for loop
with every single iteration for best worst and average case. The number
of key comparisons will be the same throughout.

Insertion Sort Complexity Analysis
- The number of key comparisons will be different for best average and worst
case. Best case will only do one comparison in the inner loop because it doesn't have to do
any further comparing when the number before it is smaller because if it's smaller
then the numbers before it are already sorted. Therefore it is theta(n). 
In average case it will be omega(n^2). According to the graph it seems like the number
of comparisons vary because there can be some further comparisons or just one. 
In the worst case it will be theta(n^2) because the numbers before will always be
bigger all the way through until the first position of the list since it's in reverse.

Selection Sort Complexity Analyis
-Just like Bubble Sort, Insertion Sort will always have the same complexity
theta(n^2) because it's always comparing in the inner loop. Although the number
of swaps would be different because it's called in the outter loop so the run
time complexity would be different from Bubble Sort.

