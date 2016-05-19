About files
-------

filelist.txt contains names of all the source files to be examined. Each in one line.

patternlist.txt contains names of all the pattern files. Each in one line.


Performance
-------

I performed 3 tests as below:

*Test 1*

KMP = 0.096702 seconds

RK = 0.327389 seconds

*Test 2*

KMP = 0.099581 seconds

RK = 0.328065 seconds

*Test 3*

KMP = 0.102452 seconds

RK = 0.325437 seconds

Average complexities of KMP and RK are especially _O(nm)_ and _O(n+m)_, where _n_ stands for total length of the strings and _m_ stands for the total length of the patterns. However, in the tests above, KMP had a significant advantage. There might be two reasons:

1. I restriced hash value to be less than 2^16 so that I can do multiplication without worring about type converting, which may lead to high false positive rate and need to perform a linear test for each pattern.

2. When calculating hash values, large amount of dividing operations are needed, which is more time-consuming than addition, substraction or multiplication.

