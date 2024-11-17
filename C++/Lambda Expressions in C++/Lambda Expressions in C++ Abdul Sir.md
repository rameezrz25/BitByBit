# Lambda Expressions in C++

## Overview
Lambda Expressions is useful for defining unnamed functions in C++. So, we can define the function wherever we like. They are more likely inline functions but they will have the features of the function. Let us see the syntax for a lambda expression or unnamed function in C++.
## Syntax

The basic syntax of a lambda expression is as follows:

![alt text](image.png)

### Explanation:
- **Capture Clause (`[]`)**: Specifies how variables from the surrounding scope are captured (either by reference or by value).
- **Parameters (`(parameters)`)**: Defines the input parameters for the lambda function.
- **Return Type (`-> return_type`)**: Specifies the return type of the lambda function (optional, often inferred by the compiler).
- **Body (`{ body }`)**: The body of the lambda function, where the logic is defined.

In many cases, the compiler can infer the return type, so you don't always need to specify it explicitly.

