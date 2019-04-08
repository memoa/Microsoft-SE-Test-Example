# Microsoft SE Test Example
Here is my solution of this test written in C++.
Test example can be found at: [https://www.microsoft.com/sr-latn-rs/mdcs/prepare-for-se-test.aspx](https://www.microsoft.com/sr-latn-rs/mdcs/prepare-for-se-test.aspx)

## Example01
For this example I created simple dictionary structure to check if such key-value pair does or not exist in the structure. `AreStringsIsomorphic` function uses this dictionary, while iterating through test strings, to memorize and check pairs of characters from test strings with previous memorized pairs. In that purpose, method `check_keyval` has been implemented in `Char_dict` structure, so if key-value pair does not exist in the structure, then adding such key-value pair and returns `true` to confirm that strings are still candidates for isomorphic check. Also, if key-value pair completely match to one of already memorized pair, method will return `true`, but not memorizing the pair. And the last condidion, if key-value pair only partly matches to one of memorized pair (just keys or values are equal but not the other side), method returns `false`, to give a signal that isomorphic test should stop immediately because it's proven that test strings are not isomorphic. After all, if it's not proven that test strings are not isomorphic, then `AreStringsIsomorphic` will return `true`.
## Example02
To linking tree nodes, I implemented stack, for tracking parents of current node, because in `TreeNode` structure, there is no pointer to parent node and when a leaf is linked, there is need to go back to first parent which have free `sibling` pointer. So, constructor `Tree(int* a, int m)` *(which I made as a replacement for function `TreeNode generateTree(int m, int* a)`)* will link first readed element of array `a` to `root` property of a `Tree` object, and each next element will be checked if it is even or odd and linking current node to `firstChild` or `sibling` pointer, of previously linked node, correspondently. Every time if leaf is not a current node, pointer of current node will be pushed into stack, and if current node is leaf, then pointers of parent nodes will be pulled out of a stack while not found a pointer of node which have free `sibling` pointer. `pre_order()` method traversing the `Tree` object as requested, using `pre_order(TreeNode* node)` method where `root` pointer's value is assigned to `node` method parameter, to define root of tree as start point for tree traverse.
## Example03
I solved this by iterating through test array only once. Initially, minimal period is 1 and then each time when element at position of `i % T` (element from minimal repeating sequence) is not equal to current iterated element in array, new minimal period is assigned to value of iterator `i` to set new possible minimal period of repeating sequence. After iteration, it's possible that minimal repeating sequence is not completely repeated and to cover that case, there is additional check if last element from minimal repeating sequence is equal to last element in array. If so, minimal period is confirmed, otherwise minimal period is assigned to length of an array.

      0  1  2  3  4  5  6  7 --- addresses of array elements
    { 2, 5, 3, 4, 2, 5, 3, 4 } --- values of array elements
    |    ^        |  ^
    |  i % T      |  i
    | <---------> | range for iterator i % T
                  T - current minimal period (index value)
*Illustration of comparing elements in array at moment when `i = 5`, `i % T = 5 % 4 = 1`*
## Example04
First, I created a class for linked list and implemented `ReverseNodes` as method in a class. The key of implementation`ReverseNodes` method is to use 4 pointers when re-linking selected elements in list, and iterating through list 2 times. First time is dedicated to position all pointers, assigning them to point on corresponding nodes. Pointers `L1`, `L2` and `L3` have a purpose of reverse linking and `curr` pointer points to `IndexB`-th node in list. `L1` will point to (`indexA - 1`)-th node, `L2` to `indexA`-th and `L3` to (`indexA + 1`)-th node in list while `curr` pointer will point to last node in range, after first iteration through list.

    1      2      3      4      5      6
    a ---> c ---> x ---> q ---> e ---> 2 ---> NULL
    ^      ^      ^      ^
    L1     L2     L3    curr
         indexA        indexB
*Ilustration of "Positioning pointers" stage*

After that, re-linking begins. I divided it in two parts and called `I stage` and `II stage`. In first stage, nodes at range endpoints are re-linked.

           * -----------------> *
    * -----|-----------> *      |
    a -/-> c -/-> x ---> q ---> e ---> 2 ---> NULL
    ^      ^      ^      ^
    L1     L2     L3    curr
         indexA        indexB
*Ilustration of `I stage`*

In `II Stage` (final), reverse linking is implemented moving pointers to the next nodes by initial nodes order and then assigning node at pointer `L2` to point to node at pointer `L1`, so previously assigned `L3` pointer keeps initial order of nodes for next iterations. Number of iterations in this stage is equal to amount of nodes in a range for reverse linking.

           * -----------------> *
    * -----|-----------> *      |
    a      c <--- x -/-> q ---> e ---> 2 ---> NULL
           ^      ^      ^
           L1     L2     L3    
                        curr
         indexA        indexB
*Ilustration of `II stage` - first step*

           * -----------------> *
    * -----|-----------> *      |
    a      c <--- x <--- q -/-> e ---> 2 ---> NULL
                  ^      ^      ^
                  L1     L2     L3    
                        curr
         indexA        indexB
*Ilustration of `II stage` - last step*

And the final result of `ReverseNodes` method will be

    1      4      3      2      5      6
           * -----------------> *
    * -----|-----------> *      |
    a      c <--- x <--- q      e ---> 2 ---> NULL
*Ilustration of result of completed reverse linking operation*
