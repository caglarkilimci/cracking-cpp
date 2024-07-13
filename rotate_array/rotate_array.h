#ifndef ROTATE_ARRAY_H
#define ROTATE_ARRAY_H

// Write a function that will return the correct element after rotation.

int return_rotated_element(int array[], int size_of_array, int number_of_rotations, int element_index);

// The function needs to output the correctly rotated element considering: 
//   - a number_of_rotations circular right rotations are performed. One rotation means
// an array {a0, a1, a2, …, an-1} will become {an-1, a0, a1, a2, …, an-2}. It can be
// between 1 and 10000
//   - the size_of_array tells how big the array is and can be between 1 and 10000
//   - element index will tell you which index position must be returned after performing 
// the rotations and can be between 0 and size_of_array – 1.

#endif // ROTATE_ARRAY_H
