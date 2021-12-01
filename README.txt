# 42_printf

TODO :
- Printf is done but bonuses require a rethink and rewrite
- New version is being written
	- Remaining is :
	- function to interpret flags
	- functions to convert arguments, taking flags into account
	- function to parse main string
	- function to coordinate flag-interpreting and argument-converting functions

New printf :
- It will use a list of bytes instead of an array of bytes
- This allows for an easier time handling padding flags
- It also makes counting the total characters of printf easier
- To optimize and allow an easier time with flags, the list won't be re-parsed at every new character written into it, rather, the current list element will be sent (the before-last element).
- It will use a structure to handle flags

Flags :

- Flags are put between the % and the conversion identifier (ex: %#04i)

- '#' puts a '0x' before hexadecimal conversions (in our case, only usable with x and X)
	- the x is uppercase for the X conversion (0X7FF)

- '0(num)' pads the number with 0's to fill a certain amount of characters
	- cares about the '-' in negative numbers
	- ex: %04i with 54 becomes 0054
	- if num is omitted it is considered to be 0
	- when used with the # flag, adds the 0 after '0x' and considers the '0x' in the padding

- ' ' pad with a space if the number is positive

- '+' pad with a + if the number is positive
	- overrides ' '

- '-(num)' and '(num)' pads with blanks to left align or right align the value (respectively)
	- overrides '0'
	- if (num) is omitted it is considered to be 0

- '.(num)' ?
	- for %s, limits how many characters are written
	- for numbers, pads them with 0's, ignoring the -


Problem with errors :

How the fuck do I handle them. As in, the real printf causes compilation warnings when flags and conversions are incorrectly used. Example : "% " by itself is an error. "%k" is also an error. Etc, etc, etc.
When encountering a %, printf sometimes is flexible on how it handles erroneous arguments, sometimes not. Bar testing every possible error scenario, I can't reproduce the behavior exactly, and I think it makes more sense to handle all errors the same way and do it how I want to.
So how do I want to do it?
When parsing, if an error is encountered, I think it's better to give up trying to interpret the input, and simply go back to printing byte per byte.


Examples :

Incorrect conversions
ft_printf("%k%,%.%i", 5)						"%k%,%.%5"
ft_printf("% .6and yes")						"% .6 and yes"

Incorrect flags
ft_printf("%#- .6i", 5)							" 000005"
explanation : # can't be used with i, - can and space can and are compatible with .6 which can too


Meaning :

Incorrect conversions are just printed
Incorrect flag usage (like %.ki) is counted like an incorrect conversion and just printed : in this case, k is an incorrect conversion.
Incompatible flags (like %#i) are ignored and the correct conversion is printed, taking correct flags into account.
Not enough arguments means we'll possibly segfault or at least read memory that isn't available to us.
Too many arguments are just ignored.
Flags incompatible with one another just use a priority system, which will be laid out in the header file above the flag structure.


Weird cases :

The - argument trumps the 0 argument but only if 0 has no flag value. If it does, then the whole flag string is ignored.
Ex: "05-4i" is displayed as "05-4i", while "0-4i" displays whatever int is passed
The same happens with width and . : "%5-4i" isn't correctly interpreted
