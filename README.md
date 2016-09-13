# cross-platform-game-ai-by-example #
Mat Buckland's "Programming Game AI by Example" is a great resource. Time to make it cross platform.

## Goal ##
The goal is to add a Platform Interface to the code in the Common section of Game AI by Example.

## UML diagrams ##
**work in progress**
UML were created using graphviz's Dot language.

Platform Interface

![alt text][PIL]
[PIL]: https://github.com/Plotnus/gaibe/blob/master/docs/PIL.png "Platform Interface"

Thread UML

![alt text][Threads]
[Threads]: https://github.com/Plotnus/gaibe/blob/master/docs/Threads.png "Threads"

## Useful Links ##
Some links that have helped guide this endeavor

[Conventions and patterns for multi-platform development] (https://www.chromium.org/developers/design-documents/conventions-and-patterns-for-multi-platform-development)

[Cross-Platform Design Strategies](http://www.drdobbs.com/cpp/cross-platform-design-strategies/184410963)

[Insomniac Coding Standards](http://www.drdobbs.com/cpp/cross-platform-design-strategies/184410963)

[Programming Game AI by Example: UML: Appendix C] (http://www.ai-junkie.com/appendices/uml_class_diagrams.html)

[Should it be a Member Function?](http://www.drdobbs.com/cpp/how-non-member-functions-improve-encapsu/184401197) I often find myself wondering, "Should it be a member function?" This link provides an algorithm to help you decide. It comes from Item 23: Prefer non-member, non-friend functions to member functions. The reasoning is to increase encapsulation. "Object-oriented principles dictate that data should be as encapsulated as possible." And he further clarifies, "The more something is encapsulated, the fewer things can see it." But also, the *less* things can see of it. As we know, a non-member, non-friend function can see less of an object then a member, friend function, and I guess thats the whole point. As a bonus, sticking to Myer's algorithm will help provide consistency, and threby manage complexity. 

