# Step 1 : From image
FROM debian:buster
LABEL maintainer="gunwoo kim <gunkim@student.42seoul.kr>"

# Step 2 : Set argument
#  Path
ARG SSL_PATH=/etc/ssl
ARG NGINX_PATH=/etc/nginx
ARG INIT_PATH=/etc/init.d
ARG HTML_PATH=/var/www/html
#  Configure mysql related wordpress
ARG WORDPRESS_DATABASE=wordpress
ARG WORDPRESS_DATABASE_USER=gunkim
ARG WORDPRESS_DATABASE_PASS=password
#  Configure wordpress
ARG WORDPRESS_URL=localhost/wordpress
ARG WORDPRESS_SITE_TITLE=Born2Code
ARG WORDPRESS_ADMIN_NAME=gunkim
ARG WORDPRESS_ADMIN_EMAIL=papawolf@kakao.com
ARG WORDPRESS_ADMIN_PASSWORD=password
#  Env variable
ENV NGINX_AUTOINDEX=on

# Step 3 : Install necessary
RUN apt-get update && apt-get -y install \
	nginx \
	openssl \
	default-mysql-server \
	php-fpm \
	php-mysql \
	wget \
	vim; \
	rm -rf /var/lib/apt/lists/*;

# Step 4 : Download necessary
WORKDIR $HTML_PATH 
RUN wget -O wordpress.tar.gz https://wordpress.org/wordpress-5.7.tar.gz; \
	wget -O phpmyadmin.tar.gz https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz;

# Step 5 : Configure SSL
WORKDIR $SSL_PATH
RUN openssl genrsa -out private/ft_server.key 2048; \
	openssl req -x509 -new -key private/ft_server.key -out certs/ft_server.crt \
	-subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=Innovation Academy/OU=42Seoul/CN=localhost/emailAddress=papawolf@kakao.com"; \
	chown -R www-data:www-data .; \
	find . -type d | xargs chmod 700; \
	find . -type f | xargs chmod 600;

# Step 6 : Configure Nginx
WORKDIR $NGINX_PATH
COPY srcs/nginx ./sites-available
RUN unlink sites-enabled/default; \
	ln -s $NGINX_PATH/sites-available/nginx sites-enabled/;

# Step 7 : Configure MySQL
RUN $INIT_PATH/mysql start; \
	mysql -e "CREATE DATABASE IF NOT EXISTS $WORDPRESS_DATABASE;"; \
	mysql -e "CREATE USER IF NOT EXISTS '$WORDPRESS_DATABASE_USER'@'localhost' IDENTIFIED BY '$WORDPRESS_DATABASE_PASS';"; \
	mysql -e "GRANT ALL ON $WORDPRESS_DATABASE.* TO '$WORDPRESS_DATABASE_USER'@'localhost'"; \
	mysql -e "FLUSH PRIVILEGES;"; \
	$INIT_PATH/mysql stop;

# Step 8 : Configure wordpress
WORKDIR $HTML_PATH
RUN	mkdir wordpress; \
	tar xvzf wordpress.tar.gz --directory ./wordpress --strip 1; \
	rm wordpress.tar.gz; \
	cp wordpress/wp-config-sample.php wordpress/wp-config.php; \
	sed -i "s/database_name_here/$WORDPRESS_DATABASE/g" wordpress/wp-config.php; \
	sed -i "s/username_here/$WORDPRESS_DATABASE_USER/g" wordpress/wp-config.php; \
	sed -i "s/password_here/$WORDPRESS_DATABASE_PASS/g" wordpress/wp-config.php; \
	wget -q https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -P /tmp/; \
	chmod +x /tmp/wp-cli.phar; \
	mv /tmp/wp-cli.phar /usr/local/bin/wp; \
	$INIT_PATH/mysql start; \
	wp core install --url=${WORDPRESS_URL} --title=${WORDPRESS_SITE_TITLE} --admin_name=${WORDPRESS_ADMIN_NAME} --admin_email=${WORDPRESS_ADMIN_EMAIL} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --allow-root --path='/var/www/html/wordpress' --quiet; \
	wp theme install retrogeek --activate --allow-root --path=/var/www/html/wordpress --quiet; \
	wp theme delete twentysixteen --allow-root --path=/var/www/html/wordpress --quiet; \
	wp theme delete twentynineteen --allow-root --path=/var/www/html/wordpress --quiet; \
	wp theme delete twentytwenty --allow-root --path=/var/www/html/wordpress --quiet; \
	wp search-replace 'Just another WordPress site' 'Welcome to my first server' --allow-root --path=/var/www/html/wordpress --quiet; \
	wp search-replace 'Hello world!' "Don't Panic" --allow-root --path=/var/www/html/wordpress --quiet; \
	wp search-replace 'Welcome to WordPress. This is your first post. Edit or delete it, then start writing!' "Fasten your seat belt now! We are leaving soon!" --allow-root --path=/var/www/html/wordpress --quiet; \
	$INIT_PATH/mysql stop; \
	chown -R www-data:www-data wordpress;

# Step 9 : Configure phpMyAdmin
WORKDIR $HTML_PATH
RUN mkdir phpmyadmin; \
	tar xvzf phpmyadmin.tar.gz --directory ./phpmyadmin --strip 1; \
	rm phpmyadmin.tar.gz; \
	cp phpmyadmin/config.sample.inc.php phpmyadmin/config.inc.php; \
	randomBlowfishSecret=$(openssl rand -base64 32); \
	sed -i "s|\['blowfish_secret'\] = ''|\['blowfish_secret'\] = '$randomBlowfishSecret'|g" phpmyadmin/config.inc.php; \
	chown -R www-data:www-data phpmyadmin;

# Step 10 : Expose port
EXPOSE 80 443

# Step 11 : Run container
WORKDIR $INIT_PATH
COPY /srcs/run.sh .
CMD bash run.sh