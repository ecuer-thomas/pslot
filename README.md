Repositery:

- *delivery* : Document for delivery
- *pslot*    : Sources of ```pslot```
- *linux*    : Modified files from linux kernel source code


How to deploy and build pslot
=============================

You need to get a unmodified Linux kernel source tree (http://kernel.org) and merge it into the ```linux``` directory. After, you can just build the kernel normally. (It will be better to make a symlink with ```/usr/src/linux```, according to your distro).

By default the ```pslot``` feature is not build. You must enable it.

```Files Systems -> Pseudo Files Systems```

Go to ```pslot``` directory, and build it.

Enjoy !

