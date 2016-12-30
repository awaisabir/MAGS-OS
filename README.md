# MAGS-OS

MAGS-OS is an augemnted version of the basekernel created by Prof. Douglas Thain of the University of Notre Damme, put together by 4 group members - Muhammad Awais Qureshi (myself) & 4 other team members.

The results obtained were: the implementation of a keyboard driver,
which takes the SCAN codes directly from the key-presses. This driver
then translates the numeric SCAN-codes to the corresponding ASCII
character. For example, the ‘R’ key is interpreted to the numerical
SCAN-code of 19, which is then translated to the ‘r’ character. The
generic solutions that one thinks of after encountering the problems
discussed in Section 1.2 would simply be to call a scanf() function in C to
process keyboard input, however it is not that simple to address since the
basekernel is its own environment. This means that all the libraries and
header files cannot be included without defining them yourself. As a
result, the only solution that can be finalized is the creation of an original
keyboard driver.
The issue of no existing console commands was also addressed by giving
the user a predefined set of usable instructions to communicate with the
kernel. To add on, after the successful implementation of the keyboard,
once the text reached the vertical end of the screen, the console would
refresh, which posed the loss of information previously typed. Hence, a
possible implementation of a scroll option was attempted as well. These
changes together with the original Basekernel, is collectively known as
MAGS-OS.

## How to start the MAGS-OS

Before you proceed to ``` make ``` , make sure you type this in your console:
```
sudo apt-get install qemu-system-i386
sudo apt-get install virtualbox
```

After, type this:

```
cd src
make
```

This will create all the associated obj files, and also produce a disk image, which we decided to mount on VirtualBox, however you can run the OS directly through qemu by:

```
qemu-system-i386 -fda basekernel.img
```

You can find all the relevant back-end structure expained fully in detail from Prof. Doughlas Thain's project @ https://github.com/dthain/basekernel , and also what we were able to create in the report attached to the project.

Thank you,
Muhammad Awais Qureshi.
