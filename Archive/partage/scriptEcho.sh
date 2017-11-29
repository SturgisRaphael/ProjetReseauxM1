#!/bin/bash

ip route del default
ip route add default via 10.0.2.2
apt-get install inetutils-inetd
update-inetd --add "echo stream tcp nowait nobody internal"
service inetutils-inetd start
service inetutils-inetd status
service inetutils-inetd restart
