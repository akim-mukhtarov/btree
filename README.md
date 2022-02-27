## About

In C, making generic data structures is quite tricky, as it does not have
powerful metaprogramming features. Although it is not a problem per se,
as apps written on C is rather quite concrete.
<br>
Any way, there is a few workarounds:
- Using macros with arguments to define structure with provided types
- Using union to store any possible type:
standart ones as char, int, etc. and custom types as void*.
<br>
Depending on chosen workaround, data structure will be either homogeneus
or heterogeneus.  
Homogeneus collection means that there is only one type that a given
instance (whether it was implemented as generic or not) can "store".
Heterogeneus data structures can store items of any type.
<br>
I'll implement both.
