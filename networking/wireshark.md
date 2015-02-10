# Wireshark Exercise

## Installing

First we must install wireshark:

```bash
$ sudo yum install wireshark bind-utils
```

We also install `bind-utils` because it will be used later
to generate traffic for us to see in wireshark.

## Exercise

The goal of this exercise is to use wireshark to see a response
to a dns query being returned to our machine. If you don't know
what a dns query is, it is the thing that turns human-readable
machine names into machine-addressable addresses. For example,
it turns `osuosl.org` into:

```
140.211.15.183
```

In otherwords, our machine will talk to a remote machine and ask it
how to talk to `osuosl.org`, to which the remote machine will respond
with `140.211.15.183`, which our machine knows how to talk to.

By default, wireshark will capture an awful lot of traffic, and we
just want to filter out DNS packets. The information we can use to
do this is the fact that DNS traffic is on port 53 and is over UDP
(instead of TCP). If this doesn't make sense, don't worry, it isn't
super important.

The specific command we want to run is called `tshark`. Run the following:

```bash
$ sudo tshark -i eth0 -R dns port 53
```

This will initially give output like the following:

```
Running as user "root" and group "root". This could be dangerous.
Capturing on eth0
```

Leave it running. In another terminal, login to your machine again.
In this terminal, run the following:

```bash
$ sudo dig +short osuosl.org
140.211.15.183
```

In your other terminal window, where you left `tshark` running, you
will see something like the following:

```
 70.291043 192.168.68.7 -> 192.168.68.4 DNS 70 Standard query 0x9153  A osuosl.org
 70.292222 192.168.68.4 -> 192.168.68.7 DNS 86 Standard query response 0x9153  A 140.211.15.183
 ```

The first line is the dns query you sent to the remote server, and the
second line is the answer that you received.

Congratulations! You just used wireshark to inspect traffic at a very low
level!
