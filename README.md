# Reverse engineering notes on the ebc_dev in the PineNote

## Whats "done"

The folder `done` has what I believe to be done code in it.
Noting that I do _not_ have hardware on hand at this point in time to test on.
I have not _yet_ done testing if it compiles with the kernel, but 10000000% open to anyone doing this before I get to it.

These all are loosely cleaned up / named versions of the C output of ghidra, there is a _lot_ of cleanup that can be done on these once they are a little tested.

## Whats "In progress"

### Notes

There is a memory mapped struct located at a splot in ram that wont resolve in ghidra,it has a length of 0x328 and is the `ebc` struct. Ghidra will need a manually made memory location for this.

Will need patch to support relocations https://github.com/NationalSecurityAgency/ghidra/issues/3352
I've been working with my guess patch there for now.. so far its.. sane
