#!/bin/bash

# Read secrets
DB_PASS=$(cat /run/secrets/db_password)
WP_CREDS=$(cat /run/secrets/credentials)
WP_ADMIN_PASS=$(echo "$WP_CREDS" | cut -d':' -f2)
WP_USER_PASS=$(echo "$WP_CREDS" | cut -d':' -f2)

# Wait for MariaDB
echo "Waiting for MariaDB..."
while ! mysqladmin ping -h mariadb -u "$MYSQL_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "MariaDB is ready!"

cd /var/www/html

# Download WordPress if not exists
if [ ! -f wp-config.php ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root
    
    # Create wp-config.php
    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASS" \
        --dbhost=mariadb:3306 \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASS" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root
    
    # Create regular user
    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --role=author \
        --user_pass="$WP_USER_PASS" \
        --allow-root
    
    # Set permissions
    chown -R www-data:www-data /var/www/html
    
    echo "WordPress installed successfully!"
fi

echo "Starting PHP-FPM..."
exec php-fpm8.2 -F
