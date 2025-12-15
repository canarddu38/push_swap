
*This project has been created as part of the 42 curriculum by sservant and julcleme.*

# push_swap (+Bonus)

## Description

The **push_swap** project is a program capable of sorting large quantities of numbers using stacks. With several algorithms, **push_swap** can __efficiently__ sort any list of numbers.

## Instructions

Run and compile the executable.

```bash
make re
./push_swap [FLAGS] [STACK_NUMBERS]
```
### Flags :
| --bench | --simple | --medium | --complex | --adaptive
|:-------- |:--------:| --------:| --------:| --------:|
| To display all statisticts of the program     | A basic O(n²) Algorithm   | A more advanced O(n√n) algorithm    | A complex and fast O(n log(n)) algorithm | An adaptive algorithm that fits your data the best

> **Tip:** How to generate fully random numbers
 
```bash
./push_swap [FLAGS] $(shuf -i 0-9999 -n [SIZE])
```

## Algorithms

### Simple by `julcleme`:
The simple algorithm uses a sorting method called "Bubble sort" adapted to the stack. It loops into the stack and swap pairs next to each other to sort them every iteration.
We choosed this algorithm because it is easier to implement using stacks than the other thanks to its top swap behaviour.

### Medium by `sservant`:
The chosen algorithm implements a "chunk-based" sorting strategy, specifically optimized for stack data structures. Uses a rank system to intelligently push elements towards stack B. Applies a rotation on B (rb) if the pushed element is less than the current median, creating an "hourglass" shaped distribution before pushing everything sorted back into A.
This algorithm is easier to make and the behaviour was near QuickSort one.

### Complex by `julcleme`:
This algoritm employs a "LSD radix sort" meethod adapted to the constraints of stack manipulation. It works by creating an array of indexes which represents the order of the elements inside the stack. This algorithm uses a bit-by-bit sorting by comparing only one bit at the time to sort the stacks.
This algorithm is fast to implement since it requires only the index ranking that was also used in the medium one. And still easiest to implement.

## Contributions

- **makefile** by `julcleme`
- **rank and array manipulation system** by `sservant`
- **arguments parsing** by `sservant` and `julcleme`
- **checker** by `julcleme`
- **benchmark** by `sservant`
- **libft and printf (older projects)** by `julcleme` and modified by `sservant`

## Resources

| Site | Reason
|:---|:---: |
| **Geeksforgeeks.org** | Search LSD radix method
| **Wikipedia.org** | Search index sorting method
| **Chatgpt.com** | Improved compression of topics and imposed restrictions
| **Gemini.google.com** | Translation of the readme sentences, better compression of the topic

## More informations
We chose to use an array for our push_swap because it seemed less restrictive for the algorithms and gave us more freedom for the rest.
