# HW1_Problem_9
By Yevgeniy Sumaryev

HW1__Problem_9
In this problem we were testing whether randomly generated sequence of 0’s and 1’s was a de Brujin sequence, 
which is a cyclic sequence in which every possible length-n string occurs exactly once as a substring, as a contiguous subsequence. 
My approach was to first pick the length of the main sequence and then the length of the subsequence. 
After that I would test for the de Brujin sequence using vector and then using linked list.
 Using Vector:
My program would go sequentially starting from the first element in the main sequence up to the last, checking substring sequences of length n. 
I used a helper method which returns a subsequence as a string, and then I would put that string into array of subsequences, 
but first checking if the subsequence already exists in that array. If we can get to the last element of the main sequence without any repeating subsequences
we found the de Brujin sequence. I also used a mod arithmetic when length of subsequence + index of the element was bigger than array length 
in order to wrap around to the starting element.
 Using Linked List:
In this approach I would also go sequentially traversing a list starting from the first element in the main sequence up to the last, 
checking substring sequences of length n. I used a helper method which returns a subsequence as a string, 
and then I would put that string into list of subsequences, but first checking if the subsequence already exists in that list. 
I used Iterator to search the list of subsequences. If we can get to the last element of the main sequence without any repeating subsequences
we found the de Brujin sequence. I also used a mod arithmetic when length of subsequence + iterator pointer to the element 
was bigger than list length in order to wrap around to the starting element.
To mutate a sequence I would sequentially iterate through an array or a linked list from start to last element, 
generate a random number from 1 to 100, if the number was equal to or less than 5 I would change the character from 0 to 1 or from 1 to 0.
 When using a list I had to use Iterator to traverse it
The program would find de Brujin sequences quickly whenever the sequence was of the form B(n,k) length n^k, 
n being the size of the alphabet (2 in our case because we only used 0 and 1) and k being the size of the subsequence.
So when the size of subsequence was 3, the program was 
able to find deBrujin sequence relatively often when array length was 8. When I tested arrays of lengths 10 and 12, deBrujin sequence was never found.
 When timing how long it took an array vs a list to find the sequence, array was always faster.
