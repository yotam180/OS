# OS

A short-term project for me to learn some new stuff about operating systems.

## Features

1. Bootloader - boots in BIOS mode. No use of GRUB/any other bootloader template.
1. Kernel loading in 1 stage - first sector of disk loads the kernel from the disk.
1. Passing to 32 bit mode
1. Enabling software & hardware interrupts
1. Enabling the timer (that currently doesn't do anything)
1. Reading input from keyboard
1. Writing text to the screen

## Next things I want to implement

1. Finish keyboard input (add keyboard modifiers, special characters [delete, function keys, etc.])
1. Physical memory allocator
1. Disk driver
1. File system
1. Paging in 32bit
1. Separate the boot to 2 stages (second stage performs jump to 32 bit, then loads the kernel, so the kernel size is not limited)
1. Moving to ring 3
1. Processes
1. Threads & scheduling
1. Normal GUI (with windows and all)

And then we'll see what's more...

**TODO: Document and add some screenshots for swag**