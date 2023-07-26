# CPP

## day 00

## day 01

### malloc() vs new():

`malloc()`: It is a C library function that can also be used in C++, while the “`new`” operator is specific for C++ only. 
 
Both `malloc()` and new are used to allocate the memory dynamically in heap. But “`new`” does call the constructor of a class whereas “`malloc()`” does not.

### free() vs delete: 

`free()` is a C library function that can also be used in C++, while “`delete`” is a C++ keyword.
`free()` frees memory but doesn’t call Destructor of a class whereas “`delete`” frees the memory and also calls the Destructor of the class.

## day 02

### Fixed-Point Numbers

Fixed points numbers are represented using integer values.

As the name implies, the position of the point between the integer and fractional part is fixed - meaning the number of bits representing the integer part as well as the number of bits representing the fractional part is always the same. 

In the following, the values NUM_INT_BITS and NUM_FRAC_BITS define the number of bits used for representing the integer respectively the fractional part of a decimal number.

The examples and implementation uses all a 24.8 representation, meaning:

NUM_INT_BITS = 24
NUM_FRAC_BITS = 8
NUM_TOTAL_BITS = NUM_INT_BITS + NUM_FRAC_BITS = 32 (size of int)

In order to store the value of a real number in fixed-point we need to shift the value of the real number by the number of fractional bits of the fixed-point.

in this module we are required to have a fracional bits equal to 8 and a 32bit integer variable to store the value of the fixed-point number.

To store the value of a real number in a fixed-point number we simply shift the real number to the left by the number of the fractional bits, for example `realNumber = 12.75`:

```c++
int     fpValue ;
float   realNumber  = 12.75f ;

// fpValue          = realNumber << fractionalBits
fpValue             = realNumber * (1 << fractionalBits) ;
// fpValue          = 12.75 << 8
// fpValue          = 12.75 * 256 = 3264
```

To convert a fixed-point number to floating number you simply shift the `fpValue` to the right by the `fractionalBits` and you get the real number value back:

```c++
int     fpValue     = 3264;
float   realNumber ;

// realNumber       = fpValue >> fractionalBits
realNumber          = fpValue / (1 << fractionalBits) ;
// fpValue          = 3264 >> 8
// fpValue          = 3264 / 256 = 12.75000000000000000000
```

### Limits

The maximum number we can store in a fixed-point (8 fractional bits and a 24bit signed int) is  `8388607.996` and the minimum is `-8388608` and they are represented as follow:

| #                             | Real number   | Fixed point value     | Binary                               |
| :--:                          | :-:           | :-:                   | :-:                                  |
| min                           | -8388608      | -2147483648           | 10000000 00000000 00000000 00000000  |
| max                           | 8388607.996   | 2147483647            | 01111111 11111111 11111111 11111111  |
| min bits                      | 0             | 0                     | 00000000 00000000 00000000 00000000  |
| max bits                      | -0.00390625   | -1                    | 11111111 11111111 11111111 11111111  |
| max bits before decimal point | -1            | -256                  | 11111111 11111111 11111111 00000000  |
| min bits before decimal point | 1             | 256                   | 00000000 00000000 00000001 00000000  |
| max bits after decimal point  | 0.99609375    | 255                   | 00000000 00000000 00000000 11111111  |
| min bits after decimal point  | 0.00390625    | 1                     | 00000000 00000000 00000000 00000001  |

### Binary representaion:

#### example of 12.75:

| -2<sup>23</sup> | 2<sup>22</sup> | 2<sup>21</sup> | 2<sup>20</sup> | 2<sup>19</sup> | 2<sup>18</sup> | 2<sup>17</sup> | 2<sup>16</sup> | 2<sup>15</sup> | 2<sup>14</sup> | 2<sup>13</sup> | 2<sup>12</sup> | 2<sup>11</sup> | 2<sup>10</sup> | 2<sup>9</sup> | 2<sup>8</sup> | 2<sup>7</sup> | 2<sup>6</sup> | 2<sup>5</sup> | 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> | 2<sup>-1</sup> | 2<sup>-2</sup> | 2<sup>-3</sup> | 2<sup>-4</sup> | 2<sup>-5</sup> | 2<sup>-6</sup> | 2<sup>-7</sup> | 2<sup>-8</sup> |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | 
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 8 | 4 | 0 | 0 | 0.5 | 0.25 | 0 | 0 | 0 | 0 | 0 | 0 |


