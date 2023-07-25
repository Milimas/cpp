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

### Fixed Point Numbers

Fixed point is a method of representing fractional numbers (real numbers) by storing the fractional part as an integer shifted to the left by the number of fractional bits of the fixed point.

#### example of 12.75:

| 2<sup>23</sup> | 2<sup>22</sup> | 2<sup>21</sup> | 2<sup>20</sup> | 2<sup>19</sup> | 2<sup>18</sup> | 2<sup>17</sup> | 2<sup>16</sup> | 2<sup>15</sup> | 2<sup>14</sup> | 2<sup>13</sup> | 2<sup>12</sup> | 2<sup>11</sup> | 2<sup>10</sup> | 2<sup>9</sup> | 2<sup>8</sup> | 2<sup>7</sup> | 2<sup>6</sup> | 2<sup>5</sup> | 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> | 2<sup>-1</sup> | 2<sup>-2</sup> | 2<sup>-3</sup> | 2<sup>-4</sup> | 2<sup>-5</sup> | 2<sup>-6</sup> | 2<sup>-7</sup> | 2<sup>-8</sup> |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | 
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 8 | 4 | 0 | 0 | 0.5 | 0.25 | 0 | 0 | 0 | 0 | 0 | 0 |


The value of x of this fixed point number is calculated as:

x = 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>-1</sup> + 2<sup>-2</sup> = 8 + 4 + 0.5 + 0.25 = 12.75

#### example of x:

| 2<sup>23</sup> | 2<sup>22</sup> | 2<sup>21</sup> | 2<sup>20</sup> | 2<sup>19</sup> | 2<sup>18</sup> | 2<sup>17</sup> | 2<sup>16</sup> | 2<sup>15</sup> | 2<sup>14</sup> | 2<sup>13</sup> | 2<sup>12</sup> | 2<sup>11</sup> | 2<sup>10</sup> | 2<sup>9</sup> | 2<sup>8</sup> | 2<sup>7</sup> | 2<sup>6</sup> | 2<sup>5</sup> | 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> | 2<sup>-1</sup> | 2<sup>-2</sup> | 2<sup>-3</sup> | 2<sup>-4</sup> | 2<sup>-5</sup> | 2<sup>-6</sup> | 2<sup>-7</sup> | 2<sup>-8</sup> |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | 
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 
| 8388608 | 4194304 | 2097152 | 1048576 | 524288 | 262144 | 131072 | 65536 | 32768 | 16384 | 8192 | 4096 | 2048 | 1024 | 512 | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | 0.5 | 0.25 | 0.125 | 0.0625 | 0.03125 | 0.015625 | 0.0078125 | 0.00390625 |

The value of x of this fixed point number is calculated as:

x = 2<sup>23</sup> + 2<sup>22</sup> + 2<sup>21</sup> + 2<sup>20</sup> + 2<sup>19</sup> + 2<sup>18</sup> + 2<sup>17</sup> + 2<sup>16</sup> + 2<sup>15</sup> + 2<sup>14</sup> + 2<sup>13</sup> + 2<sup>12</sup> + 2<sup>11</sup> + 2<sup>10</sup> + 2<sup>9</sup> + 2<sup>8</sup> + 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> + 2<sup>-1</sup> + 2<sup>-2</sup> + 2<sup>-3</sup> + 2<sup>-4</sup> + 2<sup>-5</sup> + 2<sup>-6</sup> + 2<sup>-7</sup> + 2<sup>-8</sup>

x = 8388608 + 4194304 + 2097152 + 1048576 + 524288 + 262144 + 131072 + 65536 + 32768 + 16384 + 8192 + 4096 + 2048 + 1024 + 512 + 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 + 0.5 + 0.25 + 0.125 + 0.0625 + 0.03125 + 0.015625 + 0.0078125 + 0.00390625

x = 16777215.99609375

## resouces:

[new vs malloc and free vs delete in c](https://www.geeksforgeeks.org/new-vs-malloc-and-free-vs-delete-in-c/)

[cplusplus.com](https://cplusplus.com/reference/)

[http://www.sunshine2k.de/articles/coding/fp/sunfp.html#:~:text=Fixed%20points%20numbers%20are%20represented,part%20is%20always%20the%20same.](http://www.sunshine2k.de/articles/coding/fp/sunfp.html#:~:text=Fixed%20points%20numbers%20are%20represented,part%20is%20always%20the%20same.)

[https://en.wikipedia.org/wiki/Fixed-point_arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)

[https://witscad.com/course/computer-architecture/chapter/fixed-point-arithmetic-division](https://witscad.com/course/computer-architecture/chapter/fixed-point-arithmetic-division)

[https://stackoverflow.com/questions/5028986/emulated-fixed-point-division-multiplication](https://stackoverflow.com/questions/5028986/emulated-fixed-point-division-multiplication)

[https://stackoverflow.com/questions/46104132/how-can-we-calculate-1-3-by-using-fixed-point-arithmetic](https://stackoverflow.com/questions/46104132/how-can-we-calculate-1-3-by-using-fixed-point-arithmetic)

[https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)

[https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)

[https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)

