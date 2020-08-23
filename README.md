# libosdev
Open-source components for building and bootstrapping operating systems.

**This repository is a work in progress. (AKA there's almost nothing done, haha)**

## Rationale
Who doesn't dream of making an operating system. Lots of programmers have
imagined one day creating the next Windows or Linux.

In reality, even if you know the Intel x86 manual like the back of your hand,
it's still a royal pain in the butt to scaffold a project. A modern build system?
Forget it. UEFI? Good luck finding tooling. Debugging? Keep dreaming.

The goal of `libosdev` is to provide core infrastructure and libraries, so that
people can get off the ground more easily.

## Components
All components are in C, unless stated otherwise.

Most important:
* `libosdev_bootstrap` - Multiboot2 bootstrap code. Sets up the environment
for either a 32-bit or 64-bit kernel.

Other components:
* `libosdev_debug` - Functionality for printing output to serial ports/the
screen, as well as some functionality for interacting with debuggers.
* `libosdev_elf` - Headers and functionality for reading and writing ELF
binaries.
* `libosdev_memory` - Code for x86/x86\_64 page tables, as well as page
allocation. Works well when combined with https://github.com/blanham/liballoc.
* `libosdev_x86` - General x86/x86\_64 functionality, such as GDT, IDT, and
interrupts.

# Future Components
Ideally, I would like to eventually make:
* `libosdev_test` - Infrastructure for unit testing operating systems.
