#!/bin/bash

# Free and available resources, process and users list
# Datetime setting, hostname, network configurations
# (Optional) Hypervisor name, date of last login, public IP

echo "Welcome to SystemDetailer 1.0.0 ($(cat /etc/lsb-release | tail -n 1 | cut -c 22-39))"
echo "- Free&available"
free -h

# echo "- Process"
# ps aux | head -n 1; ps aux | tail -n 5
