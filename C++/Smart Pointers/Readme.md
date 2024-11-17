# Disadvantages of Pointers :-

![1731860935133](image/Readme/1731860935133.png)

## Uninitialized pointers in C++ :-

![1731860993499](image/Readme/1731860993499.png)

if we have declared a pointer then we should not use that pointer unless we have initialized it.

![1731861028076](image/Readme/1731861028076.png)

This means that we want to store the value ‘25’ wherever the pointer is pointing. But the question here is where the pointer is pointing? In, ‘int *p’ it is not pointing anywhere. Just we have declared. Then what is the address in ‘p’ here?

**Some default garbage addresses may be in ‘p’, some random addresses that may belong to a program or may not belong to a problem.**

So, it is an invalid address as we have not made a pointer to point to some particular location. So first of all, make it point to some location then we can access it.

There are 3 methods of doing it.

#### 1st Method :-

![1731861152632](image/Readme/1731861152632.png)

If we have some variable ‘x’ then, Now the pointer is pointing to this known variable ‘x’ which is already declared.

#### 2nd Method :-

![1731861173284](image/Readme/1731861173284.png)

We can assign some addresses using some hexadecimal codes but that address has to be type casted as an integer pointer. So, can we directly assign some addresses to a pointer? Yes, if we are sure that the address belongs to the program so this type of initialization is also allowed. **This is not commonly used. This is mostly used in systems programming**

#### 3rd Method :-

![1731861189562](image/Readme/1731861189562.png)

We can dynamically allocate some memory and assign that to a pointer. If we don’t write size and write only ‘int’ then it will allocate just one integer so either to an existing variable.

#### Memory Leak :-

This is related to a pointer as well as heap memory. As we have already discussed heap memory, when we are allocating heap memory then when we don’t require that, we should deallocate it. If we don’t deallocate it then we say that memory is leaked from that total set of memory.

![1731861307539](image/Readme/1731861307539.png)

**Here we have a pointer and I have allocated heap memory of some size. Then after some time, we don’t need this memory. So, we simply say ‘p = NULL’, then point P will not be pointing to that memory.We should not do this unless we have explicitly deleted the memory.**

So first of all, say delete ‘p’ then only, make ‘p’ as null.

![1731861325873](image/Readme/1731861325873.png)

**Now here is one more thing that we can write ‘p = 0’ also or write ‘p = nullptr‘.**

In modern C++ it is suggested to use ‘nullptr’. You should avoid using null. So back to this memory leak, the conclusion is you must delete the memory when you are not using it before making a pointer to null. Now let us move to the third problem which is the dangling pointer.


#### Dangling Pointer in C++ :-

So uninitialized pointers mean, the pointer is never initialized, dangling pointer means the pointer was initialized but memory is deallocated. We should avoid these three types of problems while writing programs or developing applications. Actually, these problems are caused due to negligence of beginner programmers. Expert programmers may check all these things thoroughly only before delivering a program or before developing software.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcEFVXcBNJtn9nEO_yae4EjSmKUEr5AIJAMTvGZAWwQATi2p8JhNxfOd0zI_XXbomdzExJn8ntG3AnkSaf4HjkUxoJ2UmjNdFAusxval9cxdvGiIi9uq86vQcZbTY59uJh7MNh9?key=QLDlryDpmeT1SUbAWE3NNLuU)

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdLg4xso5v8C_yN9BayGvi2lFY2z0Fvf7gefOIcU_2Kkz3fYTxPm7IrP6Mylo6OZJM6beHOe-b1GqymP9YKYH3yovnaTLbR6719-un7-6f7Ppf7dxzSsJdjK0JxwqEke-tx-zSMYQ?key=QLDlryDpmeT1SUbAWE3NNLuU)
The improper use of pointers is often at the root of many security problems. When an application behaves in unpredictable ways, it may not seem to be a security issue, at least in terms of unauthorized access.

Pointers can do arithmetic, References can't: Memory access via pointer arithmetic is fundamentally unsafe and for safeguarding, Java has a robust security model and disallows pointer arithmetic for this reason.

#### What are Smart Pointers in C++?

