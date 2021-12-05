# 42_printf


TODO :

- Add .* flag (easy)
	- Except %.*x with 5 and 2 as arguments prints "00002" which makes 0 sense (should be 05)
	- So wtf. Check mac behavior?
	- Man says "given in the next argument" but apparently it's the preceding argument. OK. COOL.
	- Not easy then.
	- Do I need to add this since it's not in the mac manual...
- Add .m$ flag (how?!?)
	- Do I need to add this since it's not in the mac manual...
- Also add * and m$ to width and 0?! (this is getting cumbersome)
- Test everything extensively
- Reproduce printf exactly?!?!? ...


Difficulties :

Linux and mac have a different printf...
Ex: %6#x is invalid on linux, valid on mac
Some of the points below were tested on linux... no telling if they're still a problem on mac.

Some incompatible arguments cause a warning while others are outright rejected
Ex: % +i causes a warning, %8-9i is rejected
What seems to be the case is that incompatible arguments are only accepted with a warning as long as they aren't followed by any value (except for the last flag)
Ex: %-8#09x is rejected, %-#09x causes a warning, %0#-6x causes a warning

Arguments can repeat but only if the last one is followed by the optional value.
Ex: %---9s is fine %--9-s is not
This is probably responsible for the last point, too. - and - are considered as much incompatible as - and width or ' ' and +, and incompatible flags can only have an optional value for the very last flag (even if the last one is the one being ignored).

. and 0 cause really hard to reproduce behavior. If both are present, 0 is counted as if it was a regular 0 digit before other digits
Ex: %08.9i causes 08 to be interpreted as width having "08" or "8" of value
The is one easy way of handling this case the way I'm doing things. When I'm done handling the flags and I'm looking at incompatibilities, I can simply add zero's value to width's value.

Points 2 and 3 are very very hard to implement, with the way I've done things. Also, it doesn't make much sense (from a "make a useful program" point of view, not from a "reproduce an official function exactly for the fun of it" pov). The decision on what to print with a warning and what to handle like a big boy is simply arbitrary.
Point 4 is easy to implement, and makes some kind of sense (but also not much).
