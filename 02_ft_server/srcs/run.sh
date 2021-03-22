sed -i "s/autoindex on/autoindex $NGINX_AUTOINDEX/g" /etc/nginx/sites-available/nginx;

./nginx start
./mysql start
./php7.3-fpm start

tail -f /var/log/nginx/access.log /var/log/nginx/error.log