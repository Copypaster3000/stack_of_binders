This program allows the user to create, edit, and view a digital stack of binders. Todo list can be made and stored within each binder. This program was designed to become familiar with stack and circular linked lists data structures. The binders are in a stack and the todo list are circular linked list. 

Effeciency Review:

In this program, I used a combination of a stack data structure and a circular linked list (CLL) as the data structures. The stack was made up of nodes which each had a dynamically allocated array of binders. I decided to make the arrays three binders long so the stack was fast to test. Each binder, which was an instance of the binder class held a pointer to a queue. A queue is a class that manages a CLL. The queue has functions to add, remove, display, and peek nodes in the CLL. Each queue represented a CLL of to-do items. The queue class had a pointer to the CLL. The queue class is an abstract data type (ADT) and the pointer is private. Anyone using the queue class is unaware of the CLL that it uses to store data. There is also a stack class which is what manages the stack in a similar way. It is also an ADT and anyone using the stack class does not actually come into contact with the stack. 

The stack worked well for this program. I assume that the user really only needs to access the binder on the top of the pile. Just like on your desk you most likely are working with what is on top. If we assume the user only needs to interact with the top binder until they are finished with it and remove it from the pile then the stack is perfect for this. In this case, no traversal is needed to access the binder the user may want to access. If they’re ready to work with the next binder, it’s just one away and becomes the first in the stack after removing the old one. It also works well because there’s no need to know the total number of binders that may need to be stored ahead of time. Because the stack uses nodes, a new node can be added each time more memory space is needed. A stack works well when the data that is being stored will likely need to be accessed in a last-in-first-out manner. Data was also stored in a CLL. This worked especially well with the data that was stored in there needing to be first in first out. The CLL reduced the number of pointers needed to do this without traversal. The memory was also dynamic, a new node can always be added. 

If the user decided they wanted to access a binder that wasn’t on top of the stack then this data structure would not work in the way that it is set up. It wouldn’t just be inefficient, the user would not be able to access binders to interact with, without deleting the binders before it. All that can be done with binders in this stack that aren’t on top is to display them. 
