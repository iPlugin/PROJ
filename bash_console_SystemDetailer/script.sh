#!/bin/bash

# PART 1
# Write Bash script that nust be run as root and prints your system information into a cmdline-specified text file:
# - Free and available resources, process and users list
# - Datetime setting, hostname, network configurations
# - (Optional) Hypervisor name, date of last login, public IP

echo "Welcome to SystemDetailer 1.0.0 ($(cat /etc/lsb-release | tail -n 1 | cut -c 22-40))

    * Author:	iPlugin
    * Github:	https://github.com/iPlugin
    * Linkedin:	www.linkedin.com/in/iplugin
"
echo "System information as of $(date)

    System load:$(cat /proc/loadavg | awk '{print " "$1}')		Processes:	$(ps -e | wc -l)
    Usage of /:	$(df -h / | awk 'NR==2{print " "$5" of "$2}')	Users logged:	$(uptime | cut -c 22-27)
    Mem usage:	$(free -m | awk 'NR==2{printf " %.2f%%\n", $3*100/$2 }')		IPv4 address:	$(ifconfig | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | awk -F. '{printf "%03d.%03d.%03d.%03d\n", $1,$2,$3,$4}'
)
    Swap usage:	$(free -m | awk 'NR==3{printf " %.2f%%\n", $3*100/$2 }')
"

# PART 2
# Write a Bash script that simulates gambling machine, where you try to guess the number from 100 to 999:
# - Script checks your input if you are older than 18 years, denies access if not
# - Script prints your balance upon access starting from 100 gambling coins
# - Script reduces 10 coins from your balance for every your guess
# - Script adds 30 coins if last digit of your guess is correct
# - Script adds 500 coins if your guess is fully correct
# - Script saves your balance if you restart the program
# - Be creative and add some phrases or custom logic

echo -e "Game 'Guess the number' from 100 to 999\n"

read -p "How old are you: " AGE
if [ $AGE -gt 17 ]; then
	GAME_POINT=100
	WIN_NUMBERS=$((100 + RANDOM % 900))
	LAST_WIN_NUMBER=${WIN_NUMBERS: -1}

	while true; do
		echo -e "\n| Player: $(whoami) | Balance: $GAME_POINT point"
		read -p "| Let's guess the numbers: " NUMBERS
		LAST_NUMBER="${NUMBERS: -1}"

		if [ $WIN_NUMBERS -eq $NUMBERS ]; then
			echo "| You are a winner! +500 point :)"
			GAME_POINT=$((GAME_POINT + 490))
		elif [ $LAST_WIN_NUMBER -eq $LAST_NUMBER ]; then
			echo "| You guessed the last number! +30 point"
			GAME_POINT=$((GAME_POINT + 20))
		else
			echo "| No matches, try again! -10 point :("
			GAME_POINT=$((GAME_POINT - 10))
		fi

		read -p "| Try again? [smt/exit]: " ANSWER
		if [ "$ANSWER" == "exit" ]; then
			echo "| Goodbye, see you!"
			break
		fi
	done
else
	echo "| Goodbye, see you!"
fi

