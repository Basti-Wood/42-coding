#!/bin/bash

# Read secrets
DB_ROOT_PASS=$(cat /run/secrets/db_root_password)
DB_PASS=$(cat /run/secrets/db_password)

# Check if database already initialized
if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    echo "Initializing database..."
    
    # Start MariaDB temporarily
    mysqld_safe &
    sleep 5
    
    # Create database and user
    mysql -u root <<EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
FLUSH PRIVILEGES;
EOF
    
    # Stop temporary instance
    mysqladmin -u root -p"$DB_ROOT_PASS" shutdown
    sleep 2
    
    echo "Database initialized successfully."
fi

echo "Starting MariaDB..."
exec mysqld_safe
