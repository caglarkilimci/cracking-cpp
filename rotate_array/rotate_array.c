#include <stdio.h>
#include "rotate_array.h"

int return_rotated_element(int array[], int size_of_array, int number_of_rotations, int element_index) {
    number_of_rotations = number_of_rotations % size_of_array;

    int start_index = (size_of_array - number_of_rotations) % size_of_array;
    int processing_index = start_index;
    int start_position = 0;
    int new_position = start_position;
    int processing_content = array[processing_index];
    int moving_content;
    int processed = 0;
    
    while (processed < size_of_array) {
        moving_content = array[new_position];
        array[new_position] = processing_content;
        processing_content = moving_content;
        
        new_position = (new_position + number_of_rotations) % size_of_array;
        
        if (new_position == processing_index) {
            array[new_position] = processing_content;
            processed++;

            start_index = (start_index + 1) % size_of_array;
            processing_index = start_index;
            start_position = (start_position + 1) % size_of_array;
            new_position = start_position;
            processing_content = array[processing_index];
        }

        processed++;
    }

    return array[element_index];
}