The value of x of this fixed-point number is calculated as:

x = 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>-1</sup> + 2<sup>-2</sup> = 8 + 4 + 0.5 + 0.25 = 12.75

#### example of -0.00390625:

| -2<sup>23</sup> | 2<sup>22</sup> | 2<sup>21</sup> | 2<sup>20</sup> | 2<sup>19</sup> | 2<sup>18</sup> | 2<sup>17</sup> | 2<sup>16</sup> | 2<sup>15</sup> | 2<sup>14</sup> | 2<sup>13</sup> | 2<sup>12</sup> | 2<sup>11</sup> | 2<sup>10</sup> | 2<sup>9</sup> | 2<sup>8</sup> | 2<sup>7</sup> | 2<sup>6</sup> | 2<sup>5</sup> | 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> | 2<sup>-1</sup> | 2<sup>-2</sup> | 2<sup>-3</sup> | 2<sup>-4</sup> | 2<sup>-5</sup> | 2<sup>-6</sup> | 2<sup>-7</sup> | 2<sup>-8</sup> |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | 
| -1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 
| -8388608 | 4194304 | 2097152 | 1048576 | 524288 | 262144 | 131072 | 65536 | 32768 | 16384 | 8192 | 4096 | 2048 | 1024 | 512 | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | 0.5 | 0.25 | 0.125 | 0.0625 | 0.03125 | 0.015625 | 0.0078125 | 0.00390625 |

The value of x of this fixed-point number is calculated as:

x = -2<sup>23</sup> + 2<sup>22</sup> + 2<sup>21</sup> + 2<sup>20</sup> + 2<sup>19</sup> + 2<sup>18</sup> + 2<sup>17</sup> + 2<sup>16</sup> + 2<sup>15</sup> + 2<sup>14</sup> + 2<sup>13</sup> + 2<sup>12</sup> + 2<sup>11</sup> + 2<sup>10</sup> + 2<sup>9</sup> + 2<sup>8</sup> + 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> + 2<sup>-1</sup> + 2<sup>-2</sup> + 2<sup>-3</sup> + 2<sup>-4</sup> + 2<sup>-5</sup> + 2<sup>-6</sup> + 2<sup>-7</sup> + 2<sup>-8</sup>

x = -8388608 + 4194304 + 2097152 + 1048576 + 524288 + 262144 + 131072 + 65536 + 32768 + 16384 + 8192 + 4096 + 2048 + 1024 + 512 + 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 + 0.5 + 0.25 + 0.125 + 0.0625 + 0.03125 + 0.015625 + 0.0078125 + 0.00390625

x = -0.00390625


## resouces:

### general resources
[cplusplus.com](https://cplusplus.com/reference/)

### day00

### day01

[new vs malloc and free vs delete in c](https://www.geeksforgeeks.org/new-vs-malloc-and-free-vs-delete-in-c/)

### day02

#### Floating point
[Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)

[Floating point number representation](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)

[Printing floating point numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)

[Understanding and implementing fixed point numbers](http://www.sunshine2k.de/articles/coding/fp/sunfp.html#:~:text=Fixed%20points%20numbers%20are%20represented,part%20is%20always%20the%20same.)

#### Fixed point

[Fixed point Sheet](https://docs.google.com/spreadsheets/d/1zVCpyq5oLJvndQdyd9-gP0527NfVwUjyuhBUoxKFJVg/edit?pli=1#gid=0)

[Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)

[Fixed Point Arithmetic : Division](https://witscad.com/course/computer-architecture/chapter/fixed-point-arithmetic-division)

[Emulated Fixed Point Division/Multiplication](https://stackoverflow.com/questions/5028986/emulated-fixed-point-division-multiplication)

[How can we calculate 1/3 by using fixed-point arithmetic?](https://stackoverflow.com/questions/46104132/how-can-we-calculate-1-3-by-using-fixed-point-arithmetic)


[float to binary convertor](https://www.binaryconvert.com/result_float.html?decimal=045049)

[signed int to binary convertor](https://www.binaryconvert.com/convert_signed_int.html)

[Fixed Point Representation](https://www.geeksforgeeks.org/fixed-point-representation/)

[Fixed-Point Arithmetic: An Introduction](http://www.digitalsignallabs.com/fp.pdf)