Filesystem Exercise
===================

In this exercise we are going to make our own virtual block device
and change its permissions slightly.

1. Make a regular file which will be mapped to our block device:

```bash
$ sudo dd if=/dev/zero of=~/mount_file bs=4k count=10k
```

and lets look at its permissions:

```bash
ls -l ~/mount_file
-rw-r--r--. 1 root root 41943040 Nov 13 22:30 /home/vagrant/mount_file
```

So this is a regular file, the owner is `root`, which has read and write perms.
The group is also `root` (root is a group as well as a user), and the root
group just has read permissions. Everyone else can read, but not write.

Lets change the owner and group to vagrant:

```bash
$ sudo chown vagrant:vagrant ~/mount_file
```

and lets add __group__ write permissions:

```bash
$ chmod g+w ~/mount_file
```

2. We cannot format a regular file with a filesystem, or mount it. We can only do this with __block__ devices. Fortunately we can use the `losetup` tool to make the regular file into a block device. The `/dev/loop` devices can be associated with files in order to mount a regular file like a loop device.

```bash
$ ls -l /dev/loop0
brw-rw----. 1 root disk 7, 0 Nov 13 21:57 /dev/loop0
```

Again, the `b` means that `/dev/loop0` is a __block__ device. It is owned by root
with a group of `disk`, both have read and write permissions, and any user that 
is not root or in the disk group cannot read, write, or execute this file.

Now lets associate the file we made with `/dev/loop0`, format it with a
file system and mount it:

```bash
$ sudo losetup /dev/loop0 ~/vagrant_file
$ sudo mkfs.ext4 /dev/loop0
$ sudo mount -t ext4 /dev/loop0 /mnt
$ mount # lists devices that are mounted
/dev/mapper/VolGroup-lv_root on / type ext4 (rw)
proc on /proc type proc (rw)
sysfs on /sys type sysfs (rw)
devpts on /dev/pts type devpts (rw,gid=5,mode=620)
tmpfs on /dev/shm type tmpfs (rw,rootcontext="system_u:object_r:tmpfs_t:s0")
/dev/sda1 on /boot type ext4 (rw)
none on /proc/sys/fs/binfmt_misc type binfmt_misc (rw)
vagrant on /vagrant type vboxsf (uid=500,gid=500,rw)
/dev/loop0 on /mnt type ext4 (rw)
```

Congratulations, you have made a file, associated it with a loop device,
formatted it with a filesystem, and mounted it!