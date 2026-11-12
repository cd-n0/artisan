# Artisan Game Engine (Successor to Tri Engine (Hopefully))

TODO:
Some platforms don't support some features such as windowing or virtual memory.
- Maybe define function names as macros on those platforms to put a compile time error like SDL does?

Core lib 3 rev.
- [x] **Types**
- [x] **Type limits**
- [x] **Common macros (assert, static assert, threadlocal, defer, API(import/export) etc.)**
    - [x] **Platform and compiler detection**
- [ ] **Logging (Use libc first, switch after OS IO abstractions(I got carried away :D))**
- [ ] **Formatting** (snprintf)
- [ ] **Tests**
- [ ] Memory
    - [ ] CString
    - [ ] Allocators (Do not start until OS memory abstractions, otherwise logic will change for platforms with virtual memory)
        - [ ] Arena
        - [ ] Stack
        - [ ] Pool
        - [ ] Buddy
        - [ ] Slot
- [ ] Containers
    - [ ] String
        - [ ] String builder (don't use darray, use list of pointers method like JAI)
    - [ ] Trees (Binary, AVL, RB)
    - [ ] Linked list
    - [ ] Dynamic array
    - [ ] Hashmap
- [ ] Platform
    - [ ] Syscall (Stuff like exit, alloc, free etc. in stdlib, not a raw syscall caller)
    - [ ] Memory
    - [ ] Threading
        - [ ] Thread pools
    - [ ] Processes
        - [ ] IPC
    - [ ] Clock/Timer
    - [ ] Networking
    - [ ] IO
    - [ ] Windowing
    - [ ] BIG MAYBE Coroutines (Probably no)
- [ ] Math
    - [ ] Random
    - [ ] Trigonometry
    - [ ] Linear Algebra
- [ ] Build
    - [ ] Some type of metaprogramming
    - [ ] CMake support (I use it for espressif IDF sorry ;{)
- [ ] WASM
    - [ ] JS shim

UI (CHECK NOTES ON THE NOTEBOOK):
- [ ] Layout engine
    - [ ] Flexbox?
- [ ] Renderer backends

Audio:
- [ ]

Engine:
- [ ] Renderer
    - [ ] Frontend
        - [ ] TODO: plan frontend and backend API
    - [ ] Backend
        - [ ] GLES3
        - [ ] Software
        - [ ] GL33
        - [ ] GL46
        - [ ] Vulkan
- [ ] WASM
    - [ ] JS shim