If you are creating anything inside the heap memory then for accessing the heap memory, we need to use pointers. The problem with heap memory is that when you don’t need it then you must deallocate the memory. And mostly the programmer shows laziness in writing the code for the deallocation of objects from heap memory which causes severe problems like memory leaks which will cause the program to crash.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdgMqVCjpCjHsdunCbQBZgpMuDVaQJpfhMR3W6JKbMpJHFynus2PbcaqPwO1IbMojDIGVtpH4OtoeZkCSzyb-0-7uwkGwtELal6HNmWrgQvl7p60lnUJJ_CBRyP9wchEvhkjmvf?key=QLDlryDpmeT1SUbAWE3NNLuU)

###### Using Smart Pointers in C++:

If we declare the smart pointer then they will automatically deallocate the object when the smart pointer is going out of the scope. Let us show you how we can declare smart pointers in C++.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeoY7RvZaipVO3qsLokhc4TTDhirGQdl2CPhCNlrQOrmv-HDLkV2mwyhz3c81tVprIV64Aiul35E9P79SVmbsu7nQJV2nPXZFRlOXEgK_X0pgjNprCsUm25-eHftLW6gElM407pNA?key=QLDlryDpmeT1SUbAWE3NNLuU)

###### Example to Understand unique_ptr in C++ :-

If you are using unique_ptr, if an object is created and a pointer is pointing to that object then only one pointer can point to that object. So, we cannot share this object with another pointer. But we can transfer the control from one pointer to another pointer by removing p1. So unique_ptr means upon an object at a time only one pointer will be pointing.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfVVyxgSu8qTEUinf55fXT6yIKWE1c8jsjkLy1fLNqju0AovRibCB4s6fWb6Q23QKbJbrTJ2i0rhckJAkVlWCJIcBk93EwAXEfPvfBIPzfhnCD1jvDMR2KGtmkXPurW8t5-JLpBLA?key=QLDlryDpmeT1SUbAWE3NNLuU)

Output: 50

#### Shared_ptr :-

Just like how we have used unique_ptr, the same way we have to use shared_ptr. More than one pointer can point to one object. This pointer maintains a Ref_count that is a reference counter. Suppose 3 pointers are pointing on a single object the Ref_count will be 3.

So shared means an object can be used by more than one pointer. If we remove one pointer then Ref_count will be reduced by 1. We can know the value of Ref_count by using the use_count() function.![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcEHmdYz6D4Aq8C2E-s2l5wNBPZyB5k02zm2Z4tnBfDP78O2MZQSN5TIMMNmyG-woaugDtI7rVW3UqNJOqND0ipCcLhCoauuhiHEuNWfQAJ2s1chZkNgvY7Kuog5ICxKNRbov0m?key=QLDlryDpmeT1SUbAWE3NNLuU)

#### Weak_ptr :-

It is also the same as shared_ptr. Here also more than one pointer can point to a single object. But it will not maintain Ref_count. So that’s why it is known as weak_ptr. So, the pointer will not have a strong hold on the object. The reason is if the pointers are holding the object and requesting other objects, they may form a deadlock between the pointers. So, to avoid deadlock, weak_ptr is useful. So, it doesn’t have Ref_count so it is more like unique_ptr but it allows the pointer to share an object, so it is more like shared_ptr. It is in between unique and shared which is not strict. It doesn’t bother how many pointers are pointing at an object.

InClass Initializer and Delegation of Constructors :-

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdojlIzTmCvOb99sZuXhKkokZ-wgN80tTpNFgE8imrIytJgS8R247uM-pB7JVhbrJisnXVzmRIRVv6AunyhhtO8dJll7HK_4aKBlO-DZ-NTk7io0G1ZltGqC6RbTlSCbl87R83GlA?key=QLDlryDpmeT1SUbAWE3NNLuU)
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfnhtSmsvLDl6e9hS0Ev_PThwqh3vPJJ2PAA59-qL1hAMHkapqbhx6_p7kumnTPUiBpKDkZD-13aK4Acz3D9yPz2T8B9WlAT2SXKECLDZbRyFE2h2jcK7HNLVscUkYDNGAPzKWytg?key=QLDlryDpmeT1SUbAWE3NNLuU)
