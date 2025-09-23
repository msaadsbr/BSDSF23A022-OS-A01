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

### Feature-3 — Static Library Build

**What changed in Makefile (Part2 vs Part3)?**  
- Part2 compiled all source files directly into object files and linked them to create the executable.  
- Part3 splits build into two phases: (1) compile utility source files into object files and archive them into a static library `lib/libmyutils.a` using `ar`, and (2) compile `main.c` and link it against that static library using `-Llib -lmyutils`.  
- Variables added: `LIB_DIR`, `LIBNAME`, and separate targets `lib` and `client_static`. Rules added: object->archive (`ar rcs`) and archive indexing (`ranlib`). The top-level Makefile delegates to `lib/` and `src/` using recursive `make`.

**What is the purpose of `ar` and `ranlib`?**  
- `ar` creates (archives) static library files (`.a`) by combining object files (.o) into a single archive.  
- `ranlib` creates an index to the archive (symbol table) so linkers can quickly locate symbols inside the `.a`. On many systems `ar rcs` already builds the index; calling `ranlib` ensures compatibility.

**When you run `nm` on `client_static`, are symbols like `mystrlen` present? What does that tell you?**  
- Yes — `nm` on the statically linked executable typically shows the function symbols because the object code from the static library has been copied into the executable. This indicates static linking bundles the required object code into the final binary at link time (unlike dynamic linking which resolves references at runtime).



### Feature-4 — Dynamic Library Build

**Q1. What is Position-Independent Code (-fPIC) and why is it required?**  
Position-Independent Code means generated machine code can be loaded at any memory address without modification.  
Shared libraries (.so) may be mapped at different addresses by different processes, so they must be built with `-fPIC` to allow relocation by the dynamic loader.

**Q2. Explain the difference in file size between static and dynamic clients. Why?**  
- `client_static` is larger because all utility function object code is copied directly into the binary.  
- `client_dynamic` is smaller because it only stores references to functions in `libmyutils.so`. The actual code stays in the shared library, loaded at runtime.

**Q3. What is the LD_LIBRARY_PATH environment variable? Why necessary?**  
`LD_LIBRARY_PATH` tells the dynamic loader where to search for `.so` files at runtime.  
By default, loader only looks in system directories (`/lib`, `/usr/lib`). Since our `libmyutils.so` is in a custom `./lib` directory, we must export `LD_LIBRARY_PATH` to include it.  
This demonstrates the OS dynamic loader’s role: resolving and mapping required shared libraries before execution starts.

- Feature-5: Man pages & install target (man-pages branch)

