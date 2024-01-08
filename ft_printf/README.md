# Compile and run the "my_test" test case without the library
test my_test 0

# Compile and run the "my_test" test case using the library
testlib my_test 1
```

You can also create additional test files inside the `tests/` directory and use the provided functions to compile and run them.

## Usage

To use the `ft_printf` function in your code, include the `ft_printf.h` header file:

```c
#include "ft_printf.h"
```

You can then use the `ft_printf` function to print formatted output. Here's an example:

```c
#include "ft_printf.h"

int main() {
 ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
 return 0;
}
```

This will output:
```
Hello, world! The answer is 42.
```

For detailed information about the supported format specifiers and usage examples, please refer to the source code and documentation within the repository.

## Testing

The repository provides the `test` and `testlib` functions to compile and run test cases. You can use these functions to test the functionality of the `ft_printf` implementation. The test cases should be placed inside the `tests/` directory.

### copy the bash functions:
```
test() {
    if [ ! -d "exec" ]; then
        mkdir exec
    fi

    if [[ $2 -eq 1 ]]; then
        gcc -Wall -Wextra -Werror *.c tests/${1}.test.c -o exec/${1}.output && ./exec/${1}.output
    else
        gcc *.c tests/${1}.test.c tests/test.c -o exec/${1}.output && ./exec/${1}.output | cat -e
    fi
}

testlib() {
    if [ ! -d "exec" ]; then
        mkdir exec
    fi
    if [ ! -f "libftprintf.a" ]; then
        make
    fi
    if [[ "$2" -eq 1 ]]; then
        gcc -Wall -Wextra -Werror tests/"${1}".test.c tests/test.c libftprintf.a -o exec/"${1}".output && ./exec/"${1}".output
    else
        gcc tests/"${1}".test.c tests/test.c libftprintf.a -o exec/"${1}".output && ./exec/"${1}".output | cat -e
    fi
}

push() {
    git add .
    git commit -m "$1"
    git push origin master
}
```

To compile and run a test case without using the `libftprintf.a` library, use the `test` function:

```bash
# Compile and run a test case without the library
test <test_case_name> 0
# Compile and run a test case without the library with flags
test <test_case_name> 1
```

To compile and run a test case using the `libftprintf.a` library, use the `testlib` function:

```bash
# Compile and run a test case using the library
testlib <test_case_name> 0
# Compile and run a test case using the library flags
testlib <test_case_name> 1
```

Make sure to replace `<test_case_name>` with the name of the test case file (without the file extension).

You can create additional test files inside the `tests/` directory and use the provided functions to compile and run them.

## Contributing

Contributions to the `ft_printf` repository are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request. Your contributions can help enhance the functionality and reliability of the `ft_printf` implementation.

When contributing, please follow the existing coding style and conventions used in the repository. Additionally, make sure to thoroughly test your changes to ensure they do not introduce any regressions.

## License

The `ft_printf` repository is open-source and is available under the [MIT License](LICENSE). You are free to modify, distribute, and use the code in your own projects. However, please note that the repository may contain contributionsto the `ft_printf` project from other contributors, and their contributions may be subject to different licenses. Please review the individual files and their corresponding license information for more details.
```

Please note that the provided source code is a Markdown file and should be saved with the `.md` file extension.

You can use the `test` and `testlib` functions to compile and run test cases. The `test` function is used to compile and run test cases without using the `libftprintf.a` library, while the `testlib` function is used to compile and run test cases using the library.

To create test files inside the `tests/` directory, simply create new files with the desired test cases and use the `test` and `testlib` functions to compile and run them.

Remember to replace `<test_case_name>` with the actual name of the test case file (without the file extension) when using the `test` and `testlib` functions.

Additionally, the `push` function can be used to add, commit, and push changes to the `master` branch of the repository. It takes a commit message as a parameter.

Please make sure to review and customize the code as needed for your specific project and environment.
