# TP - INF224
Author: Carlos Jedwab

Date: 2023-02-19

Copyright (c) 2023

[Link to project's description](https://perso.telecom-paristech.fr/elc/inf224/)

## Important Notes

### Execution
To execute the programs, it is necessary to execute the following command in two terminals:
```make run```
one terminal for each directory `cpp` and `swing`.

### Requests

Requests are in the format:
- `create photo|video|movie|group name filename ...params` (for creating a media or a group)
- `delete media|group name` (for deleting a media or a group)
- `add media_name group_name` (for adding a media to a group)
- `display name` (for displaying a media or a group)
- `play name` (for playing a media)

### Default data

When the server is started, it will already have some data in the database. Specifically, it will have the following data:
- 2 photos of names: **cat** and **lenna**
- 1 video of name: **rain**
- 1 movie of name: **notlionking**

## Questions from Travaux Pratiques C++
### Step 4
#### What do you call this type of method and how should they be declared?
Answer: To declare a virtual method, the base class should include the "virtual" keyword before the return type in the method declaration, and the subclasses should include the "override" keyword before the method definition to indicate that it is intended to override the virtual method.

#### If you have done the above as requested, it will no longer be possible to instance objects from the base class. For what ?
Answer: Once virtual methods have been declared in the base class, it becomes an abstract class, which means that it cannot be instantiated directly. This is because the base class now has one or more pure virtual methods that must be implemented in the subclass to make it concrete. Therefore, any attempt to instantiate the base class directly would result in a compilation error. Instead, only instances of the subclasses (Photo and Video in this case) can be created. This mechanism is known as runtime polymorphism or dynamic binding, and it allows the correct method implementation to be selected at runtime based on the actual type of the object.

### Step 5
#### What is the characteristic object-oriented property that allows this to be done?
Answer: The characteristic object-oriented property that allows this to be done is polymorphism. Polymorphism allows different objects to be treated uniformly through a common interface, which in this case is the virtual method to play the multimedia object.

#### What is specifically necessary to do in the case of C++ ?
Answer: In C++, it is necessary to use pointers or references to the base class when creating the array. This is because when an array of objects is created, it must have a fixed size, which means that it can only contain objects of a single type. However, by using pointers or references to the base class, we can create an array that can hold objects of different types, as long as they are derived from the same base class.

#### What is the type of the elements of the array : should the array contain objects or pointers to these objects? For what ? Compare to Java.
Answer: The type of the elements of the array should be pointers to objects of the base class. This is because when an object is stored in an array, it is sliced if it is of a derived class type and assigned to an element of the array that is of the base class type. This means that the object loses its derived class type information and only the base class part is retained. However, when a pointer to the derived class is stored in an array of pointers to the base class, the pointer retains its type information and can be used to call the appropriate virtual method for the actual type of the object.

In Java, on the other hand, the array can contain objects of different types directly, as Java uses reference types to achieve polymorphism, rather than value types as in C++.

### Step 7
#### Among the previously written classes, which ones should be modified so that there is no memory leak when objects are destroyed? Change the code to avoid it.
Answer: The classes that have instance variables that are pointers should be modified so that there is no memory leak when objects are destroyed. In the given classes, this applies to the Movie class, which has a pointer to chapters array. Therefore, the destructor of the Movie class should be modified to delete the chapters array using the delete[] operator.


#### Object copying can also cause problems when they have instance variables that are pointers. What is the problem and what are the solutions? Implement one.
Answer: When objects with instance variables that are pointers are copied, the pointers are copied but not the memory that they point to. This can result in multiple objects pointing to the same memory, which can lead to memory corruption. To avoid this, the copy constructor and the assignment operator should be modified to allocate new memory for the instance variables that are pointers and copy the values from the original object to the new memory. This is known as deep copying.

### Step 8
#### The group must not destroy the objects when it is destroyed because an object can belong to several groups (we will see this point in the next question). We also recall that the list of objects must in fact be a list of object pointers . For what ? Compare to Java.
Answer: If the group destroys the objects when it is destroyed, then an object that belongs to multiple groups will be destroyed when the first group is destroyed. However, if the objects array contains pointers to the objects, then the objects will not be destroyed, only their pointers will be removed from the array. However, if we were to use smart pointers, then the objects would be destroyed automatically when the last pointer to them is destroyed.

As for Java, the garbage collector will automatically destroy objects that are no longer referenced by any variable, so there is no need to manually destroy objects in Java.

### Step 10
#### The preceding methods make it possible to ensure the consistency of the database because when an object is created, it is added to the appropriate table. On the other hand, this will not be the case if an object is created directly with new (it will not belong to any table). How can we prohibit it, so that only the class used to manipulate objects can create new ones?
Answer: To prohibit direct creation of objects using new outside of the class used to manipulate objects, we can make the constructors of the classes Photo, Video, Movie, and Group private, so that they cannot be called from outside the class. We can then define static factory methods inside the class used to manipulate objects that create and return instances of these classes.

## Questions from Travaux Pratiques Java/Swing 

### Step 1
#### Launch your program, click several times on the first two buttons, resize the window. What do we notice?
Answer: Clicking on the first two buttons causes the text to be appended in the text area. As for resizing the window, the text area is resized to fit the new window size. However, if the text size is larger than the window size, then the text area crops out the text that does not fit in the window.
