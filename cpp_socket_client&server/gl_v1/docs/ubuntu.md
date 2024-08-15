# Ubuntu (max line 50)

ОС	- це програмне забезпечення (ПЗ),
	яке керує: апаратними ресурсами компютера,
	управління файлама та даними, процесами,
	інтерфесом користувача і безпекою.

UNIX -> GNU/Linux -> Debian -> Ubuntu

UNIX - це багатозадачна, багатокористувацька ОС,
	розроблена в 1969 році в Bell Labs.
	Вона забезпечує стабільність, безпеку
	і має широкий спектр апаратного забезпечення.

GNU	- це набір програмного забезпечення,
	розроблене Столлманом у 1983 році,
	яке містить інструменти, утиліти, програми
	для створення ОС.
Linux - це ядро операційної системи,
	розроблене Лінусом у 1991 році,
	воно основане на базі ядра UNIX
GNU/Linux - це сімейство вільно розпоширених ОС,
	основаних на базі ядра UNIX, маючи лінцензію
	GPL (General Public License).

Debian	- це дистрибутив GNU/Linux,
	основана на базі ядра Linux,
	він був створеним в 1993 році.

Ubuntu	- це дистрибутив GNU/Linux,
	основана на базі ядра Debian,
	він був створеним в 2004 році.


_______________
# BASE COMMANDS

pwd
	- print working directory

ls
	- list dirs & files

ls <path>
	- list dirs & files in <path>

ls -r
	- list dirs & files reverse

ls -l
	- long info list dirs&files

ls -A
	- list dirs and files and hide files

cd /
	- change to the root directory

cd ~/
	- change to the home directory

cd ..
	- moves up one level

cd <path>
	- moves down one level to the <path>

clear
	- clear terminal

sudo su
	- switch to superuser

exit
	- exit from superuser

su iplugin
	- switch user to iplugin

sudo !!
	- execute last command with sudo

_______________
# FILE COMMANDS

touch file.txt
	- create new file file.txt

nano
	- create new txt editor

nano file.txt
	- edit file file.txt

open file.txt
	- open file file.txt

cat file.txt
	- write file in console

mkdir folder
	- create new dir folder

cp file.txt folder
	- copy file.txt in folder

mv file.txt folder
	- move file.txt in folder

rm file.txt
	- remove file file.txt

rm *	
	- remove all files

rm *.txt
	- remove all files with format txt

rm file.*
	- remove all files with name file

rm -rf folder
	- remove folder

rm -rf *
	- remove all dirs




sudo chown root:iplugin file.txt
	- change owner in file owner:group

sudo chown -R root:iplugin dir
	- change owner in dir owner:group

sudo chmod 765 file.txt
	- change permission for file

sudo chmod -R 755 dir
	- change permission for dir

sudo chat +i file.txt
	- file.txt becomes invariabilit
sudo chat -i file.txt
	- file.txt becomes variable

lsattr sudo
	- list invariabilit

sudo apt-get install vim
	- install vim

vim / :qa
	- start vim / exit vim

sudo apt-get remove vim
	- remove vim

apt-cache policy vim
	- find app in PC

apt-cache search telegram
	- find app in remote repo

sudo apt-get upgrade
	- upgrade applications

find . -type f -name "*.txt"
	- find files with format .txt

find . -type f -name "file.txt"
	- find file file.txt

find . -type f -name "fil*.txt"
	- find files startwith fil.. .txt

find . -type f -iname "file.txt"
	- find files not imрortant register

find . -type f -perm 0664
	- find files with permission 664

find . -type f -size -10k
	- find files size <10 kilobate

find . -type f -perm 0664 -iname "*.txt" -size -10M
	- combinate perm, iname and size

find . -type f -not -iname "*.txt"
	- find all files except -name "*.txt"

grep "print" file.py
	- find word in file file.py

grep -n "Andriy" file.txt
	- print with line number

grep -i "Andriy" file.txt file.TXT
	- find words not imрortant register

