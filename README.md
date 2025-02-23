# Damm Algorithm CLI Tool

## Overview
This is a command-line utility that implements the [Damm Algorithm](https://en.wikipedia.org/wiki/Damm_algorithm) for check digit calculation and validation. The tool allows users to compute a check digit for a given number or validate a number with an existing check digit.

## Features
- Compute the Damm check digit for a given number.
- Validate a number with an existing check digit.

## Installation
To build the executable, compile the C source code using GCC:

```sh
gcc -o damm damm.c
```

## Usage

### Compute Check Digit
To compute the check digit for a given number:
```sh
./damm 12345
```
_Output:_
```
123459
```

### Validate a Number
To validate a number with its check digit:
```sh
./damm -c 123459
```
Or using the long option:
```sh
./damm --check 123459
```
_Output:_ (No output if valid, error message if invalid)

### Display Version
To display the version of the program:
```sh
./damm --version
```

### Show Help
To display help information:
```sh
./damm --help
```

## License
See [licence](LICENSE).

## Author
Brian P. Giroux


