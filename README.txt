UNI: lm3524
Name: Laura Marin
LAB 9


Part 1:
-------

(a)

BASIC4TRACE: (0x7f69ac0)->MyString(const char *)    [1] 13,constructor,x
BASIC4TRACE: (0x7f69ad0)->MyString(const char *)    [2] 14,constructor,y
BASIC4TRACE: (0x7f69b00)->MyString(const MyString&) [3] 16,copy constructor,a
BASIC4TRACE: (0x7f69af0)->MyString(const MyString&) [4] 16,copy constructor,b
BASIC4TRACE: (0x7f69a70)->MyString(const char *)    [5] 7,constructor,t
BASIC4TRACE: op+(const MyString&, const MyString&)  [6] entering operator+
BASIC4TRACE: (0x7f69a20)->MyString()                [7] 8,default constructor,temp
BASIC4TRACE: (0x7f69a80)->MyString(const MyString&) [8] 8,copy constructor,u1 from return temp
BASIC4TRACE: (0x7f69a20)->~MyString()               [9] 8,destructor,temp
BASIC4TRACE: op+(const MyString&, const MyString&)  [10] entering operator+
BASIC4TRACE: (0x7f69a20)->MyString()                [11] 8,default constructor,temp
BASIC4TRACE: (0x7f69a90)->MyString(const MyString&) [12] 8,copy constructor,u2 from return temp
BASIC4TRACE: (0x7f69a20)->~MyString()               [13] 8,destructor,temp
BASIC4TRACE: (0x7f69b10)->MyString(const MyString&) [14] 8,copy constructor,u3 from return a + t + b (u2)
BASIC4TRACE: (0x7f69a90)->~MyString()               [15] 9,destructor,u2
BASIC4TRACE: (0x7f69a80)->~MyString()               [16] 9,destructor,u1
BASIC4TRACE: (0x7f69a70)->~MyString()               [17] 9,destructor,t
BASIC4TRACE: (0x7f69ae0)->MyString(const MyString&) [18] 16,copy constructor,z
BASIC4TRACE: (0x7f69b10)->~MyString()               [19] 16,destructor,u3
BASIC4TRACE: (0x7f69af0)->~MyString()               [20] 16,destructor,b
BASIC4TRACE: (0x7f69b00)->~MyString()               [21] 16,destructor,a
one and two                                         [22] cout << z << endl;
BASIC4TRACE: (0x7f69ae0)->~MyString()               [23] 19,destructor,z
BASIC4TRACE: (0x7f69ad0)->~MyString()               [24] 19,destructor,y
BASIC4TRACE: (0x7f69ac0)->~MyString()               [25] 19,destructor,x


(b)

new output:

BASIC4TRACE: (0x7ffd31436fa0)->MyString(const char *)    [1] 13,constructor,x
BASIC4TRACE: (0x7ffd31436f90)->MyString(const char *)    [2] 14,constructor,y
BASIC4TRACE: (0x7ffd31436f30)->MyString(const char *)    [5] 7,constructor,t
BASIC4TRACE: op+(const MyString&, const MyString&)       [6] entering operator+
BASIC4TRACE: (0x7ffd31436ee0)->MyString()                [7] 8,default constructor,temp
BASIC4TRACE: (0x7ffd31436f50)->MyString(const MyString&) [8] 8,copy constructor,u1 from return temp
BASIC4TRACE: (0x7ffd31436ee0)->~MyString()               [9] 8,destructor,temp
BASIC4TRACE: op+(const MyString&, const MyString&)       [10] entering operator+
BASIC4TRACE: (0x7ffd31436ee0)->MyString()                [11] 8,default constructor,temp
BASIC4TRACE: (0x7ffd31436f40)->MyString(const MyString&) [12] 8,copy constructor,u2 from return temp
BASIC4TRACE: (0x7ffd31436ee0)->~MyString()               [13] 8,destructor,temp
BASIC4TRACE: (0x7ffd31436fb0)->MyString(const MyString&) [14] 8,copy constructor,u3 from return a + t + b (u2)
BASIC4TRACE: (0x7ffd31436f40)->~MyString()               [15] 9,destructor,u2
BASIC4TRACE: (0x7ffd31436f50)->~MyString()               [16] 9,destructor,u1
BASIC4TRACE: (0x7ffd31436f30)->~MyString()               [17] 9,destructor,t
BASIC4TRACE: (0x7ffd31436f80)->MyString(const MyString&) [18] 16,copy constructor,z
BASIC4TRACE: (0x7ffd31436fb0)->~MyString()               [19] 16,destructor,u3
one and two                                              [22] cout << z << endl;
BASIC4TRACE: (0x7ffd31436f80)->~MyString()               [23] 19,destructor,z
BASIC4TRACE: (0x7ffd31436f90)->~MyString()               [24] 19,destructor,y
BASIC4TRACE: (0x7ffd31436fa0)->~MyString()               [25] 19,destructor,x

Lines [3], [4], [20], [21] are not present in the new output. The reason is that we are now passing the 
parameter to the add function by reference instead of by value, so the copy constructor is not executed 
when the program enters the function, and the destructor is not called to destroy those temporary objects.


(c)

new output:

BASIC4TRACE: (0x7fff52dd7e50)->MyString(const char *)    [1] 13,constructor,x
BASIC4TRACE: (0x7fff52dd7e40)->MyString(const char *)    [2] 14,constructor,y
BASIC4TRACE: (0x7fff52dd7df0)->MyString(const char *)    [5] 7,constructor,t
BASIC4TRACE: op+(const MyString&, const MyString&)       [6] entering operator+
BASIC4TRACE: (0x7fff52dd7e00)->MyString()                [7] 8,default constructor,temp
BASIC4TRACE: op+(const MyString&, const MyString&)       [10] entering operator+
BASIC4TRACE: (0x7fff52dd7e30)->MyString()                [11] 8,default constructor,z (temp)
BASIC4TRACE: (0x7fff52dd7e00)->~MyString()               [13] 8,destructor,temp
BASIC4TRACE: (0x7fff52dd7df0)->~MyString()               [17] 9,destructor,t
one and two                                              [22] cout << z << endl;
BASIC4TRACE: (0x7fff52dd7e30)->~MyString()               [23] 19,destructor,z (temp)
BASIC4TRACE: (0x7fff52dd7e40)->~MyString()               [24] 19,destructor,y
BASIC4TRACE: (0x7fff52dd7e50)->~MyString()               [25] 19,destructor,x

From the g++ man page: "-fno-elide-constructors The C ++ standard allows an implementation to omit creating 
a temporary which is only used to initialize another object of the same type. Specifying this option disables 
that optimization, and forces G++ to call the copy constructor in all cases."

We can see that temporary objects (u1, u2 and u3) were not created (and obviously not destroyed). Furthermore, 
there was a slight change in the destruction of temp (which was not destroyed until later in the process) and 
the construction of z that was executed at a different location to optimize the process and avoid a copy.



Part 2:
-------

(a) and (b)

Work exactly as they should.
No Valgrind detected memory leaks.




