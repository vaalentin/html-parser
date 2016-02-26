# HTML Parser

[![Build Status](https://travis-ci.org/vaalentin/html-parser.svg?branch=master)](https://travis-ci.org/vaalentin/html-parser)

Recursive descent lexer & parser.

## Installation

```
$ mkdir build
$ cd build
$ cmake ..
```

## Usage

```
$ ./main input.html > output.txt
```

## Test

Follow installation instructions and pass `-D TESTS=ON` to cmake:

```
$ cmake -D TESTS=ON ..
```

Then:

```
$ ./tests
```

## License

MIT, see [LICENSE.md](https://github.com/vaalentin/html-parser/blob/master/LICENSE.md) for more details.
