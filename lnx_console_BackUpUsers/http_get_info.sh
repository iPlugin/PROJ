#!/bin/bash
DATE=$(date)
WEBSITE="https://app.underdefense.com"
INFO=$(curl -o dev/null -s -w "%{http_code} %{time_total}" $WEBSITE)

echo "$DATE $WEBSITE $INFO" >> /home/iplugin/Codes/scripts/http_get_info.log
