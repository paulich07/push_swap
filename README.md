# Push swap
_42 Firenze project_

**Subject**: Create a sorting algorithm for random numbers (only certain moves are allowed).
**Bonus**: create a checker

## Main part
Compile and build the project

```
make 
```
An esecutable named *push_swap* will be created

### Usage
```
./push.swap <args>
```
<args> are random numbers to sort (no duplicates are allowed)

## Checker

An esecutable named *checker* will be created.
```
make bonus
```

### Checker usage
Insert a plain sequence of numbers as argument.
If any argument is improperly formatted, the program returns an error.
```
./push.swap <args> | ./checker <args>
```
Enter a sequence of moves via standard input.
To end the input, press **CTRL+D** (End of Transmission).
If the elements are sorted, the program returns "OK". Otherwise, it returns "KO".
If the input is not a valid move, it returns an error.

for example
```
./push.swap 4 2 1 6 5 | ./checker 4 2 1 6 5
```

You can simplify using bash variables.
```
ARGS="1 2 3"; ./push.swap $ARGS | ./checker $ARGS
```

## Bonus tip
To generate a larger amount of numbers use *shuf* command.
```
echo $(shuf -i <min>-<max> -n <num>)
```
*Generate 100 random numbers from 0 to 100*
```
echo $(shuf -i 0-100 -n 100)
```

