`sume` A simple Android `sudo`
==============================

To compile this code, the android ndk must be installed and in the current
`PATH`.

For example:

    export PATH=$PATH:/home/ben/android-ndk-r16
    ndk-build

Compile the example program `id`
--------------------------------

This example just prints the current `euid`, `uid`, `egid` and `gid`:

    cd ~
    android-ndk-r16b/build/tools/make_standalone_toolchain.py --arch arm --api 26 --stl=libc++ --install-dir=armtoolchain
    cd sume
    ~/armtoolchain/bin/arm-linux-androideabi-gcc -o id id.c

I am sure there was an easier way without having to copy an entire toolchain 
into a new directory, anyway, that works fine.

Set the Sticky Bit
------------------

To set the sticky bit on the executable:

    chmod u+x sume

Above for user, this is for group:

    chmod g+x sume

Execute it
----------

The application may now be copied to the target device, with either adb or
manipulating the filesystems.

Setting Extended Attributes
---------------------------

These utilities do not always work on my machine but I have had success when 
used with Alpine Linux or a stock Gentoo genkernel-based build.

    gcc -o setxattr setxattr.c
    gcc -o listxattr listxattr.c

When adding files to an andorid `system.img` file the selinux attributes must 
be set, these little utilities make it easier than using the selinux ones.

References
----------

* [How do you compile a C console progam with Android NDK](https://stackoverflow.com/questions/37976396/how-do-you-compile-a-c-console-program-to-run-as-an-android-process)
* [AOSP for Native Toolchain](https://developer.android.com/ndk/guides/standalone_toolchain)
* []

