## Feature 1 — Project Scaffolding & Version Control
- Repository name: BSDSF23A020-OS-A20
- GitHub URL: https://github.com/Uzair3112/BSDSF23A020-OS-A20.git
- Date created: 21/09/25
- Files and directories created: src/, include/, lib/, bin/, obj/, REPORT.md


## Feature-2: Multi-file compilation (multifile-build branch)

**Q1. Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS). How does it differ from a Makefile rule that links against a library?**

The rule `$(TARGET): $(OBJECTS)` tells make that the final executable depends on all object files. 
When any object changes, the target must be rebuilt. In this case, the linker combines all `.o` 
files into one binary.  
When linking against a library, instead of providing multiple `.o` files directly, the rule specifies 
`-lmylib` (static or dynamic) and the linker pulls symbols from the library.

**Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**

A git tag is a marker pointing to a specific commit, usually for releases.  
- Simple tag = lightweight pointer (just the commit hash).  
- Annotated tag = contains metadata (author, date, message) and is stored as a full Git object.  
Annotated tags are preferred for releases.

**Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**

A GitHub Release makes a specific tagged version easily accessible to users. It bundles source 
code at that commit, plus optional binaries. Attaching binaries like `client` means others can 
download and run the program without compiling from source.

- Feature-3: Static library (static-build branch)
- Feature-4: Dynamic library (dynamic-build branch)
- Feature-5: Man pages & install target (man-pages branch)
