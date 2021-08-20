## Notes

There is a memory mapped struct located at a splot in ram that wont resolve in ghidra,it has a length of 0x328 and is the `ebc` struct. Ghidra will need a manually made memory location for this.

Will need patch to support relocations https://github.com/NationalSecurityAgency/ghidra/issues/3352
I've been working with my guess patch there for now.. so far its.. sane
