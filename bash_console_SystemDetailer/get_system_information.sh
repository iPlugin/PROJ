#!/bin/bash

# PART 1

if [ $UID != 0 ]; then
	echo "| Enter with root permission"
	exit 1
fi

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