find -type f -iname "*.txt" -exec grep "Andriy" {} +
	- combinate find and grep

sort file.txt
	- print sorted words in file.txt

sort -n file.txt
	- print sorted number in file.txt

sort -r file.txt
	- print sorted words reverse

sort file.txt > sorted.txt
	- save sorted file.txt > sorted.txt

$ sudo groupadd developers
	- create group developers

$ sudo groupdel developers
	- delete group developers

$ sudo usermod -aG developers iplugin
	- add iplugin to developers

$ groups iplugin
	- check iplugin`s groups

$ sudo gpasswd -d iplugin developers
	- delete iplugin from developers

$ sudo groupmod -n devops developers
	- rename group

$ getent group devops
	- list members group

$ sudo usermod -g devops iplugin
	- default group for iplugin


top
	- диспетчер задач
free -h
	- free memory
ps
	- list process
ps -aux
	- all user executes process
ps -aux | grep ps
	- all user executes process + filter

__________________
# ARCHIVE COMMANDS

	[ Linux -> Linux ]
$ tar czf zip.xz dir
	- compression in zip.xz

$ tar xzf zip.xz
	- expansion in dir

$ tar czf zip.gz dir
	- compression in zip.gz

$ tar xzf zip.gz
	- expansion in dir

$ tar czf zip.bz2 dir
	- compression in zip.bz2

$ tar xzf zip.bz2
	- expansion in dir

	[ Linux -> Windows ]
$ zip -r zip.zip dir
	- compression in zip.zip

$ upzip zip.zip
	- expansion folder.zip

________________________
# GET RESOURCES COMMANDS

$wget https://picture/images.svg
	- Save image
$sudo dpkg -i ... .deb
	- install application deb

_____________________
# NETWORKING COMMANDS

$ ping www.google.com
	- Check reachability of a host
	
$ ping -c 10 www.google.com
	- Only 10 times

$ host www.google.com
	- Info IPv4, IPv6

$ netstat
	- Open connections

$ netstat | grep unix
	- Open connections + filter

$ ifconfig
	- Info network in PC

$ route
	- Info about our route	

$ ssh
	- Connection to remote server

$ sudo ufw allow 22
	- Make open 22 port

$ w
	- List users are connect to terminal

_________________
# BASH SCRIPT .sh

> Script №1 $bash bash.sh
#!/bin/bash
showDirs=`ls -l`
message="Show dirs: $0"
echo "$message:
$showDirs"

> Script №2 $bash bash.sh 5 5
#!bin/bash
arg1=$1
arg2=$2
res=$((a+b))
echo "Result: $res"

> Script №3 $bash bash.sh
#!bin/bash
read -p "Enter text: " text
echo "$text"

> Script №4 $bash bash.sh
#!bin/bash
read -p "Enter number: " num
if [ "$num" -gt 10 ]; then
	echo "Number is bigger then 10"
elif [ "$num" -lt 10 ]; then
	echo "Number is smaller then 10"
else
	echo "Number is bigger then 10"
fi

> Script №5 $bash bash.sh
#!bin/bash
for (( i=1; i<=5; i++ )); do
	echo "El: $i"
done
for i in {1..5}; do
	echo "El: $i"
done

> Script №6 $bash bash.sh
#!bin/bash
i=1
while [ $i -ne 6 ]; do
	echo "El: $i"
	i=$(($i+1))
done

> Script №7 $bash bash.sh 10 2
#!bin/bash
divide() {
	echo "Get params: $1 $2"
	if [ "$2" -ne 0 ]; then
		res=$(($1/$2))
		echo "Result: $res"
	else
		echo "Result: error"
	fi
}
divide $1 $2



/boot	- загрузчик і заголовки для OC
/dev	- файли драйверів і пристоїв
/opt	- додаткове програме запезчення
/srv	- файли системних сервісів
/tmp	- зберігання тимчасових файлів
/usr	- встановлені користувачем додатки
	/local	- доступно всім користувачам
/var	- змінних файлів (черга друку і тд)
