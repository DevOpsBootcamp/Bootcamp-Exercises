Booting
=======

In this exercise we will be exploring the initrd that is installed
on your VM and is used to boot (don't worry, we won't break the
VM!)

To begin, lets make a copy of your initrd:

```bash
$ ls /boot/init*
/boot/initramfs-2.6.32-504.el6.x86_64.img
$ cp /boot/initramfs-2.6.32-504.el6.x84_64.img ~/initramfs.img.gz
```

The `cp` here makes a copy (and renames the copy to `initramfs.img.gz`).
Make a new directory in your homedir to work in:

```bash
$ cd 
$ mkdir ramdisk
$ cd ramdisk
```

Now we need to decompress the initramfs -- they are compressed with gzip
by default on CentOS.

```bash
$ sudo gunzip ~/initramfs.img.gz # this creates ~/initramfs.img
```

The image is stored in an archive format known as `cpio`. We can extract it
using the utility of the same name:

```bash
$ sudo cat ~/initramfs.img | cpio -i --make-directories
93206 blocks
```

Now, you will notice that `cpio` unarchived everything in the current
directory. This corresponds to the root of the ramdisk, you will see
some familiar directories like `bin` and `sbin`:

```bash
$ ls -l
total 112
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 bin
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 cmdline
drwxr-xr-x. 3 vagrant vagrant 4096 Nov 18 00:13 dev
-rw-r--r--. 1 vagrant vagrant   19 Nov 18 00:13 dracut-004-356.el6
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 emergency
drwxr-xr-x. 7 vagrant vagrant 4096 Nov 18 00:13 etc
-rwxr-xr-x. 1 vagrant vagrant 9028 Nov 18 00:13 init
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 initqueue
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 initqueue-finished
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 initqueue-settled
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 initqueue-timeout
drwxr-xr-x. 7 vagrant vagrant 4096 Nov 18 00:13 lib
drwxr-xr-x. 3 vagrant vagrant 4096 Nov 18 00:13 lib64
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 mount
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 netroot
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 pre-mount
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 pre-pivot
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 pre-trigger
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 pre-udev
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 proc
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 sbin
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 sys
drwxr-xr-x. 2 vagrant vagrant 4096 Nov 18 00:13 sysroot
drwxrwxrwt. 2 vagrant vagrant 4096 Nov 18 00:13 tmp
drwxr-xr-x. 7 vagrant vagrant 4096 Nov 18 00:13 usr
drwxr-xr-x. 4 vagrant vagrant 4096 Nov 18 00:13 var
```

We don't have time to go over everything in the ramdisk, but the
most important part is the `init` script:

```bash
$ less init
```

Another important script this calls is `mount/99mount-root.sh`:

```bash
$ less mount/99mount-root.sh
```

That is all for this exercise!