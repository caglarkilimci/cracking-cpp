# cracking-cpp
A comprehensive collection of C++ coding problems, solutions, and resources to help you prepare for software engineering interviews. Ace your C++ interview with confidence!


## Creating a Question

To create a new question for the `cracking-cpp` collection, follow these steps:

1. Create a folder for the question: 
    - Name the folder appropriately, using a descriptive and concise title for the question.
    - Place the folder in the appropriate location within the project structure.

2. Create a CMake file for the question:
    - Name the CMake file according to the question's folder name.
    - Include any necessary build instructions or dependencies in the CMake file.

3. Add the question folder to the main CMake file:
    - Open the main CMake file located in the root directory of the project.
    - Add a reference to the question's folder in the appropriate section of the CMake file.

By following these steps, you can easily create a new question and integrate it into the `cracking-cpp` project.


## Building and Running the Questions

To build and run the questions in the `cracking-cpp` collection, follow these steps:

1. Create a build directory:
    - Open a terminal and navigate to the root directory of the project.
    - Execute the following commands:
        - `mkdir build`
        - `cd build`

2. Generate the build files using CMake:
    - Execute the following command:
        - `cmake ..`

3. Build the project using the generated build files:
    - Execute the following command:
        - `make` (to build all questions) or `make sample_question` (to build a specific question)

4. Run the executable:
    - Execute the following command:
        - `./sample_question/sample_question` (replace `sample_question` with the appropriate question name)

By following these steps, you can successfully build and run the questions in the `cracking-cpp` project.

## Building, Testing, and Cleaning the Questions Using a Script

To simplify the process of building, testing, and cleaning the questions in the `cracking-cpp` collection, a script called `build.sh` is provided. Here is how you can use the script:

```bash
$ ./build.sh -h
```

The script supports the following options:

- `-h`: Print the help message.

You can use the script with the following commands:

- `build`: Build all questions.
- `test`: Run tests for all questions.
- `clean`: Clean build files.

Additionally, you can specify a question using the `-q` option. By default, the script will perform the specified command for all questions. To specify a specific question, provide the name of the question after the `-q` option.

By using the `build.sh` script, you can easily build, test, and clean the questions in the `cracking-cpp` project.
