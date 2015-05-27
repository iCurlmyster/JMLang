# JMLang
Personal project to try and make a simple interpreted language.


--
Just an attempt at trying to make a simple interpreted language written in c++, using c++11 features.

As of now the language can store variables for strings, numbers (which are stored as doubles), arrays of these types, and simple lambda functions (which can be set to variables).
It also can use built in functions like `print:` and `println:` and can call methods from variables and literals.
There is also support for single line comments.

### Check out Examples directory to see how the language is used.

The string objects support:
`concat:`
`append:`
`length:`
`writeToFile:`
`class:`
`val:`

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
`val:`

The Array objects support:
`append:`
`push:`
`at:`
`length:`
`writeToFile:`
`class:`
`val:`

The Lambda objects support:
`call:`
