# 42_printf

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
	- cares about the '-' in negative numbers
- '+' pad with a + if the number is positive
	- overrides ' '
- '-(num)' and '(num)' pads with blanks to left align or right align the value (respectively)
	- overrides '0'
	- if (num) is omitted it is considered to be 0
- '.(num)' ?
	- for %s, limits how many characters are written
	- for numbers, pads them with 0's, ignoring the -
