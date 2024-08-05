# BissantiSort

BissantiSort is an innovative sorting algorithm that combines the benefits of PowerSort and TimSort to optimize the sorting of partially ordered arrays. This algorithm was developed by Roberto Bissanti.

You can find more information on the related wiki page: <https://github.com/robertobissanti/BissantiSort/wiki>

## Description

BissantiSort detects runs (ordered sequences) within the array and uses a combination of PowerSort and TimSort to efficiently sort and merge these runs. The algorithm leverages the efficiency of PowerSort in detecting and sorting runs, combined with the optimization of TimSort for partially ordered data.

## Features

- **Time Complexity**: O(n) in the best case, O(n log n) in the worst and average cases.
- **Space Complexity**: O(n).
- **Stability**: Maintains the relative order of equal elements.
- **Adaptability**: Excellent with partially ordered data.

## Project Structure

```plaintext
BissantiSort/
├── include/
│   └── bissanti_sort.h
├── src/
│   └── bissanti_sort.c
├── test/
│   └── test_bissanti_sort.c
├── README.md
└── LICENSE
```

## Usage

### Compilation

To compile the algorithm, use the following commands:

```sh
gcc -o test_bissanti_sort test/test_bissanti_sort.c src/bissanti_sort.c

```

### Execution

To run the algorithm, use the following commands:

```sh
./test_bissanti_sort
```

### Code Example

```sh
#include <stdio.h>
#include "include/bissanti_sort.h"

int main() {
    int array[] = {9, 10, 12, 14, 27, 4, 3, 1, 7, 5, 6, 2, 8};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bissantiSort(array, length);

    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
```

### API

```sh
void bissantiSort(int* array, int length);
```

### Testing

We have included some test files to verify the effectiveness of the algorithm. To run the tests, use the following command:

```sh
./test_bissanti_sort
```

### Contribution

Contributions are welcome! Feel free to fork the project, open issues, and submit pull requests.

### License

This project is licensed under the GNU General Public License v3.0. See the LICENSE file for more details.

### Author

Roberto Bissanti
<roberto.bissanti@gmail.com>
Alessandro Bissanti
<alessandro.bissanti@gmail.com>
