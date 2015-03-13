# JMLang
Personal project to try and make an interpreted language.


--
Just an attempt at trying to make a simple interpreted language written in c++.

As of now the language can store variables for strings, numbers (which are stored as doubles), and arrays of these types.
It also can use built in functions like `print:` and `println:` and can call methods from variables and literals.
the parameters to the object's methods are dynamic, so you can add as many arguments as you would like,
or as few. There is also support for single line comments.

The string objects support:
`concat:`
`append:`
`length:`
`writeToFile:`
`class:`

The number objects support:
`add:`
`sub:`
`div:`
`mul:`
`+:`
`-:`
`/:`
`*:`
`class:`

The Array objects support:
`append:`
`push:`
`at:`
`length:`
`writeToFile:`
`class:`
