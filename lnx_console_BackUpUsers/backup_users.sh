#!/bin/bash

# Директорія для зберігання резервних копій
BACKUP_DIR="/opt/backups"

# Отримуємо список усіх користувачів, у яких є домашня тека
for user in $(ls /home); do
  # Створюємо директорію для користувача, якщо вона не існує
  mkdir -p $BACKUP_DIR/$user

  # Створюємо ім'я файлу з поточною датою
  DATE=$(date +%Y-%m-%d)
  BACKUP_FILE="$BACKUP_DIR/$user/$DATE.tar.gz"

  # Архівуємо домашню теку користувача
  tar -czf $BACKUP_FILE -C /home $user
done

