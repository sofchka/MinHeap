# MinHeap Implementation in C

## Overview
This project implements a **Min Heap** data structure in C, supporting basic heap operations such as inserting, deleting, and retrieving the minimum and maximum elements. It also includes a visualization feature for printing the heap structure.

## Features
- **Retrieve minimum element** (`getmin`)  
- **Retrieve maximum element** (`getmax`)  
- **Initialize an empty heap** (`unitHeap`)  
- **Insert a new element** (`myPush`)  
- **Remove a specific element** (`myRemove`)  
- **Remove the root element** (`myPop`)  
- **Print the heap as a tree structure** (`print`)

### Example Output
```
Min Heap elements:
       0
     /  \            
  53      44
 /  \    /  \    
66  94  47  64
Minimum element is: 0
Maximum element is: 94

After Popping the first element:
      44
     /  \            
  53      47
 /  \    /
66  94  64    
Minimum element is: 44
Maximum element is: 94

Put index to remove: 1

After Removing the [1] element:
      44
     /  \            
  64      47
 /  \    
66  94        
Minimum element is: 44
Maximum element is: 94
```
