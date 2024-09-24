# Hi everyone, I received a task #2 from Underdefense

### PART 1
Create a cronjob that checks status of https://app.underdefense.com
Cronjob runs every minute and connects to the website
Cronjob appends the results to a "status.log" file in a format
"<current-time> <website-name> <status-code> <request-duration-milisecs>

### PART 2
Create a cronjob that backups home folders of all users into /opt/backups/<user>
Cronjob runs every day and creates TAR archive of home folder for every user
Cronjob saves the archives in names like "/opt/backups/myuser/2024-07-30.tar.gz"